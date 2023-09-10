#pragma once
#include <SDL_rect.h>

namespace BlockDestroyer {
    class CollisionUtils {
    public:
        static bool Intersects(const SDL_Rect& rectA, const SDL_Rect& rectB);
    };
}