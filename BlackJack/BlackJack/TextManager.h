#pragma once

#include"TextureManager.h"

class TextManager : public TextureManager 
{

private:

public:
	static SDL_Texture* LoadText(std::string file, int size, SDL_Color color = {255,255,255});
	static SDL_Texture* LoadImage(std::string file) = delete;
};
