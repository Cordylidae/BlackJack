#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include"Game.h"

class TextureManager {

private:
	
public:
	static SDL_Texture* LoadImage(std::string file, SDL_Renderer* rend);
	static void ApplySurface(int x, int y, SDL_Texture* tex, SDL_Renderer* rend);

};

#endif
