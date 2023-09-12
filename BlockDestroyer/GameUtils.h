#pragma once
#include <SDL_rect.h>

namespace BlockDestroyer {
    class GameUtils {
    public:
        static bool Intersects(const SDL_Rect& rectA, const SDL_Rect& rectB);
    };
}