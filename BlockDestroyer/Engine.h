#pragma once
#include "ResourceManager.h"
#include "GameSettings.h"
#include <SDL.h>
#include <SDL_image.h>


namespace BlockDestroyer {
    class Engine {
    public:
        Engine();
        ~Engine();

        void cleanUp();
        SDL_Renderer* getRenderer() const;
        ResourceManager& getResourceManager(); // Add a getter for the ResourceManager
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        ResourceManager resourceManager;
        GameSettings gameSettings;

        int imgInit;
    };
}