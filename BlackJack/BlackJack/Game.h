#ifndef GAME_H
#define GAME_H

#include<memory>
#include"BlackJack.h"

class Game
{
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::unique_ptr<BlackJack> blackJack;

public:
	Game(const char* title = "noname", int xpos = SDL_WINDOWPOS_CENTERED, int ypos = SDL_WINDOWPOS_CENTERED, int width = 800, int height = 600, bool fullscreen = false);
	~Game();

	
	void handleEvents();
	void update();
	void render();

	bool running() { return isRunning; }
};

#endif // GAME_H