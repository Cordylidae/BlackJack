#ifndef BlackJack_H
#define BlackJack_H

#include"Player.h"


class BlackJack
{
private:
	//enum State {Start, Turn, End} state;
	//int countOfPlayer;

	SDL_Texture* background;
	Deck* deck;
	Player* player;

	bool click;

public:
	BlackJack();
	~BlackJack();

	void update();
	void render();
	void reset();
};


#endif BlackJack_H