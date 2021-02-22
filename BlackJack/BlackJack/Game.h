#ifndef GAME_H
#define GAME_H

#include<iostream>
#include"SDL.h"
#include"SDL_image.h"


class Game
{
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;

public:
	Game(const char* title = "noname", int xpos = SDL_WINDOWPOS_CENTERED, int ypos = SDL_WINDOWPOS_CENTERED, int width = 800, int height = 600, bool fullscreen = false);
	~Game();

	
	void handleEvents();
	void update();
	void render();
	
	bool running() { return isRunning; }
};

#endif // GAME_H