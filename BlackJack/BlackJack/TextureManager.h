#pragma once
#include"Game.h"
#include<map>
#include<utility>

class TextureManager {

private:
	
public:
	static SDL_Texture* LoadImage(std::string file);
	static void Draw(SDL_Texture* tex,SDL_Rect src,SDL_Rect dest);
	static void Draw(SDL_Texture* tex, SDL_Rect dest);
	static void Draw(SDL_Texture* tex);

};


class image_cache {
    std::map<std::string, std::pair<SDL_Texture*,SDL_Surface*>> cache_;
public:
    SDL_Texture* get_image(std::string file) {

        std::map<std::string, std::pair<SDL_Texture*, SDL_Surface*>>::iterator i = cache_.find(file);
        if (i == cache_.end()) {

            SDL_Surface* surf = IMG_Load(file.c_str());
            if (surf != nullptr) {
                SDL_Texture* text = SDL_CreateTextureFromSurface(Game::renderer, surf);
                i = cache_.insert(i, std::make_pair(file, std::make_pair(text, surf)));
            }
            else std::cout << "Cant load Image\n";
        
        }
        return i->second.first;

    }
    void flush() {
        std::map<std::string, std::pair<SDL_Texture*, SDL_Surface*>>::iterator i = cache_.begin();
        for (; i != cache_.end(); ++i)
        {
            SDL_FreeSurface(i->second.second);
        }
        cache_.clear();
    }
    ~image_cache() { flush(); }
};
