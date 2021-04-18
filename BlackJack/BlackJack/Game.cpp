#include"TextManager.h"
#include"Game.h"

//#include"Components.h"

SDL_Event Game::event;
SDL_Renderer* Game::renderer = nullptr;
SDL_Texture* text;


Game::Game(const char* title, int xpos, int ypos, int width, int height, bool fullscreen_)
{

	fullscreen = fullscreen_ = false;
	click = true;
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
		else std::cout << SDL_Error << std::endl;

		

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}




		if (!TTF_Init())
		{
			std::cout << "Can make Text!" << std::endl;
		}
		else std::cout << "Problems with SDL_TTF\n";

		if (!Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 2048)) {
			std::cout << "Can make Sound!" << std::endl;
		}
		else std::cout << "Problems with Sound\n";

		isRunning = true;
	}
	else {
		isRunning = false;
	}



	blackJack = new BlackJack(4);

	text = nullptr;

	//make texture of text
	{
		text = TextManager::LoadText("Black Jack view");
	}

	
}

Game::~Game() 
{
	delete blackJack;

	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);

	Mix_Quit();
	TTF_Quit();
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
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_ESCAPE && click)
			{
				setScreen();
				click = false;
			}
			break;
		case SDL_KEYUP:
			if (event.key.keysym.sym == SDLK_ESCAPE)
			{
				click = true;
			}
			break;
		default:
			break;
	}
}

void Game::update() 
{
	blackJack->update();
	if (blackJack->closeOff)isRunning = false;
}

void Game::render() 
{
	SDL_RenderClear(renderer);

	blackJack->render();

	SDL_Rect dest;
	dest.x = dest.y = 0;
	SDL_QueryTexture(text, NULL, NULL, &dest.w, &dest.h);

	TextureManager::Draw(text,dest);


	SDL_RenderPresent(renderer);
}

bool Game::enterMouseInRect(SDL_Rect& rect)
{
	int x, y;
	SDL_GetMouseState(&x, &y);

	

	x -= rect.x;
	y -= rect.y;

	if (x > 0 && x < rect.w
		&& y > 0 && y < rect.h)
	{
		return true;
	}

	return false;
}

void Game::setScreen()
{
	fullscreen = !fullscreen;
	int flags = 0;

	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	SDL_SetWindowFullscreen(window, flags);
}