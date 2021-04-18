#pragma once

#include<iostream>
#include<string>
#include"SDL.h"
#include"SDL_image.h"
#include"SDL_ttf.h"
#include"SDL_mixer.h"
#include"SDL_audio.h"
#include"Vector2d.h"


class Card
{
private:

	bool isAce;
	bool isAnim;
	int score;
	std::string namePath;
	std::string name;

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

	void swapTextureCard(std::string namePath);
	void swapTextureBack(std::string namePath);

	SDL_Rect sizeOfCard();

	bool isFace;
};
