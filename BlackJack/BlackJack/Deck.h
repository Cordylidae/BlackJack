#ifndef  DECK_H
#define DECK_H

#include"Card.h"
#include<vector>
#include<memory>

class Deck
{
private:
	
	std::vector<std::shared_ptr<Card>> cards;

	SDL_Renderer* renderer;

public:
	Deck(SDL_Renderer* rend);
	~Deck();

	void update();
	void render();
};

#endif // ! DECK_H