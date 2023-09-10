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
		quit(false) {

		if (SDL_Init(SDL_INIT_VIDEO) < 0) {
			throw std::runtime_error("SDL initialization failed");
		}

		window = SDL_CreateWindow("Block Destroyer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
		if (!window) {
			throw std::runtime_error("Window creation failed");
		}

		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
		if (!renderer) {
			throw std::runtime_error("Renderer creation failed");
		}

		int imgInit = IMG_Init(IMG_INIT_PNG);
		if ((imgInit & IMG_INIT_PNG) != IMG_INIT_PNG) {
			throw std::runtime_error("Image initialization failed");
		}
	}

	void Game::quitGame() {
		quit = true;
	}

	SDL_Renderer* Game::getRenderer() const {
		return renderer;
	}

	void Game::run() {
		GameStateManager gameStateManager(*this);
		gameStateManager.changeState(GameStateManager::State::Gameplay);

		while (!quit) {
			gameStateManager.handleEvents();
			gameStateManager.update();
			gameStateManager.render();
		}
	}

	bool Game::intersects(const SDL_Rect& rectA, const SDL_Rect& rectB) {
		bool horizontalOverlap = (rectA.x < rectB.x + rectB.w) && (rectB.x < rectA.x + rectA.w);// Check for horizontal overlap
		bool verticalOverlap = (rectA.y < rectB.y + rectB.h) && (rectB.y < rectA.y + rectA.h);// Check for vertical overlap
		return horizontalOverlap && verticalOverlap;
	}

	void Game::cleanUp() {
		if (IMG_Init(0) < 1) {
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

