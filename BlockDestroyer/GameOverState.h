#pragma once
#include <SDL.h>
#include "GameState.h"

namespace BlockDestroyer {
    class GameOverState : public GameState {
    public:
        GameOverState(SDL_Renderer* renderer);
        void handleEvents() override;
        void update() override;
        void render() override;

    private:
        SDL_Renderer* renderer;
    };
}
