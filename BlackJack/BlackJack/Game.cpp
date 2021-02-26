#include"TextureManager.h"
#include"Game.h"

#include"Components.h"

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;
//Manager Game::manager;




Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{


	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (!SDL_Init(SDL_INIT_EVERYTHING))
	{
		std::cout << "Subsystems Initialised!..." << std::endl;

		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else {
		isRunning = false;
	}

	blackJack = std::make_unique<BlackJack>();
	
}

Game::~Game() 
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();

	std::cout << "Game Cleaned" << std::endl;
}

void Game::handleEvents()
{
	SDL_PollEvent(&event);

	switch (event.type)
	{
		case SDL_QUIT:
			isRunning = false;
			break;

		default:
			break;
	}
}

void Game::update() 
{
	blackJack->update();

	//Vector2D vec(Card.getComponent<TransformComponent>().position);
	/*
	Card.getComponent<TransformComponent>().position.Add(Vector2D(5, 0));

	if (Card.getComponent<TransformComponent>().position.x > 300)
	{
		Card.getComponent<SpriteComponent>().setTex("assets/Cards/Back.png");
	}*/

	/*if (vec.x < 600 && vec.y <400)
	{
		Card.getComponent<TransformComponent>().position.Add(Vector2D(5, 0));
		Card.getComponent<SpriteComponent>().setTex("assets/Cards/PikaKing.png");
	}
	else if (vec.x >= 600 && vec.y < 400)
	{
		Card.getComponent<TransformComponent>().position.Add(Vector2D(0, 5));
		Card.getComponent<SpriteComponent>().setTex("assets/Cards/HeartKing.png");
	}
	else if (vec.x >= 0 && vec.y >= 400)
	{
		Card.getComponent<TransformComponent>().position.Add(Vector2D(-5, 0));
		Card.getComponent<SpriteComponent>().setTex("assets/Cards/RubeKing.png");
	}
	else if (vec.x < 0 && vec.y >= 0)
	{
		Card.getComponent<TransformComponent>().position.Add(Vector2D(0, -5));
		Card.getComponent<SpriteComponent>().setTex("assets/Cards/KrestKing.png");
	}*/
}

void Game::render() 
{
	SDL_RenderClear(renderer);

	blackJack->render();

	SDL_RenderPresent(renderer);
}
