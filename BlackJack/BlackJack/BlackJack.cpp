#include"BlackJack.h"
#include"TextureManager.h"


BlackJack::BlackJack()
{
	background = TextureManager::LoadImage("assets/table.png");
	
	deck = new Deck();
	player = new Player(50,450);

	click = true;
}

BlackJack::~BlackJack()
{
	delete deck;
	delete player;
	SDL_DestroyTexture(background);
	
	std::cout << "Black_Jack Cleaned" << std::endl;
}


void BlackJack::reset()
{
	delete deck;
	delete player;

	deck = new Deck();
	player = new Player(50,450);
}

void BlackJack::update()
{
	deck->update();
	player->update();

	if (Game::event.type == SDL_KEYDOWN)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_SPACE:
			if (click) {
				
				if (!deck->isEmpty() && player->playerState() == Player::None)
				{
					player->addCardtoHand(deck->moveTopCard());
				}

				player->update();
				click = false;
			}
		case SDLK_r:
			if (click) {
				
				reset();
				click = false;
			}
		default:
			break;
		}
	}
	if (Game::event.type == SDL_KEYUP)
	{
		switch (Game::event.key.keysym.sym)
		{
		case SDLK_SPACE:
		case SDLK_r:
			click = true;
		default:
			break;
		}
	}
}

void BlackJack::render()
{

	SDL_RenderCopy(Game::renderer, background, NULL, NULL);

	deck->render();
	player->render();

}

