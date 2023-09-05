#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Block.h"
#include "Ball.h"
#include "Paddle.h"

namespace BlockDestroyer {
    class Game {
    public:
        Game();
        void Run();
        ~Game();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        bool quit;

        bool intersects(const SDL_Rect& rectA, const SDL_Rect& rectB);
        bool initialize();
        void cleanUp();
    };
}