#pragma once

#include"TextureManager.h"

class TextManager : public TextureManager 
{

private:
	
public:
	static SDL_Texture* LoadText(std::string text, int size = 25, SDL_Color color = { 255,255,255 });
	static SDL_Texture* LoadImage(std::string file) = delete;
};



class text_cache {
    using Value = std::pair<SDL_Texture*, SDL_Surface*>;
    std::map<std::string, Value> cache_;
public:

    SDL_Texture* get_image(std::string text, int size, SDL_Color color) {

        std::map<std::string, Value>::iterator i = cache_.find(text);
        if (i == cache_.end()) {

            TTF_Font* sans = TTF_OpenFont("assets/Fonts/Blackjack.ttf", size);

            SDL_Surface* surf = TTF_RenderText_Solid(sans, text.c_str(), color);
            if (surf != nullptr) {
                SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, surf);
                i = cache_.insert(i, std::make_pair(text, std::make_pair(texture, surf)));
            }
            else std::cout << "Cant load Image\n";
            

        }
        return i->second.first;

    }
    void flush() {
        std::map<std::string, Value>::iterator i = cache_.begin();
        for (; i != cache_.end(); ++i)
        {
            SDL_FreeSurface(i->second.second);
        }
        cache_.clear();
    }
    ~text_cache() { flush(); }
};
