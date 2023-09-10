#pragma once
#include <SDL.h>

namespace BlockDestroyer {
    class Game {
    public:
        Game();
        ~Game();
        void start();
        void quitGame();
        SDL_Renderer* getRenderer() const;
    private:
        int imgInit;
        bool quit;
        SDL_Window* window;
        SDL_Renderer* renderer;
        
        void cleanUp();
    };
}