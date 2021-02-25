#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"

class Card
{
private:

	bool isAce;
	bool isFace;
	int score;

	double xpos;
	double ypos;

	SDL_Texture* textureCard, *textureBack;

public:
	Card(std::string namePath, int score_, double x=0,double y=0, bool isAce_ = false);
	~Card();

	void render();
	void update();

};

#endif