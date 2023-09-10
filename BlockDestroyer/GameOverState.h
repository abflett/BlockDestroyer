#pragma once
#include "Game.h"
#include "GameState.h"

#include <SDL.h>

namespace BlockDestroyer {
    class GameOverState : public GameState {
    public:
        GameOverState(Game& game);
        void handleEvents() override;
        void update(Uint32 deltaTime) override;
        void render() override;
        void initialize() override;

    private:
        Game& game;
    };
}
