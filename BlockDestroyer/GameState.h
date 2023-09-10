#pragma once
#include <SDL.h>

namespace BlockDestroyer {
    class GameState {
    public:
        virtual void handleEvents() = 0;
        virtual void update(Uint32 deltaTime) = 0;
        virtual void render() = 0;
        virtual void initialize() = 0;
    };
}