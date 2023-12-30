//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "TextureStorage.h"
#include "RendererWindow.h"
#include <iostream>

namespace Game {
    TextureStorage::TextureStorage(RendererWindow &window) : window_{window} {

    }

    TextureStorage::~TextureStorage() {
        for (auto &[key, value] : textures_) {
            SDL_DestroyTexture(value);
        }
    }

    bool TextureStorage::load(const std::string& objectName, const std::string &texturePath) {
        SDL_Texture *texture = IMG_LoadTexture(window_.getRenderer(), texturePath.c_str());
        if (texture == nullptr) {
            std::cerr << "Cannot load an image: " << texturePath << "\n";
            return false;
        }

        textures_.insert({objectName, texture});
        return true;
    }

    SDL_Texture *TextureStorage::get(const std::string &objectName) {
        auto it = textures_.find(objectName);
        if (it != textures_.end()) return it->second;

        return nullptr;
    }
} // Game
