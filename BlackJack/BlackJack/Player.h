#pragma once

#include"Deck.h"

class Player : public Deck
{
private:

public:
	Player();
	~Player();

	void update() override;
	void render() override;
	std::shared_ptr<Card> moveTopCard() = delete;
	void addCardtoHand(std::shared_ptr<Card> card);


};