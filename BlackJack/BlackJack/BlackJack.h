#ifndef BlackJack_H
#define BlackJack_H

//#include<iostream>
//#include<string>
//#include"SDL.h"
//#include"SDL_image.h"
#include"Card.h"
#include"Deck.h"

class BlackJack
{
private:
	//enum State {Start, Turn, End} state;
	//int countOfPlayer;

	SDL_Texture* background;
	//SDL_Texture;
	SDL_Renderer* renderer;
	//Player* player;
	Deck* deck;
	Card* card;

public:
	BlackJack(SDL_Renderer* rend);
	~BlackJack();

	void update();
	void render();
};


#endif BlackJack_H