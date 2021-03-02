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
		cards[i]->update((xpos+i*20), ypos);
	}

	score = getScore();
}

void Player::render()
{
	Deck::render();	
}

void Player::addCardtoHand(std::shared_ptr<Card> card,bool face)
{
	if (state == Player::None) {

		Player::cards.push_back(card);

		cards.back()->isFace = face;

		//score = getScore();

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

int Player::getScore()
{
	int temp = 0, countOfAce=0;

	for (auto card : cards)
	{
		if (card->getIsAce()) { temp += 1; countOfAce++; }
		else temp+= card->getScore();
	}

	for (int i = 0; i < countOfAce;i++)
	{
		if (temp + 10 <= 21) { temp += 10;}
	}

	if (score > 21)state = Player::Burn;
	if (score == 21)state = Player::Win;

	return temp;
}