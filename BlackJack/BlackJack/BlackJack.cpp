#include"BlackJack.h"
#include"TextureManager.h"

BlackJack::BlackJack(SDL_Renderer* rend)
{
	renderer = rend;

	background = TextureManager::LoadImage("assets/table.png", rend);
	deck = new Deck(rend);
	//card = new Card("assets/Cards/Pika9.png", rend);
}

BlackJack::~BlackJack()
{
	delete deck;
	SDL_DestroyTexture(background);
	
	std::cout << "Black_Jack Cleaned" << std::endl;
}

void BlackJack::update()
{
	//card->Update();
	deck->update();
}

void BlackJack::render()
{

	SDL_RenderCopy(renderer, background, NULL, NULL);
	
	//card->Render();
	deck->render();
}
