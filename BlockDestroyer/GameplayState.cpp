#include "GameplayState.h"
#include "GameState.h"
#include "Paddle.h"
#include "Block.h"
#include "Ball.h"
#include "Game.h"

#include <SDL.h>

namespace BlockDestroyer {
	GameplayState::GameplayState(Game& game) :
		renderer(game.getRenderer()),
		game(game),
		quit(false),
		block({ 20, 20, 50, 30 }, { 255, 0, 0, 255 }),
		paddle(300),
		ball(renderer, { 400, 300, 16, 16 }) {
		SDL_Log("GameplayState");
	}

	void GameplayState::handleEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				game.quitGame();
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

	void GameplayState::update(Uint32 deltaTime) {
		ball.move(deltaTime);
		paddle.update(deltaTime);
	}

	void GameplayState::render() {
		int rate = 165 / 1000;
		
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set the background color (black)
		SDL_RenderClear(renderer);

		block.draw(renderer);
		ball.draw();
		paddle.draw(renderer);

		SDL_RenderPresent(renderer);
	}
}
