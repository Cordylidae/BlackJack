#include"TextManager.h"

TTF_Font* sans = nullptr;

void TextManager::LoadFont(std::string file, int size)
{
	sans = TTF_OpenFont(file.c_str(), size);
	if (sans == nullptr) std::cout << SDL_GetError() << std::endl;
}

SDL_Texture* TextManager::LoadText(std::string text, int size, SDL_Color color)
{
	SDL_Surface* loadedText = nullptr;
	SDL_Texture* texture = nullptr;

	//TTF_Font* Sans = TTF_OpenFont(file.c_str(), size);
	TTF_SetFontOutline(sans, size);


	if (sans != nullptr) {
		loadedText = TTF_RenderText_Solid(sans, text.c_str(), color); // need to modificied
		texture = SDL_CreateTextureFromSurface(Game::renderer, loadedText);
		SDL_FreeSurface(loadedText);
	}
	else std::cout << SDL_GetError() << std::endl;
	
	return texture;
}