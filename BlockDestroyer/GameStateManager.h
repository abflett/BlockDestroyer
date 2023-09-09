#pragma once
#include <memory>
#include "GameState.h"
#include "Ball.h" // Include any other necessary headers for game objects
#include "Game.h"

namespace BlockDestroyer {
    class GameStateManager {
    public:
        enum class State { MainMenu, Gameplay, GameOver };

        GameStateManager(Game& game);
        void changeState(State newState);
        void handleEvents();
        void update();
        void render();

    private:
        Game& game;
        State currentState;
        std::unique_ptr<GameState> currentStatePtr;
    };
}