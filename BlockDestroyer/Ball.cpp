// Ball.cpp
#include "Ball.h"

namespace BlockDestroyer {
    Ball::Ball(SDL_Renderer* newRenderer, SDL_Rect initialRect) : 
        renderer(newRenderer),
        texture(nullptr),
        rect(initialRect),
        velocity({ 0.3113f, 0.3332f }) {

        texture = IMG_LoadTexture(renderer, "ball.png");
        if (!texture) {
            SDL_Log("Texture could not load: %s", SDL_GetError());
        }
    }

    void Ball::draw() {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
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

    Ball::~Ball() {
        if (texture) {
            SDL_DestroyTexture(texture);
        }
    }
}
