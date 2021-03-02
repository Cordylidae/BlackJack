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
	double xpos, ypos;

public:
	Deck(double x=632,double y=100);
	virtual ~Deck();

	virtual void update();
	virtual void render();
	bool isEmpty() { return cards.empty(); }
	std::shared_ptr<Card> moveTopCard();

	virtual bool animationFinish();
	void openCard();
};

#endif // ! DECK_H