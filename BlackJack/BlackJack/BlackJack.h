#pragma once

#include"Diler.h"

struct UI
{
	SDL_Texture* sprite;
	SDL_Rect rect;
	SDL_Rect src;

};


class BlackJack
{
private:
	
	enum State {Start, Animation, PlayerInterection, End, Option} state;
	//int countOfPlayer;

	UI hit, stand, sound, option, optionUI, close;
	std::vector<std::shared_ptr<UI>> texts;

	SDL_Texture* background;
	Deck* deck;
	std::vector<std::shared_ptr<Player>> players; // 0 - index of Diler

	Mix_Music* music;
	bool musicOn;

	int indexPlayer, indexDiler;
	int indexStyleCard, indexStyleBack, numberOfText;
	const int numberOfPlayer;
	bool click;
	bool optionOn;

public:
	bool closeOff;

	BlackJack(int playerNum = 3);
	~BlackJack();

	// for game object
	void update();
	void render();
	void reset();


	// for UI interaction
	void takeHit();
	void takeStand();
	void takeOption(int index_,bool isCard_);

	// for game logic 
	void playerInteractiv();
	void WinLose();
	void drawTextInOption();
	void renderUIBack();
	void renderUIFront();

	// for initialize from constructor 
	void startGame();
	void makeUI();
};
