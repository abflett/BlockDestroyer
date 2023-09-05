#pragma once
#include <SDL.h>
#include "GameState.h"
#include "Paddle.h"
#include "Block.h"
#include "Ball.h"

namespace BlockDestroyer {
    class GameplayState : public GameState {
    public:
        GameplayState(SDL_Renderer* existingRenderer);
        void handleEvents() override;
        void update() override;
        void render() override;

    private:
        SDL_Renderer* renderer;
        bool quit;
        Uint64 lastFrameTime;
        Block block;
        Ball ball;
        Paddle paddle;
    };
}