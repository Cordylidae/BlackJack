#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_ttf.h"

enum groupLabes
{
	groupCards,
	groupPlayers,
	groupTable
};

class Card
{
private:

	bool isAce;
	int score;

	double xpos;
	double ypos;

	SDL_Texture* textureCard, *textureBack;

public:
	Card(std::string namePath, int score_, double x=0,double y=0, bool isAce_ = false);
	~Card();

	void render();
	void update(double x, double y);
	int getScore() { return score; }
	bool getIsAce() { return isAce; }

	bool isFace;
};

#endif