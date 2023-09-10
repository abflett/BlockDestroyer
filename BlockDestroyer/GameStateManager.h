#pragma once
#include "GameState.h"
#include "Game.h"

#include <memory>

namespace BlockDestroyer {
    class GameStateManager {
    public:
        enum class State { MainMenu, Gameplay, GameOver };

        GameStateManager(Game& game);
        void changeState(State newState);
        void handleEvents();
        void update(Uint32 deltaTime);
        void render();

    private:
        Game& game;
        State currentState;
        std::unique_ptr<GameState> currentStatePtr;
    };
}