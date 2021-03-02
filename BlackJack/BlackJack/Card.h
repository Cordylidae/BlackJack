#ifndef CARD_H
#define CARD_H

#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_ttf.h"
#include"Vector2d.h"

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
	bool isAnim;
	int score;

	Vector2D now,finish,direction;
	double speedAnim;

	SDL_Texture* textureCard, *textureBack;

public:
	Card(std::string namePath, int score_, double x=0,double y=0, bool isAce_ = false);
	~Card();

	void render();
	void update(double x, double y);
	void animation();
	
	int getScore() { return score; }
	bool getIsAce() { return isAce; }
	bool getIsAnimation() { return isAnim; }

	SDL_Rect sizeOfCard();

	bool isFace;
};

#endif