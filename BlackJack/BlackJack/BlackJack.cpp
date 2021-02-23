#include"BlackJack.h"
#include"TextureManager.h"

BlackJack::BlackJack(SDL_Renderer* rend)
{
	renderer = rend;

	background = TextureManager::LoadImage("assets/table.png", rend);
	image = TextureManager::LoadImage("assets/Cards/Pika9.png", rend);
}

BlackJack::~BlackJack()
{
	SDL_DestroyTexture(background);
	SDL_DestroyTexture(image);

	std::cout << "Black_Jack Cleaned" << std::endl;
}

void BlackJack::Update()
{

}

void BlackJack::Render()
{

	SDL_RenderCopy(renderer, background, NULL, NULL);
	
	TextureManager::ApplySurface(50, 50, image, renderer);

}
