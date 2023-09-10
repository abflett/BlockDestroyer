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
        bool quit;
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        
        void cleanUp();
    };
}