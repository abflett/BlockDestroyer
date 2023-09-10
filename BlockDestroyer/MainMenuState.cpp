#include "MainMenuState.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {
    MainMenuState::MainMenuState(Game& game) : GameState(), game(game) {
        SDL_Log("MainMenuState(SDL_Renderer* renderer)");
    }

    void MainMenuState::handleEvents() {
        // Handle events for the main menu
    }

    void MainMenuState::update() {
        // Update the main menu state
    }

    void MainMenuState::render() {
        // Render the main menu
    }
}