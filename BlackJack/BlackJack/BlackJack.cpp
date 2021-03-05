#include"BlackJack.h"
#include"TextManager.h"


BlackJack::BlackJack(int playerNum):numberOfPlayer(playerNum)
{


	numberOfText = 6;

	startGame(); // initalize deck and players
	makeUI(); // initalize UI
	
	indexStyleCard = 2;
	indexStyleBack = 2;

	optionOn = false;
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
	texts.clear();
	
	std::cout << "Black_Jack Cleaned" << std::endl;

	
	Mix_FreeMusic(music);
	

}


void BlackJack::reset()
{
	delete deck;
	players.clear();

	startGame();

	takeOption(indexStyleCard,false);
	takeOption(indexStyleBack, true);

	state = BlackJack::Start;
	indexDiler = players.size() - 1;
	indexPlayer = 0;

	players[indexPlayer]->isMyTurn = true;
}

void BlackJack::render()
{

	renderUIBack();

	deck->render();

	for (int i=players.size()-1; i>=0;i--)
	{
		players[i]->render();
	}

	renderUIFront();

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
	case BlackJack::Option:
	{

	}
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

				if (!optionOn) {
					if (Game::enterMouseInRect(hit.rect))takeHit();
					if (Game::enterMouseInRect(stand.rect))takeStand();
					if (Game::enterMouseInRect(option.rect))optionOn = true;
					if (Game::enterMouseInRect(sound.rect))musicOn = !musicOn;
				}
				else
				{
					if (!Game::enterMouseInRect(optionUI.rect))optionOn = false;


					if (Game::enterMouseInRect(texts[3]->rect)) {
						takeOption(1,false);
						indexStyleBack = 1;
					}
					if (Game::enterMouseInRect(texts[5]->rect)) {
						takeOption(2, false);
						indexStyleBack = 2;
					}
					if (Game::enterMouseInRect(texts[2]->rect)) {
						takeOption(1, true);
						indexStyleCard = 1;//index - number of style
					}
					if (Game::enterMouseInRect(texts[4]->rect)) {
						takeOption(2, true);
						indexStyleCard = 2;
					}
				}

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

void BlackJack::renderUIBack()
{
	SDL_RenderCopy(Game::renderer, background, NULL, NULL);


	TextureManager::Draw(hit.sprite,hit.rect);
	TextureManager::Draw(stand.sprite, stand.rect);
	TextureManager::Draw(option.sprite, option.rect);
	TextureManager::Draw(sound.sprite, sound.src, sound.rect);

}

void BlackJack::renderUIFront()
{
	if (optionOn)
	{
		
		TextureManager::Draw(optionUI.sprite,optionUI.rect);
		drawTextInOption();
	}
}

void BlackJack::takeOption(int index_, bool isCard_)
{
	std::string namePath = "assets/Cards";
	namePath += std::to_string(index_) + '/';


	if (isCard_)
	{
		deck->swapTextureCard(namePath);

		for (auto player : players)
			player->swapTextureCard(namePath);
	}
	else {

		deck->swapTextureBack(namePath);

		for (auto player : players)
			player->swapTextureBack(namePath);
	}
	optionOn = false;
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


void BlackJack::startGame()
{
	std::shared_ptr<Player> player;
	std::shared_ptr<UI> ui;

	for (int i = 0; i < numberOfText; i++)
	{
		ui = std::make_shared<UI>();
		texts.push_back(ui);
	}

	for (int i = 0; i < numberOfPlayer; i++) {
		player = std::make_shared<Player>(50 + i * 200, 450, i + 1);
		players.push_back(player);
	}

	player = std::make_shared<Diler>(300, 200, indexDiler + 1);
	players.push_back(player);


	deck = new Deck();
}

void BlackJack::makeUI()
{
	background = TextureManager::LoadImage("assets/UI/table.bmp");
	stand.sprite = TextureManager::LoadImage("assets/UI/stand.bmp");
	hit.sprite = TextureManager::LoadImage("assets/UI/hit.bmp");
	option.sprite = TextureManager::LoadImage("assets/UI/option.bmp");
	optionUI.sprite = TextureManager::LoadImage("assets/UI/optionUI.bmp");
	sound.sprite = TextureManager::LoadImage("assets/UI/sound.bmp");

	music = Mix_LoadMUS("assets/Music/main2.mp3");
	musicOn = false;
	Mix_PlayMusic(music, -1);

	SDL_Rect rect;

	SDL_QueryTexture(hit.sprite, NULL, NULL, &rect.w, &rect.h);
	SDL_QueryTexture(sound.sprite, NULL, NULL, &sound.rect.w, &sound.rect.h);
	option.rect.x = 10; option.rect.y = sound.rect.y = 30; sound.rect.w /= 2;
	option.rect.h = sound.src.h = sound.rect.h;
	option.rect.w = sound.src.w = sound.rect.w;
	sound.rect.x = option.rect.x + option.rect.w + 10;
	sound.src.x = sound.src.y = 0;

	hit.rect.w = stand.rect.w = rect.w;
	hit.rect.h = stand.rect.h = rect.h;

	hit.rect.x = deck->getPos().x - (hit.rect.w) / 4 * 3;
	stand.rect.y = hit.rect.y = deck->getPos().y + 120;
	stand.rect.x += hit.rect.x + hit.rect.w + 10;


	SDL_QueryTexture(optionUI.sprite,NULL,NULL,&optionUI.rect.w, &optionUI.rect.h);
	optionUI.rect.x = optionUI.rect.y = 100;

	texts[0]->sprite = TextManager::LoadText("Card", 40, { 255, 255, 255 });
	texts[1]->sprite = TextManager::LoadText("Back", 40, { 255, 255, 255 });
	texts[2]->sprite = TextManager::LoadText("Style n1", 28, { 255, 212, 0 });
	texts[3]->sprite = TextManager::LoadText("Style n1", 28, { 255, 212, 0 });
	texts[4]->sprite = TextManager::LoadText("Style n2", 28, { 255, 230, 110 });
	texts[5]->sprite = TextManager::LoadText("Style n2", 28, { 255, 230, 110 });


	for (int i = 0; i < texts.size(); i++)
	{
		SDL_QueryTexture(texts[i]->sprite, NULL, NULL, &texts[i]->rect.w, &texts[i]->rect.h);
	}

	texts[0]->rect.x = optionUI.rect.x + 30;
	texts[0]->rect.y = optionUI.rect.y + 30;

	texts[1]->rect.x = texts[0]->rect.x + texts[0]->rect.w + 30;
	texts[1]->rect.y = optionUI.rect.y + 30;

	texts[2]->rect.x = texts[0]->rect.x;
	texts[2]->rect.y = texts[0]->rect.y + 70;

	texts[3]->rect.x = texts[1]->rect.x;
	texts[3]->rect.y = texts[1]->rect.y + 70;

	texts[4]->rect.x = texts[2]->rect.x;
	texts[4]->rect.y = texts[2]->rect.y + 35;

	texts[5]->rect.x = texts[3]->rect.x;
	texts[5]->rect.y = texts[3]->rect.y + 35;
}

void BlackJack::drawTextInOption()
{
	for (int i = 0; i < texts.size(); i++)
	{
		TextManager::Draw(texts[i]->sprite, texts[i]->rect);
	}
}