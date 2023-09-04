#include "Block.h"

namespace BlockDestroyer {
    Block::Block(int x, int y, SDL_Color color) : x(x), y(y), color(color) {}

    void Block::draw(SDL_Renderer* renderer) {
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = { x, y, width, height };
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_Rect Block::getBoundingBox() const {
        SDL_Rect boundingBox = {x, y, width, height};
        return boundingBox;
    }
}
