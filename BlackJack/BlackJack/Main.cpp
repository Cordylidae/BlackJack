#include<memory>
#include"Game.h"


int main(int argc, char* argv[])
{
	std::unique_ptr<Game> game;
	
	game = std::make_unique<Game>("Black Jack v.0.1");

	while (game->running())
	{
		game->handleEvents();
		game->update();
		game->render();
	}


	return 0;
}