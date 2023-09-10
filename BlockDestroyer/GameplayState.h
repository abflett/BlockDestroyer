#pragma once
#include "GameState.h"
#include "Paddle.h"
#include "Block.h"
#include "Ball.h"
#include "Game.h"
#include "GameStateManager.h"

#include <SDL.h>

namespace BlockDestroyer {
    class GameplayState : public GameState {
    public:
        GameplayState(Game& game, GameStateManager& setGameStateManager);
        void handleEvents() override;
        void update(Uint32 deltaTime) override;
        void render() override;
        void initialize() override;

    private:
        SDL_Renderer* renderer;
        GameStateManager& gameStateManager;
        Game& game;
        SDL_Texture* gameplayTexture;
        Block block;
        Ball ball;
        Paddle paddle;
    };
}