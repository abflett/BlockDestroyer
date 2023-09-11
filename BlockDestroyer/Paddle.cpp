#include "Paddle.h"
#include "Definitions.h"
#include <SDL.h>

namespace BlockDestroyer {
	const int Paddle::width = 96;
	const int Paddle::height = 16;
	const int Paddle::y = PLAYFIELD_HEIGHT - 40;

	Paddle::Paddle(int x) : x(x), leftIsPressed(false), rightIsPressed(false) {}

	void Paddle::draw(SDL_Renderer* renderer) {
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
		SDL_Rect rect = { x, y, width, height };
		SDL_RenderFillRect(renderer, &rect);;
	}

	SDL_Rect Paddle::getBoundingBox() const {
		SDL_Rect boundingBox = { x, y, width, height };
		return boundingBox;
	}

	void Paddle::rightPressed(bool pressed) {
		rightIsPressed = pressed;
	}

	void Paddle::leftPressed(bool pressed) {
		leftIsPressed = pressed;
	}

	void Paddle::update(Uint64 deltaTime) {

		float speed = 1;

		if (leftIsPressed && x > 0) {
			x += static_cast<int>(-1 * deltaTime);
		}

		if (x < 0) {
			x = 0;
		}

		if (rightIsPressed && x < PLAYFIELD_WIDTH - width) {
			x += static_cast<int>(1 * deltaTime);
		}

		if (x > PLAYFIELD_WIDTH - width) {
			x = PLAYFIELD_WIDTH - width;
		}
	}
}