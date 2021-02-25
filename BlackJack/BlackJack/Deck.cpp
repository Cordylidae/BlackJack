#include"Deck.h"
#include"TextureManager.h"
#include<algorithm>
#include<thread>

Deck::Deck()
{
	
	std::shared_ptr<Card> card;
	
	for (int i = 0; i < 4; i++) {
		for (int j = 1; j < 14; j++)
		{
			std::string path = "assets/Cards/"; int score = 10; bool isAce = false;

			switch (i)
			{
			case 0:
				path += "Heart";
				break;
			case 1:
				path += "Pika";
				break;
			case 2:
				path += "Krest";
				break;
			case 3:
				path += "Rube";
				break;
			}

			switch (j)
			{
			case 1:
			{
				path += "Ace";
				score += 1;
				isAce = true;
			}
				break;
			case 10:
				path += "10";
				break;
			case 11:
				path += "Jack";
				break;
			case 12:
				path += "Queen";
				break;
			case 13:
				path += "King";
				break;
			default:
			{
				char digit = j + '0';
				path += digit;
				score = j;
			}
				break;
			}

			card = std::make_shared<Card>(path + ".png",score, sin(SDL_GetTicks())*5.0 + 10, cos(SDL_GetTicks())*5.0 + 10, isAce);
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
	//xpos = sin(M_PI * SDL_GetTicks() / 1000.0)*100.0 + 250;
	//ypos = cos(M_PI * SDL_GetTicks() / 1000.0)*100.0 + 250;
	

	for (int i = 0; i < cards.size(); i++) {
		cards[i]->update();
	}
}


void Deck::render()
{
	//TextureManager::ApplySurface(xpos, ypos, textureCard, renderer);
	for (int i = 0; i < cards.size(); i++) {
		cards[i]->render();
	}
}
