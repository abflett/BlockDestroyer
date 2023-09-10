#pragma once
#include "Game.h"
#include "GameState.h"
#include "GameStateManager.h"

#include <SDL.h>

namespace BlockDestroyer {
    class GameOverState : public GameState {
    public:
        GameOverState(Game& game, GameStateManager& setGameStateManager);
        void handleEvents() override;
        void update(Uint32 deltaTime) override;
        void render() override;
        void initialize() override;

    private:
        SDL_Renderer* renderer;
        Game& game;
        GameStateManager& gameStateManager;
    };
}
