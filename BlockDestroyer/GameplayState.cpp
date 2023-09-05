#include "GameplayState.h"

namespace BlockDestroyer {
	GameplayState::GameplayState(SDL_Renderer* existingRenderer) :
		renderer(existingRenderer),
		quit(false),
		block({ 20, 20, 50, 30 }, { 255, 0, 0, 255 }),
		paddle(300),
		ball({ 400, 300, 16, 16 }),
		lastFrameTime(SDL_GetTicks64()) {
		SDL_Log("GameplayState(SDL_Renderer* renderer)");
	}

	void GameplayState::handleEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				quit = true;
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
					// Left arrow key is pressed, handle it here
					paddle.leftPressed(true);
				}

				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
					// Right arrow key is pressed, handle it here
					paddle.rightPressed(true);
				}
			}

			else if (event.type == SDL_KEYUP) {
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
					// Left or right arrow key is released, stop moving the paddle
					paddle.leftPressed(false);
				}

				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
					// Left or right arrow key is released, stop moving the paddle
					paddle.rightPressed(false);
				}
			}
		}
	}

	void GameplayState::update() {
		Uint64 currentTime = SDL_GetTicks64();
		Uint64 deltaTime = currentTime - lastFrameTime;
		lastFrameTime = currentTime;

		ball.move(deltaTime);
		paddle.update(deltaTime);
	}

	void GameplayState::render() {
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set the background color (black)
		SDL_RenderClear(renderer);

		block.draw(renderer);
		ball.draw();
		paddle.draw(renderer);

		SDL_RenderPresent(renderer);
		SDL_Delay(16);
	}
}
