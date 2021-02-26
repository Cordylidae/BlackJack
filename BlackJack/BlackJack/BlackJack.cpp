#include"BlackJack.h"
#include"TextureManager.h"


#include"Components.h"

extern Manager manager;

BlackJack::BlackJack()
{
	background = TextureManager::LoadImage("assets/table.png");
	//deck = new Deck();
	//card = new Card("assets/Cards/Pika9.png",);
	auto& Card(manager.addEntity());
	auto& Table(manager.addEntity());



	Card.addComponent<TransformComponent>();
	Card.addComponent<SpriteComponent>("assets/Cards/Z_Original.png", false, true);
	Card.getComponent<SpriteComponent>().animations.emplace(0, Animation(0, 1, 100));
	Card.getComponent<SpriteComponent>().animations.emplace(1, Animation(1, 4, 100));
	Card.getComponent<SpriteComponent>().Play(0);
	Card.addComponent<KeyboardController>();
	Card.addGroup(groupLabes::groupCards);
	Card.getComponent<SpriteComponent>().SetRect(68, 88);

	Table.addComponent<TransformComponent>();
	Table.addComponent<SpriteComponent>("assets/table.png");
	Table.addGroup(groupLabes::groupTable);
	Table.getComponent<SpriteComponent>().init();
}

BlackJack::~BlackJack()
{
	//delete deck;
	//delete card;
	SDL_DestroyTexture(background);
	
	std::cout << "Black_Jack Cleaned" << std::endl;
}

void BlackJack::update()
{
	//card->Update();
	//deck->update();
	manager.refresh();
	manager.update();
}

void BlackJack::render()
{

	//SDL_RenderCopy(Game::renderer, background, NULL, NULL);

	manager.draw(manager.getGroup(groupLabes::groupTable));
	manager.draw(manager.getGroup(groupLabes::groupCards));
	//card->Render();
	//deck->render();
}
