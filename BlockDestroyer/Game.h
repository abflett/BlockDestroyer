#pragma once
#include "Engine.h"
#include "GameSettings.h"
#include <SDL.h>
#include <string>

namespace BlockDestroyer {
    class Game {
    public:
        Game(Engine& engine);
        ~Game();
        void start();
        void quitGame();
        SDL_Renderer* getRenderer() const;
        SDL_Texture* getTexture(std::string name) const;
        SDL_Texture* loadTexture(std::string file, std::string name) const;
        GameSettings& getGameSettings();
    private:
        int imgInit;
        bool quit;
        Engine& engine;
    };
}