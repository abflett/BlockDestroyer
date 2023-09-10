#pragma once
#include "Game.h"
#include "GameState.h"

namespace BlockDestroyer {
    class GameOverState : public GameState {
    public:
        GameOverState(Game& game);
        void handleEvents() override;
        void update() override;
        void render() override;

    private:
        Game& game;
    };
}
