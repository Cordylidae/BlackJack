#include<memory>
#include<time.h>
#include"Game.h"


int main(int argc, char* argv[])
{
	srand(time(0));

	std::unique_ptr<Game> game;
	
	game = std::make_unique<Game>("Black Jack v.0.1");

	const int FPS = 60;
	const int frameDelay = 1000 / FPS;

	Uint64 frameStart;
	int frameTime;

	while (game->running())
	{
		frameStart = SDL_GetTicks();

		game->handleEvents();
		game->update();
		game->render();

		frameTime = SDL_GetTicks() - frameStart;

		if (frameDelay > frameTime)
		{
			SDL_Delay(frameDelay - frameTime);
		}
	}


	return 0;
}