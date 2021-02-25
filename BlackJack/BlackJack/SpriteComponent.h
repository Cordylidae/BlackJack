#ifndef SPRITE_COMP_H
#define SPRITE_COMP_H

#include"Components.h"
#include"SDL.h"
#include<string>
#include"TextureManager.h"

class SpriteComponent : public Component 
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;

public:

	SpriteComponent() = default;
	SpriteComponent(std::string path)
	{
		setTex(path);
	}

	void setTex(std::string path)
	{
		texture = TextureManager::LoadImage(path);
	}

	void init() override 
	{
		transform = &entity->getComponent<TransformComponent>();

		srcRect.x = srcRect.y = 0;
	}
	void update() override 
	{
		destRect.x = transform->position.x;
		destRect.y = transform->position.y;
	}
	
	void draw() override 
	{
		TextureManager::Draw(texture,destRect);
	}
	 
};

#endif // ! SPRIT_COMP_H