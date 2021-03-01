#include"Player.h"

Player::Player(double x,double y){
	xpos = x;
	ypos = y;

	state = Player::None;
	score = 0;

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
	if (state == Player::None) {

		Player::cards.push_back(card);

		cards.back()->isFace = true;

		score += (cards.back()->getScore());

		playerState();

		std::cout << cards.size() << " " <<score<<std::endl;


	}
	if (state == Player::Burn)
	{
		std::cout<<"Burn"<<std::endl;
	}
	if (state == Player::Win)
	{
		std::cout << "Win" << std::endl;
	}
	if (state == Player::Lose)
	{
		std::cout << "Lose" << std::endl;
	}
	
}

Player::State Player::playerState()
{
	if (score > 21)state = Player::Burn;
	if (score == 21)state = Player::Win;
	//if (score < 17)state = Player::Lose;
	//if (score >= 17 && score <= 21)state = Player::Win;
	return state;
}