#pragma once

#include"Player.h"

class Diler : public Player
{
private:
	bool firstCard;
public:
	Diler(double x, double y);
	virtual ~Diler();

	void update() override;
	void render() override;
	std::shared_ptr<Card> moveTopCard() = delete;
	void addCardtoHand(std::shared_ptr<Card> card, bool face = true) override;
	
};