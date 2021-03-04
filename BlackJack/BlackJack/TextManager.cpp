#include"TextManager.h"

text_cache texts;

SDL_Texture* TextManager::LoadText(std::string text, int size, SDL_Color color)
{
	return texts.get_image(text,size,color);
}