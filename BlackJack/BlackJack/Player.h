#pragma once

#include"Deck.h"

class Player : public Deck
{
public:
	enum State { Win, Lose, Burn, None };

private:
	State state;
	int score;

public:
	Player(double x,double y);
	~Player();

	void update() override;
	void render() override;
	std::shared_ptr<Card> moveTopCard() = delete;
	void addCardtoHand(std::shared_ptr<Card> card);
	State playerState();

};