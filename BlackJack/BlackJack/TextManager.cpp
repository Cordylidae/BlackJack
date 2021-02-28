#include"TextManager.h"

SDL_Texture* TextManager::LoadText(std::string file, int size, SDL_Color color)
{
	SDL_Surface* loadedText = nullptr;
	SDL_Texture* texture = nullptr;

	TTF_Font* Sans = TTF_OpenFont(file.c_str(), size);

	if (Sans != nullptr) {
		loadedText = TTF_RenderText_Solid(Sans, "win,lose,burn", color); // need to modificied
		texture = SDL_CreateTextureFromSurface(Game::renderer, loadedText);
		SDL_FreeSurface(loadedText);
	}
	else std::cout << SDL_GetError() << std::endl;
	
	return texture;
}