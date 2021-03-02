#ifndef BlackJack_H
#define BlackJack_H

#include"Diler.h"


class BlackJack
{
private:
	
	enum State {Start, Animation, PlayerInterection, End} state;
	//int countOfPlayer;

	SDL_Texture* background;
	Deck* deck;
	std::vector<std::shared_ptr<Player>> players; // 0 - index of Diler

	int indexPlayer,indexDiler;
	bool click;

public:
	BlackJack();
	~BlackJack();

	void update();
	void render();
	void reset();
	void playerInteractiv();
	void WinLose();
};


#endif BlackJack_H