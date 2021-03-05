#pragma once

#include"Player.h"

class Diler : public Player
{
private:
	bool firstCard;
public:
	Diler(double x, double y,int number);
	virtual ~Diler();

	void update() override;
	void render() override;
	std::shared_ptr<Card> moveTopCard() = delete;

	void addCardtoHand(std::shared_ptr<Card> card, bool face = true) override;
	int getScore() override;
	void drawTextOfPlayer() override;

	void swapTextureCard(std::string namePath) override;
	void swapTextureBack(std::string namePath) override;
};