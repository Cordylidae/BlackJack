#include"Deck.h"
#include"TextureManager.h"
#include<algorithm>
#include<thread>

Deck::Deck(double x,double y):xpos(x),ypos(y)
{
	std::shared_ptr<Card> card;
	

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++)
		{
			std::string part = ""; int score = 10; bool isAce = false;

			switch (i)
			{
			case 0:
				part += "Heart";
				break;
			case 1:
				part += "Pika";
				break;
			case 2:
				part += "Krest";
				break;
			case 3:
				part += "Rube";
				break;
			}

			switch (j)
			{
			case 1:
			{
				part += "Ace";
				score += 1;
				isAce = true;
			}
				break;
			case 10:
				part += "10";
				break;
			case 11:
				part += "Jack";
				break;
			case 12:
				part += "Queen";
				break;
			case 13:
				part += "King";
				break;
			default:
			{
				char digit = j + '0';
				part += digit;
				score = j;
			}
				break;
			}

			card = std::make_shared<Card>(part + ".png",score, sin(SDL_GetTicks())*5.0 + xpos, cos(SDL_GetTicks())*5.0 + ypos, isAce);
			cards.push_back(card);
		}

		std::random_shuffle(cards.begin(),cards.end());
	}
}

Deck::~Deck()
{
	
	cards.clear();

	std::cout << "Deck Cleaned" << std::endl;
}

void Deck::update()
{
	
}

bool Deck::animationFinish()
{
	bool animYet = false;

	for (int i = 0; i < cards.size(); i++) {
		if (cards[i]->getIsAnimation())animYet = true;
	}

	return !animYet;
}

void Deck::render()
{
	for (int i = 0; i < cards.size(); i++) {
		cards[i]->render();
	}
}

std::shared_ptr<Card> Deck::moveTopCard()
{
	if (isEmpty()) {
		std::cout << "Empty Deck cant delete object" << std::endl;
	}

	std::shared_ptr<Card> temp;

	//cards.back()->update();
	temp = cards.back();
	cards.pop_back();

	return temp;
}

void Deck::openCard()
{
	for (int i = 0; i < cards.size(); i++) {
		cards[i]->isFace = true;
	}
}

Vector2D Deck::getPos()
{
	Vector2D vec;
	vec.x = xpos;
	vec.y = ypos;

	return vec;
}

void Deck::swapTextureCard(std::string namePath)
{
	for (auto c : cards)
	{
		c->swapTextureCard(namePath);
	}
}
void Deck::swapTextureBack(std::string namePath)
{
	for (auto c : cards)
	{
		c->swapTextureBack(namePath);
	}
}