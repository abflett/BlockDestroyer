#include "Engine.h"
#include "ResourceManager.h"
#include "GameSettings.h"

#include <stdexcept>
#include <string>

namespace BlockDestroyer {
    Engine::Engine() :
        window(nullptr),
        renderer(nullptr),
        resourceManager(nullptr),
        gameSettings(),
        imgInit(0) {

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw std::runtime_error("SDL initialization failed: " + std::string(SDL_GetError()));
        }

        SDL_DisplayMode desktopDisplayMode;
        if (!gameSettings.isInitialized()) {
            if (SDL_GetDesktopDisplayMode(0, &desktopDisplayMode) != 0) {
                throw std::runtime_error("SDL desktop display mode retrieval failed: " + std::string(SDL_GetError()));
            }

            gameSettings.initializeFirstLoad(true, desktopDisplayMode.w, desktopDisplayMode.h, desktopDisplayMode.refresh_rate);
        }

        window = SDL_CreateWindow("Block Destroyer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gameSettings.getScreenWidth(), gameSettings.getScreenHeight(), SDL_WINDOW_SHOWN);
        if (!window) {
            throw std::runtime_error("Window creation failed: " + std::string(SDL_GetError()));
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer) {
            throw std::runtime_error("Renderer creation failed: " + std::string(SDL_GetError()));
        }

        imgInit = IMG_Init(IMG_INIT_PNG);
        if ((imgInit & IMG_INIT_PNG) != IMG_INIT_PNG) {
            throw std::runtime_error("Image initialization failed: " + std::string(SDL_GetError()));
        }

        resourceManager = ResourceManager(renderer);
    }

    void Engine::cleanUp() {
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

    SDL_Renderer* Engine::getRenderer() const {
        return renderer;
    }

    ResourceManager& Engine::getResourceManager() {
        return resourceManager;
    }

    GameSettings& Engine::getGameSettings() {
        return gameSettings;
    }

    Engine::~Engine() {
        cleanUp();
    }
}