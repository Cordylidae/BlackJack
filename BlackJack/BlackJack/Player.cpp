#include"Player.h"

Player::Player() {
	cards.clear();
}
Player::~Player() {
	
	cards.clear();

	std::cout << "Player Hand Cleaned" << std::endl;
}

void Player::update(){}

void Player::render()
{
	Deck::render();	
}

void Player::addCardtoHand(std::shared_ptr<Card> card)
{
	Player::cards.push_back(card);
	
	std::cout << cards.size() << std::endl;

}
