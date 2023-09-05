#pragma once
#include "GameState.h"
#include <SDL.h>

namespace BlockDestroyer {
    class MainMenuState : public GameState {
    public:
        MainMenuState(SDL_Renderer* renderer);
        void handleEvents() override;
        void update() override;
        void render() override;

    private:
        SDL_Renderer* renderer;
    };
}
