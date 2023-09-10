#include "CollisionUtils.h"

namespace BlockDestroyer {
	bool CollisionUtils::Intersects(const SDL_Rect& rectA, const SDL_Rect& rectB) {
        bool horizontalOverlap = (rectA.x < rectB.x + rectB.w) && (rectB.x < rectA.x + rectA.w);
        bool verticalOverlap = (rectA.y < rectB.y + rectB.h) && (rectB.y < rectA.y + rectA.h);
        return horizontalOverlap && verticalOverlap;
    }
}
