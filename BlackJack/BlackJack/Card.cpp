#include"Card.h"
#include"TextureManager.h"
#include<math.h>
//
//#include"Components.h"
//
//
//Manager manager;
//


Card::Card(std::string namePath, int score_, double x, double y, bool isAce_)
	:xpos(x),ypos(y),score(score_),isAce(isAce_)
{
	isFace = true;
	
	textureCard = TextureManager::LoadImage(namePath);
	textureBack = TextureManager::LoadImage("assets/Cards/Back.png");
}

Card::~Card() 
{
	SDL_DestroyTexture(textureCard);
	SDL_DestroyTexture(textureBack);
}


void Card::update(double x, double y) 
{
	xpos = x;
	ypos = y;
}


void Card::render() 
{
	SDL_Rect dect;

	dect.x = xpos;
	dect.y = ypos;

	

	if(isFace)TextureManager::Draw(textureCard, dect);
	else TextureManager::Draw(textureBack, dect);
}