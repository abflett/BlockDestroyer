#include "GameStateManager.h"
#include "GameplayState.h"
#include "GameOverState.h"
#include "MainMenuState.h"

namespace BlockDestroyer {
    GameStateManager::GameStateManager(SDL_Renderer* renderer) : currentState(State::Gameplay), renderer(renderer) {}

    void GameStateManager::changeState(State newState) {
        currentState = newState;

        switch (currentState) {
        case State::MainMenu:
            currentStatePtr = std::make_unique<MainMenuState>(renderer);
            break;
        case State::Gameplay:
            currentStatePtr = std::make_unique<GameplayState>(renderer);
            break;
        case State::GameOver:
            currentStatePtr = std::make_unique<GameOverState>(renderer);
            break;
        }
    }

    void GameStateManager::handleEvents() {
        currentStatePtr->handleEvents();
    }

    void GameStateManager::update() {
        currentStatePtr->update();
    }

    void GameStateManager::render() {
        currentStatePtr->render();
    }
}
