#pragma once

#include"Deck.h"

class Player : public Deck
{
public:
	enum State { Win, Lose, Burn, None };
	State state;

protected:
	int score;

public:
	Player(double x,double y);
	virtual ~Player();

	void update() override;
	void render() override;
	std::shared_ptr<Card> moveTopCard() = delete;
	
	virtual void addCardtoHand(std::shared_ptr<Card> card, bool face=true);
	
	int getScore();
	
};