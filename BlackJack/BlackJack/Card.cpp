#include"Card.h"
#include"TextureManager.h"
#include<math.h>

Card::Card(std::string namePath, SDL_Renderer* rend,int score_, double x, double y, bool isAce_)
	:xpos(x),ypos(y),score(score_),isAce(isAce_)
{
	isFace = true;
	
	renderer = rend;
	textureCard = TextureManager::LoadImage(namePath, rend);
	textureBack = TextureManager::LoadImage("assets/Cards/Back.png" , rend);
}

Card::~Card() 
{
	SDL_DestroyTexture(textureCard);
	SDL_DestroyTexture(textureBack);

	//std::cout << "Card Deleted" << std::endl;
}


void Card::Update() 
{
	/*xpos = sin(M_PI * SDL_GetTicks() / 1000.0)*100.0 + 250;
	ypos = cos(M_PI * SDL_GetTicks() / 1000.0)*100.0 + 250;*/
	xpos = rand() % 600;
	ypos = rand() % 400;
}


void Card::Render() 
{
	if(isFace)TextureManager::ApplySurface(xpos, ypos, textureCard, renderer);
	else TextureManager::ApplySurface(xpos, ypos, textureBack, renderer);
}