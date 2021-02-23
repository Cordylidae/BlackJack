#ifndef BlackJack_H
#define BlackJack_H

#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"

class BlackJack
{
private:
	//enum State {Start, Turn, End} state;
	//int countOfPlayer;

	SDL_Texture* background, *image;
	//SDL_Texture;
	SDL_Renderer* renderer;
	//Player* player;
	//Deck* deck;


public:
	BlackJack(SDL_Renderer* rend);
	~BlackJack();

	void Update();
	void Render();
};


#endif BlackJack_H