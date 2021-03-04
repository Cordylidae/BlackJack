#include"TextureManager.h"

image_cache image;

SDL_Texture* TextureManager::LoadImage(std::string file)
{
	
	return image.get_image(file);
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