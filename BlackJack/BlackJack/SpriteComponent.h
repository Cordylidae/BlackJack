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
	bool full;

public:

	SpriteComponent() = default;
	SpriteComponent(std::string path,bool f=true):full(f)
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

	}
	void update() override 
	{
		destRect.x = transform->position.x;
		destRect.y = transform->position.y;
	}
	
	void draw() override 
	{
		if (full)TextureManager::Draw(texture);
		else TextureManager::Draw(texture,destRect);

	}

	 
};


#endif // ! SPRIT_COMP_H