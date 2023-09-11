#pragma once
#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_image.h>

namespace BlockDestroyer {
    class Engine {
    public:
        Engine();
        ~Engine();

        void cleanUp();
        SDL_Renderer* getRenderer() const;
        SDL_DisplayMode getDesktopDisplayMode() const;
        ResourceManager& getResourceManager(); // Add a getter for the ResourceManager

    private:
        int windowWidth;
        int windowHeight;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_DisplayMode desktopDisplayMode;
        ResourceManager resourceManager;
        int imgInit;
    };
}