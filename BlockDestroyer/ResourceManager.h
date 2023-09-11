#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <string>

namespace BlockDestroyer {
    class ResourceManager {
    public:
        ResourceManager(SDL_Renderer* renderer);
        ~ResourceManager();

        SDL_Texture* getTexture(const std::string& name) const;
        SDL_Texture* loadTexture(const std::string& filePath, const std::string& name);

        void releaseResources();
    private:
        SDL_Renderer* renderer;
        std::unordered_map<std::string, SDL_Texture*> textures;
    };
}
