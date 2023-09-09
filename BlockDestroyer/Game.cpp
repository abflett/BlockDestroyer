#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "Block.h"
#include "Ball.h"
#include "GameStateManager.h"
#include "MainMenuState.h"
#include "GameplayState.h"


namespace BlockDestroyer {
	Game::Game() :
		window(nullptr),
		renderer(nullptr),
		quit(false) {}

	void Game::quitGame() {
		quit = true;
	}

	SDL_Renderer* Game::getRenderer() const {
		return renderer;
	}

	void Game::run() {
		if (!initialize()) {
			return;
		}

		GameStateManager gameStateManager(*this);
		gameStateManager.changeState(GameStateManager::State::Gameplay);

		while (!quit) {
			gameStateManager.handleEvents();
			gameStateManager.update();
			gameStateManager.render();
		}
	}

	bool Game::initialize() {
		SDL_Log("Logging: Initialize()");

		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			SDL_Log("SDL initialization failed: %s", SDL_GetError());
			return false;
		}

		window = SDL_CreateWindow("Block Destroyer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
		if (!window) {
			SDL_Log("Window creation failed: %s", SDL_GetError());
			SDL_Quit();
			return false;
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!renderer) {
			SDL_Log("Renderer creation failed: %s", SDL_GetError());
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}

		int imgInit = IMG_Init(IMG_INIT_PNG);
		if((imgInit & IMG_INIT_PNG) != IMG_INIT_PNG) {
			SDL_Log("Image initialization failed: %s", SDL_GetError());
			SDL_DestroyWindow(window);
			SDL_Quit();

		}

		return true;
	}

	bool Game::intersects(const SDL_Rect& rectA, const SDL_Rect& rectB) {
		// Check for horizontal overlap
		bool horizontalOverlap = (rectA.x < rectB.x + rectB.w) && (rectB.x < rectA.x + rectA.w);

		// Check for vertical overlap
		bool verticalOverlap = (rectA.y < rectB.y + rectB.h) && (rectB.y < rectA.y + rectA.h);

		// Return true if both horizontal and vertical overlap
		return horizontalOverlap && verticalOverlap;
	}

	void Game::cleanUp() {
		IMG_Quit();

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

