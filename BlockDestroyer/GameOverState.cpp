#include "GameOverState.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {

    GameOverState::GameOverState(Game& game, GameStateManager& setGameStateManager) :
        renderer(game.getRenderer()),
        game(game),
        gameStateManager(setGameStateManager) { }

    void GameOverState::initialize() {
        SDL_Log("GameOverState initialize()");
    }

    void GameOverState::handleEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				game.quitGame();
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) {
					// Right arrow key is pressed, handle it here
					gameStateManager.changeState(GameStateManager::State::MainMenu);

				}
			}
		}
    }

    void GameOverState::update(Uint32 deltaTime) {
        // Update the game over state
    }

    void GameOverState::render() {
		SDL_SetRenderDrawColor(renderer, 122, 0, 0, 255); // Set the background color (black)
		SDL_RenderClear(renderer);

		SDL_RenderPresent(renderer);
    }
}
