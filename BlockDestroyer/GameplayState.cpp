#include "GameplayState.h"
#include "GameState.h"
#include "Paddle.h"
#include "Block.h"
#include "Ball.h"
#include "Game.h"
#include "GameStateManager.h"
#include "GameSettings.h"

#include <SDL.h>

namespace BlockDestroyer {
	GameplayState::GameplayState(Game& game, GameStateManager& setGameStateManager) :
		renderer(game.getRenderer()),
		game(game),
		gameStateManager(setGameStateManager),
		gameplayTexture(nullptr),
		gameSettings(game.getGameSettings()),
		block({ 20, 20, 48, 16 }, { 255, 0, 0, 255 }),
		paddle(300),
		ball(game.getTexture("ball"), renderer) {

		gameplayTexture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, gameSettings.getPlayfieldWidth(), gameSettings.getPlayfieldHeight());
		if (gameplayTexture == nullptr) {
			SDL_Log("Failed to create gameplay texture: %s", SDL_GetError());
		}
	}

	void GameplayState::initialize() {
		SDL_Log("GameplayState initialize()");
	}

	void GameplayState::handleEvents() {
		SDL_Event event;
		while (SDL_PollEvent(&event) != 0) {
			if (event.type == SDL_QUIT) {
				game.quitGame();
			}
			else if (event.type == SDL_KEYDOWN) {
				if (event.key.keysym.scancode == SDL_SCANCODE_LEFT) {
					paddle.leftPressed(true);
				}

				if (event.key.keysym.scancode == SDL_SCANCODE_RIGHT) {
					paddle.rightPressed(true);
				}

				if (event.key.keysym.scancode == SDL_SCANCODE_BACKSPACE) {
					gameStateManager.changeState(GameStateManager::State::GameOver);
				}

				if (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
					game.quitGame();
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
		const int screenWidth = gameSettings.getScreenWidth();
		const int screenHeight = gameSettings.getScreenHeight();
		const int gameWidth = gameSettings.getGameWidth();
		const int gameHeight = gameSettings.getGameHeight();
		const int playfieldWidth = gameSettings.getPlayfieldWidth();
		const int playfieldHeight = gameSettings.getPlayfieldHeight();

		SDL_SetRenderTarget(renderer, gameplayTexture);

		SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
		SDL_RenderClear(renderer);

		block.draw(renderer);
		ball.draw();
		paddle.draw(renderer);

		SDL_SetRenderTarget(renderer, nullptr);

		float scaleX = static_cast<float>(screenWidth) / static_cast<float>(gameWidth);
		float scaleY = static_cast<float>(screenHeight) / static_cast<float>(gameHeight);

		// Choose the smaller scaling factor to ensure the entire playfield fits on the screen
		float scale = std::min(scaleX, scaleY);

		// Calculate the scaled width and height of the screen rectangle
		int scaledWidth = static_cast<int>(playfieldWidth * scale);
		int scaledHeight = static_cast<int>(playfieldHeight * scale);

		// Calculate the position to center the gameplayTexture on the screen
		SDL_Rect screen{
			(screenWidth != scaledWidth) ? (screenWidth - scaledWidth) / 2 : 0,
			(screenHeight != scaledHeight) ? (screenHeight - scaledHeight) / 2 : 0,
			scaledWidth,
			scaledHeight
		};

		SDL_RenderCopy(renderer, gameplayTexture, nullptr, &screen);

		SDL_RenderPresent(renderer);
	}
}
