#include "ResourceManager.h"
#include <SDL.h>
#include <SDL_image.h>
#include <unordered_map>
#include <stdexcept>

namespace BlockDestroyer {
    ResourceManager::ResourceManager(SDL_Renderer* renderer) : renderer(renderer), textures() { }

    void ResourceManager::releaseResources() {
        for (auto& pair : textures) {
            if (pair.second) {
                SDL_DestroyTexture(pair.second);
            }
        }
        textures.clear();
    }

    SDL_Texture* ResourceManager::getTexture(const std::string& name) const {
        auto it = textures.find(name);
        if (it != textures.end()) {
            return it->second;
        }
        return nullptr;
    }

    SDL_Texture* ResourceManager::loadTexture(const std::string& filePath, const std::string& name) {
        SDL_Texture* texture = IMG_LoadTexture(renderer, filePath.c_str());
        if (!texture) {
            throw std::runtime_error("Texture could not load: " + name);
        }
        else {
            textures[name] = texture;
        }
        return texture;
    }

    ResourceManager::~ResourceManager() {
        releaseResources();
    }
}
