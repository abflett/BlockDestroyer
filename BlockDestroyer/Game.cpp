#include <SDL.h>
#include <SDL_image.h>
#include "Game.h"
#include "Block.h"
#include "Ball.h"


namespace BlockDestroyer {
	Game::Game() :
		window(nullptr),
		renderer(nullptr),
		quit(false),
		block(20, 20, { 255, 0, 0, 255 }),
		paddle(300),
		ball(0, 0, 0.3212, 0.3413, 10, { 255, 255, 255, 255 }, paddle),
		lastFrameTime(SDL_GetTicks64()),
		texture(nullptr),
		imageSurface(nullptr) {}

	void Game::Run() {
		if (!initialize()) {
			return;
		}

		while (!quit) {
			handleEvents();
			update();
			render();
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

		imageSurface = IMG_Load("brick.png");
		if (!imageSurface) {
			SDL_Log("Image could not load: %s", SDL_GetError());
			SDL_Quit();
		}

		texture = IMG_LoadTexture(renderer, "brick.png");
		if (!texture) {
			SDL_Log("Texture could not load: %s", SDL_GetError());
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

	void Game::handleEvents() {
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

	void Game::update() {
		Uint64 currentTime = SDL_GetTicks64();
		Uint64 deltaTime = currentTime - lastFrameTime;
		lastFrameTime = currentTime;

		ball.move(deltaTime);
		paddle.update(deltaTime);
	}

	void Game::render() {
		// Clear the renderer
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Set the background color (black)
		SDL_RenderClear(renderer);

		block.draw(renderer);
		ball.draw(renderer);
		paddle.draw(renderer);

		SDL_Rect textureRect = { 0, 0, 100, 25 };
		SDL_RenderCopy(renderer, texture, NULL, &textureRect);

		SDL_RenderPresent(renderer);

		SDL_Delay(16);
	}

	void Game::cleanUp() {
		if (imageSurface) {
			SDL_FreeSurface(imageSurface);
		}

		if (texture) {
			SDL_DestroyTexture(texture);
		}

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

