#ifndef TEXTURE_MANAGER_H
#define TEXTURE_MANAGER_H

#include"Game.h"

class TextureManager {

private:
	
public:
	static SDL_Texture* LoadImage(std::string file);
	static void Draw(SDL_Texture* tex, double x, double y);

};

#endif
