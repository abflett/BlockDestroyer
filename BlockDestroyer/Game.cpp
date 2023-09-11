#include "Game.h"
#include "Engine.h"
#include "GameStateManager.h"
#include "Definitions.h"

#include <SDL.h>
#include <SDL_image.h>

#include <stdexcept>
#include <thread>

namespace BlockDestroyer {
	Game::Game(Engine& getEngine) :
		quit(false),
		imgInit(0),
		renderer(getEngine.getRenderer()),
		engine(getEngine) {
	}

	void Game::quitGame() {
		quit = true;
	}

	SDL_Renderer* Game::getRenderer() const {
		return renderer;
	}

	void Game::start() {
		GameStateManager gameStateManager(*this);

		Uint32 lastFrameTime = 0;

		while (!quit) {
			Uint32 currentTime = SDL_GetTicks();
			Uint32 deltaTime = currentTime - lastFrameTime;
			lastFrameTime = currentTime;


			gameStateManager.handleEvents();
			gameStateManager.update(deltaTime);
			gameStateManager.render();

			// Cap the frame rate by delaying if necessary
			Uint32 frameTime = SDL_GetTicks() - currentTime;
			if (frameTime < targetFrameTime) {
				SDL_Delay(targetFrameTime - frameTime);
			}
		}
	}

	Game::~Game() {
	}
}

