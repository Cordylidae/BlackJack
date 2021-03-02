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
	:score(score_),isAce(isAce_)
{
	speedAnim = 100;

	now.x = x;
	now.y = y;

	isFace = false;
	isAnim = false;

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
	if (!isAnim) {

		finish.x = x;
		finish.y = y;
		isAnim = true;

		direction = finish - now;
		direction /= speedAnim;

		/*direction.x = int(direction.x);
		direction.y = int(direction.y);*/

		/*std::cout << direction.x<<" " << direction.y << std::endl;

		std::cout << now.x << " " << now.y << std::endl;
		std::cout << finish.x << " " << finish.y << std::endl << std::endl;*/

	}
	else animation();
	
	/*finish.x = x;
	finish.y = y;

	std::cout << now.x << " " << now.y << std::endl;
	std::cout << finish.x << " " << finish.y << std::endl << std::endl;

	now.x = x;
	now.y = y;*/
}

void Card::animation()
{
	if (abs(now.x - finish.x) <= 0.1 && abs(now.y - finish.y) <= 0.1)isAnim = false;
	else {
		now += direction;
	}
}

void Card::render() 
{
	SDL_Rect dect;

	dect.x = now.x;
	dect.y = now.y;


	if(isFace)TextureManager::Draw(textureCard, dect);
	else TextureManager::Draw(textureBack, dect);
}

SDL_Rect Card::sizeOfCard()
{
	SDL_Rect rect;
	rect.x = rect.y = 0;

	SDL_QueryTexture(textureCard, NULL, NULL, &rect.w, &rect.w);

	return rect;
}