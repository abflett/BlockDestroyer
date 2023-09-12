#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>

namespace BlockDestroyer {
    class Ball {
    public:
        Ball(SDL_Texture* texture, SDL_Renderer* newRenderer, glm::i32vec2 bounds);
        void draw();
        void move(Uint64 deltaTime);
        SDL_Rect getBoundingBox() const;

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        SDL_Rect rect;
        glm::vec2 velocity;
        glm::vec2 position;
        glm::i32vec2 bounds;
    };
}
