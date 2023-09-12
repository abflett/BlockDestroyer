#include "Game.h"
#include "Engine.h"
#include "GameStateManager.h"

#include "GameSettings.h"

#include <SDL.h>
#include <SDL_image.h>

#include <stdexcept>
#include <thread>

namespace BlockDestroyer {
	Game::Game(Engine& engine) :
		quit(false),
		imgInit(0),
		engine(engine) {
	}

	void Game::quitGame() {
		quit = true;
	}

	GameSettings& Game::getGameSettings()
	{
		return engine.getGameSettings();
	}

	SDL_Texture* Game::getTexture(std::string name) const {
		return engine.getResourceManager().getTexture(name);
	}

	SDL_Texture* Game::loadTexture(std::string file, std::string name) const {
		return engine.getResourceManager().loadTexture(file, name);
	}
	
	SDL_Renderer* Game::getRenderer() const {
		return engine.getRenderer();
	}

	void Game::start() {
		loadTexture("ball.png", "ball");

		GameStateManager gameStateManager(*this);

		Uint32 lastFrameTime = 0;
		int targetFrameTime = static_cast <int>(1000 / engine.getGameSettings().getRefreshRate());
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

