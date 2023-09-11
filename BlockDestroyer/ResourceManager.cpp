// ResourceManager.cpp
#include "ResourceManager.h"
#include <stdexcept>

namespace BlockDestroyer {
    ResourceManager::ResourceManager(SDL_Renderer* renderer) : renderer(renderer) {
        // Load textures during ResourceManager initialization and associate them with names
        textures["ball"] = loadTexture("ball.png", "ball");
        // Load other textures here...
    }

    ResourceManager::~ResourceManager() {
        // Release resources in the destructor
        releaseResources();
    }

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
            SDL_Log("Texture could not load: %s", SDL_GetError());
        }
        else {
            // Store the texture with its associated name
            textures[name] = texture;
        }
        return texture;
    }
}
