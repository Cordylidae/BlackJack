#include"Card.h"
#include"TextureManager.h"
#include<math.h>

Card::Card(std::string namePath, SDL_Renderer* rend) 
{
	isAce = false;
	isFace = true;
	score = 2;
	
	xpos = 250;
	ypos = 250;


	renderer = rend;
	textureCard = TextureManager::LoadImage(namePath, rend);

}

Card::~Card() 
{
	SDL_DestroyTexture(textureCard);
	std::cout << "Card Deleted" << std::endl;
}


void Card::Update() 
{
	//xpos = sin(M_PI * SDL_GetTicks() / 1000.0)*100.0 + 250;
	//ypos = cos(M_PI * SDL_GetTicks() / 1000.0)*100.0 + 250;

}


void Card::Render() 
{
	TextureManager::ApplySurface(xpos, ypos, textureCard, renderer);
}