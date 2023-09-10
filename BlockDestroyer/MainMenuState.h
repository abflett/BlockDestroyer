#pragma once
#include "GameState.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {
    class MainMenuState : public GameState {
    public:
        MainMenuState(Game& game);
        void handleEvents() override;
        void update() override;
        void render() override;

    private:
        Game& game;
    };
}
