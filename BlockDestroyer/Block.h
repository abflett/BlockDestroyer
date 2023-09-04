#pragma once
#include <SDL.h>

namespace BlockDestroyer {
    class Block {
    public:
        Block(int x, int y, SDL_Color color);
        void draw(SDL_Renderer* renderer);
        SDL_Rect getBoundingBox() const;

    private:
        int x;
        int y;
        SDL_Color color;
        static const int width = 50;  // Static size
        static const int height = 25; // Static size
    };
}