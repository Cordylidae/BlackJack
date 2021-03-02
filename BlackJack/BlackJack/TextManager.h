#pragma once

#include"TextureManager.h"

class TextManager : public TextureManager 
{

private:
	
public:
	static SDL_Texture* LoadText(std::string text, int size = 25, SDL_Color color = { 255,255,255 }, std::string file="assets/Fonts/Bebas.ttf");
	static SDL_Texture* LoadImage(std::string file) = delete;
};
