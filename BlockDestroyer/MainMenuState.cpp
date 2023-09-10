#include "MainMenuState.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {
    MainMenuState::MainMenuState(Game& game, GameStateManager& setGameStateManager) :
        renderer(game.getRenderer()),
        game(game),
        gameStateManager(setGameStateManager) { }

    void MainMenuState::initialize() {
        SDL_Log("MainMenuState initialize()");
    }

    void MainMenuState::handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                game.quitGame();
            }
            else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) {
                    // Right arrow key is pressed, handle it here
                    gameStateManager.changeState(GameStateManager::State::Gameplay);

                }
            }
        }
    }

    void MainMenuState::update(Uint32 deltaTime) {
        // Update the main menu state
    }

    void MainMenuState::render() {
        // Render the main menu
    }
}