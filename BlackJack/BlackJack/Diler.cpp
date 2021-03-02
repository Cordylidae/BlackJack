#include"Diler.h"
#include"TextManager.h"

Diler::Diler(double x, double y,int number):Player(x,y,number) {

	playerText = TextManager::LoadText("#Diler", 25, {0,0,0});
	playerState = nullptr;

	firstCard = true;
}

Diler::~Diler() {
	SDL_DestroyTexture(playerState);
	SDL_DestroyTexture(playerText);

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
	if (state != Player::Burn)state = Player::None;

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

}

int Diler::getScore()
{
	int temp = 0, countOfAce = 0;



	for (auto card : cards)
	{
		if (card->isFace) {
			if (card->getIsAce()) { temp += 1; countOfAce++; }
			else temp += card->getScore();
		}
	}

	for (int i = 0; i < countOfAce; i++)
	{
		if (temp + 10 <= 21) { temp += 10; }
	}
		
	if (temp > 21)state = Player::Burn;
	if (temp == 21)state = Player::Win;

	return temp;
}

void Diler::drawTextOfPlayer()
{
	SDL_Rect pos, rect;
	SDL_QueryTexture(playerText, NULL, NULL, &pos.w, &pos.h);

	pos.x = xpos;
	pos.y = ypos - 30;

	TextManager::Draw(playerText, pos);
}