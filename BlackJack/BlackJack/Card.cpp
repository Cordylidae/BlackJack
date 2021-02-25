#include"Card.h"
#include"TextureManager.h"
#include<math.h>

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

	//std::cout << "Card Deleted" << std::endl;
}


void Card::update() 
{
	xpos = sin(M_PI * SDL_GetTicks() / 5000.0) * 100.0 + 250;// +rand() % 52;
	ypos = cos(M_PI * SDL_GetTicks() / 5000.0) * 100.0 + 250;// +rand() % 52;
	/*xpos = rand() % 600;
	ypos = rand() % 400;*/
}


void Card::render() 
{
	SDL_Rect dect;

	dect.x = xpos;
	dect.y = ypos;

	

	if(isFace)TextureManager::Draw(textureCard, dect);
	else TextureManager::Draw(textureBack, dect);
}