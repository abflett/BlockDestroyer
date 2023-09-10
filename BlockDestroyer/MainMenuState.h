#pragma once
#include "GameState.h"
#include "Game.h"
#include "GameStateManager.h"

#include <SDL.h>


namespace BlockDestroyer {
    class MainMenuState : public GameState {
    public:
        MainMenuState(Game& game, GameStateManager& setGameStateManager);
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
