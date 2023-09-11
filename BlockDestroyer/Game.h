#pragma once
#include "Engine.h"
#include <SDL.h>

namespace BlockDestroyer {
    class Game {
    public:
        Game(Engine& getEngine);
        ~Game();
        void start();
        void quitGame();
        SDL_Renderer* getRenderer() const;
    private:
        int imgInit;
        bool quit;
        SDL_Renderer* renderer;
        Engine& engine;
    };
}