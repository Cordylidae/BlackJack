#ifndef SPRITE_COMP_H
#define SPRITE_COMP_H

#include"Components.h"
#include"SDL.h"
#include<string>

class SpriteComponent : public Component 
{
private:
	PositionComponent* position;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:

	SpriteComponent() = default;
	SpriteComponent(std::string path)
	{

	}

	void init() override 
	{
		position = &entity->getComponent<PositionComponent>();

		srcRect.x = srcRect.y = 0;
	}
	void update() override 
	{
		destRect.x = position->x();
		destRect.y = position->y();
	}
	
	void draw() override 
	{
		
	}
	 
};

#endif // ! SPRIT_COMP_H