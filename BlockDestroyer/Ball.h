#pragma once
#include <SDL.h>
#include "Paddle.h"

namespace BlockDestroyer {
    class Ball {
    public:
        Ball(int x, int y, float speedX, float speedY, int size, SDL_Color startColor, Paddle& paddle);
        void draw(SDL_Renderer* renderer);
        void move(Uint64 deltaTime);
        SDL_Rect getBoundingBox() const;

    private:
        int x;
        int y;
        float speedX;
        float speedY;
        int size;
        SDL_Color color;
        Paddle& paddle;
    };
}
