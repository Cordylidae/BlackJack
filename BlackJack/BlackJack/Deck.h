#ifndef  DECK_H
#define DECK_H

#include"Card.h"
#include<vector>
#include<memory>

class Deck
{
private:

protected:
	std::vector<std::shared_ptr<Card>> cards;

public:
	Deck();
	virtual ~Deck();

	virtual void update();
	virtual void render();
	bool isEmpty() { return cards.empty(); }
	std::shared_ptr<Card> moveTopCard();
};

#endif // ! DECK_H