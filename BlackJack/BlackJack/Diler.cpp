#include"Diler.h"

Diler::Diler(double x, double y):Player(x,y) {
	firstCard = true;
}

Diler::~Diler() {

	std::cout << "Diler Hand Cleaned" << std::endl;
}

void Diler::update() {

	Player::update();
}

void Diler::render()
{
	Player::render();
}

void Diler::addCardtoHand(std::shared_ptr<Card> card, bool face)
{
	if (state == Player::None) {

		cards.push_back(card);

		if (firstCard){
			cards.back()->isFace = false;
			firstCard = false;
		}
		else cards.back()->isFace = face;

		score = getScore();

		//std::cout << cards.size() << " " << score << std::endl;


	}
	if (state == Player::Burn)
	{
		std::cout << "Burn" << std::endl;
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
