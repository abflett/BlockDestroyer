#pragma once
#include <SDL.h>

namespace BlockDestroyer {
    class Block {
    public:
        Block(SDL_Rect initialRect, SDL_Color color);
        void draw(SDL_Renderer* renderer);
        SDL_Rect getBoundingBox() const;

    private:
        SDL_Rect rect;
        SDL_Color color;
    };
}