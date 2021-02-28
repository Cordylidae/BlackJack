#include"Player.h"

Player::Player(double x,double y){
	xpos = x;
	ypos = y;

	cards.clear();
}
Player::~Player() {
	
	cards.clear();

	std::cout << "Player Hand Cleaned" << std::endl;
}

void Player::update(){

	for (int i = 0; i < cards.size(); i++) {
		cards[i]->update(xpos+i*20, ypos);
	}
}

void Player::render()
{
	Deck::render();	
}

void Player::addCardtoHand(std::shared_ptr<Card> card)
{
	Player::cards.push_back(card);
	
	std::cout << cards.size() << std::endl;

}
