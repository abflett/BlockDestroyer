// Ball.cpp
#include "Ball.h"

namespace BlockDestroyer {
    Ball::Ball(int x, int y, float speedX, float speedY, int size, SDL_Color color, Paddle& paddle)
        : x(x), y(y), speedX(speedX), speedY(speedY), size(size), color(color), paddle(paddle) {}


    void Ball::draw(SDL_Renderer* renderer) {
        // Render the ball
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
        SDL_Rect rect = { x, y, size, size };
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_Rect Ball::getBoundingBox() const {
        SDL_Rect boundingBox = {x, y, size, size};
        return boundingBox;
    }

    void Ball::move(Uint64 deltaTime) {

        int xPos = paddle.x;

        if (x > 800 - size)
        {
            speedX *= -1;
            x = 800 - size;
        }

        if (x < 0)
        {
            speedX *= -1;
            x = 0;
        }

        if (y > 600 - size)
        {
            speedY *= -1;
            y = 600 - size;
        }

        if (y < 0)
        {
            speedY *= -1;
            y = 0;
        }

        x += static_cast<int>(speedX * deltaTime);
        y += static_cast<int>(speedY * deltaTime);
    }
}
