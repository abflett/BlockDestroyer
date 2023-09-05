#include "Block.h"

namespace BlockDestroyer {
    Block::Block(SDL_Rect initialRect, SDL_Color color) : rect(initialRect), color(color) {}

    void Block::draw(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_Rect Block::getBoundingBox() const {
        return rect;
    }
}
