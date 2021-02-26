#ifndef BlackJack_H
#define BlackJack_H

#include"Card.h"
#include"Deck.h"

class BlackJack
{
private:
	//enum State {Start, Turn, End} state;
	//int countOfPlayer;

	SDL_Texture* background;
	//SDL_Texture;
	//Player* player;
	//Deck* deck;
	Card* card;

public:
	BlackJack();
	~BlackJack();

	void update();
	void render();
};


#endif BlackJack_H