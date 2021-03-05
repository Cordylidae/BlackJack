#pragma once

#include"Deck.h"

class Player : public Deck
{
public:
	enum State { Win, Lose, Burn, None };
	State state;
	bool isMyTurn = false;

protected:
	int score;
	int index;
	SDL_Texture *playerText, *playerState;

public:
	Player(double x,double y,int number);
	virtual ~Player();

	void update() override;
	void render() override;
	
	std::shared_ptr<Card> moveTopCard() = delete;
	
	virtual void addCardtoHand(std::shared_ptr<Card> card, bool face=true);
	virtual void drawTextOfPlayer();
	virtual int getScore();
	
	void swapTextureCard(std::string namePath) override;
	void swapTextureBack(std::string namePath) override;
};