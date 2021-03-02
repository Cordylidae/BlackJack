#include"TextManager.h"



SDL_Texture* TextManager::LoadText(std::string text, int size, SDL_Color color, std::string file)
{
	SDL_Surface* loadedText = nullptr;
	SDL_Texture* texture = nullptr;

	TTF_Font* sans = TTF_OpenFont(file.c_str(), size);
	if (sans == nullptr) std::cout << SDL_GetError() << std::endl;


	if (sans != nullptr) {
		loadedText = TTF_RenderText_Solid(sans, text.c_str(), color); // need to modificied
		texture = SDL_CreateTextureFromSurface(Game::renderer, loadedText);
		SDL_FreeSurface(loadedText);
	}
	else std::cout << SDL_GetError() << std::endl;
	
	return texture;
}