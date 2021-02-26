#ifndef SPRITE_COMP_H
#define SPRITE_COMP_H

#include"Components.h"
#include"SDL.h"
#include<string>
#include"TextureManager.h"
#include"Animation.h"
#include<map>


class SpriteComponent : public Component 
{
private:
	TransformComponent* transform;
	SDL_Texture* texture;
	SDL_Rect srcRect, destRect;
	
	bool full;
	bool animated = false;

	int frames;
	int animSpeed;
	int animIndex;

public:
	

	std::map<const char*, Animation> animations;


	SpriteComponent() = default;
	SpriteComponent(std::string path,bool f = true,bool isAnim = false)
		: full(f), animated(isAnim)
	{
		Animation idle = Animation(0, 1, 100);
		Animation move = Animation(1, 4, 100);

		animations.emplace("Idle", idle);
		animations.emplace("Move", move);

		Play("Idle");
		

		setTex(path);
	}

	void setTex(std::string path)
	{
		texture = TextureManager::LoadImage(path);
	}

	void SetRect(int w,int h)
	{
		destRect.w = srcRect.w = w;
		destRect.h = srcRect.h = h;
	}


	void init() override 
	{
		transform = &entity->getComponent<TransformComponent>();

		SDL_QueryTexture(texture, NULL, NULL, &srcRect.w, &srcRect.h);
		destRect.w = srcRect.w;
		destRect.h = srcRect.h;

	}
	void update() override 
	{
		if (animated)
		{
			//srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / speedAnime) % frames % 4);
			//srcRect.y = srcRect.h * static_cast<int>((SDL_GetTicks() / speedAnime) % frames / 4);

			//std::cout << srcRect.x << " " << srcRect.y << " " << srcRect.w << " " << srcRect.h << "\n";

			srcRect.x = srcRect.w * static_cast<int>((SDL_GetTicks() / animSpeed) % frames % 4);
			srcRect.y = srcRect.h * static_cast<int>((SDL_GetTicks() / animSpeed) % frames / 4);

			destRect.x = static_cast<int>(transform->position.x);
			destRect.y = static_cast<int>(transform->position.y);
		}


	}
	
	void draw() override 
	{
		if (full)TextureManager::Draw(texture);
		else TextureManager::Draw(texture,srcRect,destRect);

	}

	void Play(const char* aniName)
	{
		frames = animations[aniName].frame;
		animIndex = animations[aniName].index;
		animSpeed = animations[aniName].speed;
	}
	 
};


#endif // ! SPRIT_COMP_H