#include"BlackJack.h"
#include"TextureManager.h"

BlackJack::BlackJack(SDL_Renderer* rend)
{
	renderer = rend;

	background = TextureManager::LoadImage("assets/table.png", rend);
	card = new Card("assets/Cards/Pika9.png", rend);
}

BlackJack::~BlackJack()
{
	delete card;
	SDL_DestroyTexture(background);
	
	std::cout << "Black_Jack Cleaned" << std::endl;
}

void BlackJack::Update()
{
	card->Update();
}

void BlackJack::Render()
{

	SDL_RenderCopy(renderer, background, NULL, NULL);
	
	card->Render();


}
