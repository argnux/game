//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "TextureStorage.h"
#include "RendererWindow.h"
#include "Log.h"

namespace Game {
    const std::string TextureStorage::RESOURCE_PATH{std::string(SDL_GetBasePath()) + "../res/png/"};

    TextureStorage::TextureStorage(RendererWindow &window) : window_{window} {
        Log(LogLevel::Debug) << "TextureStorage created.";
    }

    TextureStorage::~TextureStorage() {
        for (auto &[key, value] : textures_) {
            SDL_DestroyTexture(value);
        }
        Log(LogLevel::Debug) << "TextureStorage destroyed.";
    }

    bool TextureStorage::load(const std::string& objectName, const std::string &texturePath) {
        const std::string fullTexturePath = RESOURCE_PATH + texturePath;
        SDL_Texture *texture = IMG_LoadTexture(window_.getRenderer(), fullTexturePath.c_str());
        if (texture == nullptr) {
            Log(LogLevel::Error) << "Cannot load an image: " << fullTexturePath;
            return false;
        }

        textures_.insert({objectName, texture});

        Log(LogLevel::Debug) << "Texture loaded: " << fullTexturePath;
        return true;
    }

    SDL_Texture *TextureStorage::get(const std::string &objectName) {
        auto it = textures_.find(objectName);
        if (it != textures_.end()) return it->second;

        return nullptr;
    }
} // Game
