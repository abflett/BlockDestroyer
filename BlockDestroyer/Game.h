#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Block.h"
#include "Ball.h"
#include "Paddle.h"
#include "Definitions.h"
#include <stdexcept>

namespace BlockDestroyer {
    class Game {
    public:
        Game();
        ~Game();
        void run();
        void quitGame();
        SDL_Renderer* getRenderer() const;
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        bool quit;

        bool intersects(const SDL_Rect& rectA, const SDL_Rect& rectB);
        void cleanUp();
    };
}