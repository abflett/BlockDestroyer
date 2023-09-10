#pragma once
#include "GameState.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {
    class MainMenuState : public GameState {
    public:
        MainMenuState(Game& game);
        void handleEvents() override;
        void update(Uint32 deltaTime) override;
        void render() override;
        void initialize() override;

    private:
        Game& game;
    };
}
