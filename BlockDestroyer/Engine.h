#pragma once

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

    private:
        int windowWidth;
        int windowHeight;
        SDL_Window* window;
        SDL_Renderer* renderer;
        SDL_DisplayMode desktopDisplayMode;
        int imgInit;
    };
}