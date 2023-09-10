#include "MainMenuState.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {
    MainMenuState::MainMenuState(Game& game) : GameState(), game(game) { }

    void MainMenuState::initialize() {
        SDL_Log("MainMenuState initialize()");
    }

    void MainMenuState::handleEvents() {
        // Handle events for the main menu
    }

    void MainMenuState::update(Uint32 deltaTime) {
        // Update the main menu state
    }

    void MainMenuState::render() {
        // Render the main menu
    }
}