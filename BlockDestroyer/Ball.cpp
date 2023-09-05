// Ball.cpp
#include "Ball.h"

namespace BlockDestroyer {
    Ball::Ball(SDL_Rect initialRect) : renderer(nullptr), rect(initialRect), velocity({ 0.3113f, 0.3332f }) {}

    void Ball::setRenderer(SDL_Renderer* newRenderer) {
        renderer = newRenderer;
    }

    void Ball::draw() {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_Rect Ball::getBoundingBox() const {
        return rect;
    }

    void Ball::move(Uint64 deltaTime) {
        if (rect.x > 800 - rect.w) {
            velocity.x *= -1;
            rect.x = 800 - rect.w;
        }

        if (rect.x < 0) {
            velocity.x *= -1;
            rect.x = 0;
        }

        if (rect.y > 600 - rect.w) {
            velocity.y *= -1;
            rect.y = 600 - rect.w;
        }

        if (rect.y < 0) {
            velocity.y *= -1;
            rect.y = 0;
        }

        rect.x += static_cast<int>(velocity.x * deltaTime);
        rect.y += static_cast<int>(velocity.y * deltaTime);
    }
}
