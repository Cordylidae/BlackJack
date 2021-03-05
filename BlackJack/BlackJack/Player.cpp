#include"Player.h"
#include"TextManager.h"

Player::Player(double x,double y,int number):index(number){
	xpos = x;
	ypos = y;

	state = Player::None;
	score = 0;

	playerText = nullptr;
	playerState = nullptr;

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

	drawTextOfPlayer();

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

void Player::drawTextOfPlayer()
{
	SDL_Rect pos, rect;
	SDL_QueryTexture(playerText, NULL, NULL, &pos.w, &pos.h);

	pos.x = xpos;
	pos.y = ypos - 30;


	playerText = TextManager::LoadText("Player " + std::to_string(index));

	SDL_SetTextureColorMod(playerText, 255, 255, 255);
	if (isMyTurn)SDL_SetTextureColorMod(playerText, 0, 255, 0);

	TextManager::Draw(playerText, pos);


	pos.y = ypos + 88;
	playerState = TextManager::LoadText(std::to_string(getScore()));
	SDL_SetTextureColorMod(playerState, 0, 0, 0);
	TextManager::Draw(playerState, pos);

	pos.x += 44;

	switch (state)
	{
	case Win:
		playerState = TextManager::LoadText("Win", 25, {0,255,0});
		TextManager::Draw(playerState, pos);
		break;
	case Lose:
		playerState = TextManager::LoadText("Lose", 25, { 255,0,0 });
		TextManager::Draw(playerState, pos);
		break;
	case Burn:
		playerState = TextManager::LoadText("Burn", 25, { 255,180,0 });
		TextManager::Draw(playerState, pos);
		break;
	}

}

void Player::swapTextureCard(std::string namePath)
{
	Deck::swapTextureCard(namePath);
}
void Player::swapTextureBack(std::string namePath)
{
	Deck::swapTextureBack(namePath);
}