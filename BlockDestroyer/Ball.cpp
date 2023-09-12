#include "Ball.h"

#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>

namespace BlockDestroyer {
    Ball::Ball(SDL_Texture* getTexture, SDL_Renderer* newRenderer, glm::i32vec2 bounds) :
        renderer(newRenderer),
        texture(getTexture),
        rect(),
        velocity({ 0.3113f, -0.3332f }), 
        bounds(bounds),
        position({ bounds.x / 2, bounds.y / 2 }) {

        // set ball size and position
        rect = { static_cast<int>(position.x), static_cast<int>(position.y), 0, 0 };
        SDL_QueryTexture(texture, NULL, NULL, &rect.w, &rect.h);
        
    }

    void Ball::draw() {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }

    SDL_Rect Ball::getBoundingBox() const {
        return rect;
    }

    void Ball::move(Uint64 deltaTime) {
        if (position.x > bounds.x - rect.w) {
            velocity.x *= -1;
            position.x = bounds.x - rect.w;
        }

        if (position.x < 0) {
            velocity.x *= -1;
            position.x = 0;
        }

        if (position.y > bounds.y - rect.w) {
            velocity.y *= -1;
            position.y = bounds.y - rect.w;
        }

        if (position.y < 0) {
            velocity.y *= -1;
            position.y = 0;
        }

        position.x += velocity.x * deltaTime;
        position.y += velocity.y * deltaTime;

        rect.x = static_cast<int>(position.x);
        rect.y = static_cast<int>(position.y);
    }
}
