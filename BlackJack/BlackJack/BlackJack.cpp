#include"BlackJack.h"
#include"TextureManager.h"


BlackJack::BlackJack()
{
	background = TextureManager::LoadImage("assets/table.png");
	
	deck = new Deck();

	std::shared_ptr<Player> player;

	for (int i = 0; i < 3; i++) {
		player = std::make_shared<Player>(50 + i * 200, 450);
		players.push_back(player);
	}

	player = std::make_shared<Diler>(100, 100);
	players.push_back(player);


	state = BlackJack::Start;
	indexPlayer = 0;
	indexDiler = players.size() - 1;
	click = true;
}

BlackJack::~BlackJack()
{
	delete deck;
	players.clear();
	SDL_DestroyTexture(background);
	
	std::cout << "Black_Jack Cleaned" << std::endl;
}


void BlackJack::reset()
{
	delete deck;
	players.clear();


	std::shared_ptr<Player> player;

	for (int i = 0; i < 3; i++) {
		player = std::make_shared<Player>(50 + i * 200, 450);
		players.push_back(player);
	}

	player = std::make_shared<Diler>(100, 100);
	players.push_back(player);


	deck = new Deck();

	state = BlackJack::Start;

	indexDiler = players.size() - 1;
	indexPlayer = 0;
}

void BlackJack::render()
{

	SDL_RenderCopy(Game::renderer, background, NULL, NULL);

	deck->render();

	for (int i=players.size()-1; i>=0;i--)
	{
		players[i]->render();
	}
}


void BlackJack::update()
{
	deck->update();

	//std::cout << state << " " << std::endl;

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
			
			if (indexPlayer >= indexDiler) { players[indexDiler]->openCard(); state = BlackJack::End; }
			else state = BlackJack::PlayerInterection;

			if (players[indexPlayer]->state != Player::None)
				indexPlayer++;

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
		WinLose();

		SDL_Delay(2000);
		reset();
	}
		break;
	default:
		break;
	}


}

void BlackJack::playerInteractiv()
{
	switch (Game::event.type)
	{
	case SDL_KEYDOWN:
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (click) {

				if (!deck->isEmpty() && players[indexPlayer]->state == Player::None && indexPlayer != indexDiler)
				{
					players[indexPlayer]->addCardtoHand(deck->moveTopCard());
				}

				//players[indexPlayer]->update();
				click = false;
			}
		case SDLK_r:
			if (click) {

				reset();
				click = false;
			}
		case SDLK_s:
			if (click) {

				do {
					if (indexPlayer < players.size()) {

						indexPlayer++;

					}
				} while (players[indexPlayer]->state == Player::Win);

				std::cout << indexPlayer << std::endl;

				click = false;

			}
		default:
			std::cout << "Now Player #" << indexPlayer + 1 << std::endl;
			break;
		}
	case SDL_KEYUP:
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_SPACE:
		case SDLK_r:
		case SDLK_s:
			state = BlackJack::Animation;
			click = true;
		default:
			break;
		}
	}
	}

	if (indexPlayer == indexDiler)
	{
		while(players[indexPlayer]->getScore()<17)
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
			if(!BurnDiler && players[i]->getScore() < players[indexDiler]->getScore())std::cout << "Player #" << i + 1 << " Losed\n";
			else std::cout << "Player #" << i + 1 << " Won\n";
		}
		else std::cout << "Player #" << i + 1 << " Burned\n";
	}
	if(BurnDiler)std::cout << "Diler Burned\n";
}