#include "Engine.h"
#include "ResourceManager.h"

#include <stdexcept>
#include <string>

namespace BlockDestroyer {
    Engine::Engine() :
        windowWidth(0),
        windowHeight(0),
        window(nullptr),
        renderer(nullptr),
        desktopDisplayMode(),
        resourceManager(nullptr),
        imgInit(0) {

        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            throw std::runtime_error("SDL initialization failed: " + std::string(SDL_GetError()));
        }

        if (SDL_GetDesktopDisplayMode(0, &desktopDisplayMode) != 0) {
            throw std::runtime_error("SDL desktop display mode retrieval failed: " + std::string(SDL_GetError()));
        }

        window = SDL_CreateWindow("Block Destroyer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, desktopDisplayMode.w, desktopDisplayMode.h, SDL_WINDOW_SHOWN);
        if (!window) {
            throw std::runtime_error("Window creation failed: " + std::string(SDL_GetError()));
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
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

    SDL_DisplayMode Engine::getDesktopDisplayMode() const {
        return desktopDisplayMode;
    }

    ResourceManager& Engine::getResourceManager() {
        return resourceManager;
    }

    Engine::~Engine() {
        cleanUp();
    }
}