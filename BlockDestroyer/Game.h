#pragma once
#include "Engine.h"
#include <SDL.h>
#include <string>

namespace BlockDestroyer {
    class Game {
    public:
        Game(Engine& getEngine);
        ~Game();
        void start();
        void quitGame();
        SDL_Renderer* getRenderer() const;
        SDL_Texture* getTexture(std::string name) const;
        SDL_Texture* loadTexture(std::string file, std::string name) const;
    private:
        int imgInit;
        bool quit;
        Engine& engine;
    };
}