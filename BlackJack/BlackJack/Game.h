#pragma once

#include<memory>
#include"BlackJack.h"
//#include"Components.h"

class Game
{
private:
	bool isRunning;
	bool fullscreen;
	bool click;
	SDL_Window* window;
	//std::unique_ptr<BlackJack> blackJack;
	BlackJack* blackJack;

public:
	Game(const char* title = "Black Jack", int xpos = SDL_WINDOWPOS_CENTERED, int ypos = SDL_WINDOWPOS_CENTERED, int width = 800, int height = 600, bool fullscreen = false);
	~Game();

	
	void handleEvents();
	void update();
	void render();

	bool running() { return isRunning; }
	static bool enterMouseInRect(SDL_Rect&);

	static SDL_Renderer* renderer;
	static SDL_Event event;

	void setScreen();
	void setClose();
};
