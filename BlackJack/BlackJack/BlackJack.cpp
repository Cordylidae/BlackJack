#include"BlackJack.h"
#include"TextureManager.h"


BlackJack::BlackJack(int playerNum):numberOfPlayer(playerNum)
{

	deck = new Deck();

	

	background = TextureManager::LoadImage("assets/UI/table.bmp");
	stand.sprite = TextureManager::LoadImage("assets/UI/stand.bmp");
	hit.sprite = TextureManager::LoadImage("assets/UI/hit.bmp");
	sound.sprite = TextureManager::LoadImage("assets/UI/sound.bmp");

	music = Mix_LoadMUS("assets/Music/main1.mp3");
	musicOn = false;
	Mix_PlayMusic(music,-1);

	SDL_Rect rect;

	SDL_QueryTexture(hit.sprite, NULL, NULL, &rect.w, &rect.h);
	SDL_QueryTexture(sound.sprite, NULL, NULL,&sound.rect.w, &sound.rect.h);
	sound.rect.x = 650; sound.rect.y = 500; sound.rect.w /= 2;
	sound.src.x = sound.src.y = 0; sound.src.h = sound.rect.h; sound.src.w = sound.rect.w;

	hit.rect.w = stand.rect.w = rect.w;
	hit.rect.h = stand.rect.h = rect.h;

	hit.rect.x = deck->getPos().x - (hit.rect.w) / 4 * 3;
	stand.rect.y = hit.rect.y = deck->getPos().y + 120;
	stand.rect.x += hit.rect.x + hit.rect.w + 10;



	std::shared_ptr<Player> player;

	for (int i = 0; i < numberOfPlayer; i++) {
		player = std::make_shared<Player>(50 + i * 200, 450,i+1);
		players.push_back(player);
	}

	player = std::make_shared<Diler>(100, 100,indexDiler+1);
	players.push_back(player);


	state = BlackJack::Start;
	indexPlayer = 0;
	indexDiler = players.size() - 1;
	players[indexPlayer]->isMyTurn = true;
	click = true;
}

BlackJack::~BlackJack()
{
	delete deck;
	
	players.clear();
	
	std::cout << "Black_Jack Cleaned" << std::endl;

	
	Mix_FreeMusic(music);
	

}


void BlackJack::reset()
{
	delete deck;
	players.clear();


	std::shared_ptr<Player> player;

	for (int i = 0; i < numberOfPlayer; i++) {
		player = std::make_shared<Player>(50 + i * 200, 450,i+1);
		players.push_back(player);
	}

	player = std::make_shared<Diler>(100, 100,indexDiler+1);
	players.push_back(player);


	deck = new Deck();

	state = BlackJack::Start;

	indexDiler = players.size() - 1;
	indexPlayer = 0;
	players[indexPlayer]->isMyTurn = true;
}

void BlackJack::render()
{
	renderUI();

	deck->render();

	for (int i=players.size()-1; i>=0;i--)
	{
		players[i]->render();
	}
}


void BlackJack::update()
{
	deck->update();
	 

	switch (state)
	{
	case BlackJack::Start:
	{
		for (auto p : players)
		{
			if (!deck->isEmpty() && p->state == Player::None)
			{
				p->addCardtoHand(deck->moveTopCard());
				p->addCardtoHand(deck->moveTopCard());
			}
			
		}

		state = BlackJack::Animation;
	}
		break;
	case BlackJack::Animation:
	{
		bool animFinish = true;

		for (auto p : players)
		{
			p->update();
			if (!p->animationFinish())animFinish = false;
		}

		if (animFinish) {
			
			if (indexPlayer >= indexDiler) 
			{
				state = BlackJack::End; WinLose();
			}
			else state = BlackJack::PlayerInterection;

			if (players[indexPlayer]->state != Player::None && indexPlayer<indexDiler)
			{
				players[indexPlayer]->isMyTurn = false;
				players[indexPlayer+1]->isMyTurn = true;
				indexPlayer++;
			}
		}
		
	}
		break;
	case BlackJack::PlayerInterection:
	{
		playerInteractiv();
	}
		break;
	case BlackJack::End:
	{
		SDL_Delay(3000);
		reset();
	}
		break;
	default:
		break;
	}

	if (musicOn) {
		Mix_ResumeMusic(); sound.src.x = 0;
	}
	else {
		Mix_PauseMusic(); sound.src.x = sound.src.w;
	}
}

void BlackJack::playerInteractiv()
{
	switch (Game::event.type)
	{
	case SDL_MOUSEBUTTONDOWN:
		if (Game::event.button.clicks == SDL_BUTTON_LEFT) {
			
			if (click) {

				
				if (Game::enterMouseInRect(hit.rect))takeHit();
				if (Game::enterMouseInRect(stand.rect))takeStand();
				if (Game::enterMouseInRect(sound.rect))musicOn=!musicOn;

				click = false;
			}
		}
		break;
	case SDL_KEYDOWN:
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (click) {

				takeHit();
				click = false;
			}
			break;
		case SDLK_r:
			if (click) {

				reset();
				click = false;
			}
			break;
		case SDLK_s:
			if (click) {

				takeStand();

				click = false;

			}
			break;
		}
		break;
	case SDL_MOUSEBUTTONUP:
		if (Game::event.button.clicks == SDL_BUTTON_LEFT) {
			state = BlackJack::Animation;
			click = true;
		}
	break;
	case SDL_KEYUP:
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_r:
			click = true;
			break;
		case SDLK_SPACE:
		case SDLK_s:
			state = BlackJack::Animation;
			click = true;
		default:
			break;
		}
	}

	break;
	}

	if (indexPlayer == indexDiler)
	{
		players[indexDiler]->openCard();

		while (players[indexPlayer]->getScore() < 17)
			players[indexPlayer]->addCardtoHand(deck->moveTopCard());
		state = BlackJack::Animation;
	}
}

void BlackJack::WinLose()
{
	bool BurnDiler = (players[indexDiler]->state==Player::Burn);
	for (int i = 0; i < players.size() - 1; i++)
	{
		if (players[i]->state != Player::Burn)
		{
			if(!BurnDiler && players[i]->getScore() < players[indexDiler]->getScore())players[i]->state = Player::Lose;
			else players[i]->state = Player::Win;
		}
	}
}

void BlackJack::renderUI()
{
	SDL_RenderCopy(Game::renderer, background, NULL, NULL);


	TextureManager::Draw(hit.sprite,hit.rect);
	TextureManager::Draw(stand.sprite, stand.rect);
	TextureManager::Draw(sound.sprite, sound.src, sound.rect);

}

void BlackJack::takeHit()
{
	if (!deck->isEmpty() && players[indexPlayer]->state == Player::None && indexPlayer != indexDiler)
	{
		players[indexPlayer]->addCardtoHand(deck->moveTopCard());
	}

}

void BlackJack::takeStand()
{
	do {
		if (indexPlayer < players.size() - 1) {

			players[indexPlayer]->isMyTurn = false;
			players[indexPlayer + 1]->isMyTurn = true;
			indexPlayer++;

		}
	} while (players[indexPlayer]->state == Player::Win);
}