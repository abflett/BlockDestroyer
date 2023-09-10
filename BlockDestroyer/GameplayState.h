#pragma once
#include "GameState.h"
#include "Paddle.h"
#include "Block.h"
#include "Ball.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {
    class GameplayState : public GameState {
    public:
        GameplayState(Game& game);
        void handleEvents() override;
        void update(Uint32 deltaTime) override;
        void render() override;

    private:
        SDL_Renderer* renderer;
        bool quit;
        Block block;
        Ball ball;
        Paddle paddle;
        Game& game;
    };
}