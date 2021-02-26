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

void TextureManager::Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest) {
	SDL_RenderCopy(Game::renderer, tex, &src, &dest);
}

void TextureManager::Draw(SDL_Texture* tex, SDL_Rect dest) {
	SDL_Rect pos;
	pos.x = dest.x;
	pos.y = dest.y;



	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	SDL_RenderCopy(Game::renderer, tex, NULL, &pos);
}

void TextureManager::Draw(SDL_Texture* tex) {
	SDL_RenderCopy(Game::renderer, tex, NULL, NULL);
}