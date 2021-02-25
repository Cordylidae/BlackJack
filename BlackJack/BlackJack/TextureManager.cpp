#include"TextureManager.h"


SDL_Texture* TextureManager::LoadImage(std::string file)
{
	SDL_Surface* loadedImage = nullptr;
	SDL_Texture* texture = nullptr;

	loadedImage = SDL_LoadBMP(file.c_str());
	if (loadedImage != nullptr) {
		texture = SDL_CreateTextureFromSurface(Game::renderer, loadedImage);
		SDL_FreeSurface(loadedImage);
	}
	else
	{
		loadedImage = IMG_Load(file.c_str());

		if (loadedImage != nullptr)
		{
			texture = SDL_CreateTextureFromSurface(Game::renderer, loadedImage);
			SDL_FreeSurface(loadedImage);
		}
		else std::cout << SDL_GetError() << std::endl;
	}
	return texture;
}

void TextureManager::Draw(SDL_Texture* tex, double x, double y) {
	SDL_Rect pos;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(Game::renderer, tex, NULL, &pos);
}