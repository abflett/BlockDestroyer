#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <glm/glm.hpp>

namespace BlockDestroyer {
    class Ball {
    public:
        Ball(SDL_Renderer* newRenderer, SDL_Rect initialRect);
        ~Ball();
        void draw();
        void move(Uint64 deltaTime);
        SDL_Rect getBoundingBox() const;

    private:
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        SDL_Rect rect;
        glm::vec2 velocity;
    };
}
