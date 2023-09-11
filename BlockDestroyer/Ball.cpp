#include "Ball.h"
#include "Definitions.h"

#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>

namespace BlockDestroyer {
    Ball::Ball(SDL_Texture* getTexture, SDL_Renderer* newRenderer) :
        renderer(newRenderer),
        texture(getTexture),
        rect(),
        velocity({ 0.3113f, -0.3332f }), 
        position({ PLAYFIELD_WIDTH / 2, PLAYFIELD_HEIGHT / 2 }) {

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
        if (position.x > PLAYFIELD_WIDTH - rect.w) {
            velocity.x *= -1;
            position.x = PLAYFIELD_WIDTH - rect.w;
        }

        if (position.x < 0) {
            velocity.x *= -1;
            position.x = 0;
        }

        if (position.y > PLAYFIELD_HEIGHT - rect.w) {
            velocity.y *= -1;
            position.y = PLAYFIELD_HEIGHT - rect.w;
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
