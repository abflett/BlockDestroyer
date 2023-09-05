#pragma once
#include <SDL.h>
#include <glm/glm.hpp>
#include "Paddle.h"

namespace BlockDestroyer {
    class Ball {
    public:
        Ball(SDL_Rect initialRect);
        void setRenderer(SDL_Renderer* newRenderer);
        void draw();
        void move(Uint64 deltaTime);
        SDL_Rect getBoundingBox() const;

    private:
        SDL_Renderer* renderer;
        SDL_Rect rect;
        glm::vec2 velocity;
    };
}
