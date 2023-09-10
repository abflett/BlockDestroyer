#include "GameStateManager.h"
#include "GameplayState.h"
#include "GameOverState.h"
#include "MainMenuState.h"
#include "GameState.h"
#include "Game.h"

#include <memory>

namespace BlockDestroyer {
    GameStateManager::GameStateManager(Game& game) : currentState(State::Gameplay), game(game) {}

    void GameStateManager::changeState(State newState) {
        currentState = newState;

        switch (currentState) {
        case State::MainMenu:
            currentStatePtr = std::make_unique<MainMenuState>(game);
            break;
        case State::Gameplay:
            currentStatePtr = std::make_unique<GameplayState>(game);
            break;
        case State::GameOver:
            currentStatePtr = std::make_unique<GameOverState>(game);
            break;
        }
    }

    void GameStateManager::handleEvents() {
        currentStatePtr->handleEvents();
    }

    void GameStateManager::update(Uint32 deltaTime) {
        currentStatePtr->update(deltaTime);
    }

    void GameStateManager::render() {
        currentStatePtr->render();
    }
}
