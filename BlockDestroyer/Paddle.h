#pragma once
#include <SDL.h>

namespace BlockDestroyer {
	class Paddle
	{
	public:
		int x;
		static const int width;

		Paddle(int x);
		void draw(SDL_Renderer* renderer);
		void update(Uint64 deltaTime);
		void leftPressed(bool pressed);
		void rightPressed(bool pressed);
		SDL_Rect getBoundingBox() const;

	private:
		static const int height;
		static const int y;

		bool leftIsPressed;
		bool rightIsPressed;
	};
}