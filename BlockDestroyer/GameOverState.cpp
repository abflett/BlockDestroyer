#include "GameOverState.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {

    GameOverState::GameOverState(Game& game) : game(game) {
        SDL_Log("GameOverState(SDL_Renderer* renderer");
    }

    void GameOverState::handleEvents() {
        // Handle events for the game over state
    }

    void GameOverState::update(Uint32 deltaTime) {
        // Update the game over state
    }

    void GameOverState::render() {
        // Render the game over state
    }
}
