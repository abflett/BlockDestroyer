#pragma once
#include <memory>
#include "GameState.h"
#include "Ball.h" // Include any other necessary headers for game objects

namespace BlockDestroyer {
    class GameStateManager {
    public:
        enum class State { MainMenu, Gameplay, GameOver };

        GameStateManager(SDL_Renderer* renderer);
        void changeState(State newState);
        void handleEvents();
        void update();
        void render();

    private:
        State currentState;
        std::unique_ptr<GameState> currentStatePtr;
        SDL_Renderer* renderer;
    };
}