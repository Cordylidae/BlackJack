#ifndef BlackJack_H
#define BlackJack_H

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
	
	enum State {Start, Animation, PlayerInterection, End} state;
	//int countOfPlayer;

	UI hit, stand, sound;
	SDL_Texture* background;
	Deck* deck;
	std::vector<std::shared_ptr<Player>> players; // 0 - index of Diler

	Mix_Music* music;
	bool musicOn;

	int indexPlayer,indexDiler;
	const int numberOfPlayer;
	bool click;
	


public:
	BlackJack(int playerNum = 3);
	~BlackJack();

	void update();
	void render();
	void reset();

	void takeHit();
	void takeStand();

	void playerInteractiv();
	void WinLose();
	void renderUI();
};


#endif BlackJack_H