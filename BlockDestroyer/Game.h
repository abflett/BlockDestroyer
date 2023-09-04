#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Block.h"
#include "Ball.h"
#include "Paddle.h"

namespace BlockDestroyer {
    class Game {
    public:
        Uint64 lastFrameTime;

        Game();
        void Run();
        ~Game();

    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_Texture* texture;
        SDL_Surface* imageSurface;
        
        Block block;
        Ball ball;
        Paddle paddle;

        bool quit;

        bool intersects(const SDL_Rect& rectA, const SDL_Rect& rectB);
        bool initialize();
        void handleEvents();
        void update();
        void render();
        void cleanUp();
    };
}