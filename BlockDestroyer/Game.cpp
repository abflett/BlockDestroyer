#include "Game.h"
#include "GameStateManager.h"
#include "Definitions.h"

#include <SDL.h>
#include <SDL_image.h>

#include <stdexcept>
#include <thread>

namespace BlockDestroyer {
	Game::Game() :
		quit(false),
		imgInit(0),
		window(nullptr),
		renderer(nullptr) {

		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			throw std::runtime_error("SDL initialization failed: " + std::string(SDL_GetError()));
		}

		window = SDL_CreateWindow("Block Destroyer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (!window) {
			throw std::runtime_error("Window creation failed: " + std::string(SDL_GetError()));
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!renderer) {
			throw std::runtime_error("Renderer creation failed: " + std::string(SDL_GetError()));
		}

		imgInit = IMG_Init(IMG_INIT_PNG);
		if ((imgInit & IMG_INIT_PNG) != IMG_INIT_PNG) {
			throw std::runtime_error("Image initialization failed" + std::string(SDL_GetError()));
		}
	}

	void Game::quitGame() {
		quit = true;
	}

	SDL_Renderer* Game::getRenderer() const {
		return renderer;
	}

	void Game::start() {
		GameStateManager gameStateManager(*this);
		gameStateManager.changeState(GameStateManager::State::Gameplay);

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

	void Game::cleanUp() {
		if (imgInit > 0) {
			IMG_Quit();
		}

		if (renderer) {
			SDL_DestroyRenderer(renderer);
		}

		if (window) {
			SDL_DestroyWindow(window);
		}

		SDL_Quit();
	}

	Game::~Game() {
		cleanUp();
	}
}

