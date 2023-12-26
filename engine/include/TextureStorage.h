//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_TEXTURESTORAGE_H
#define ENGINE_TEXTURESTORAGE_H

#include <string>
#include <map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

namespace Game {
    class RendererWindow;

    class TextureStorage {
    public:
        explicit TextureStorage(RendererWindow& window);
        ~TextureStorage();

        bool load(const std::string& objectName, const std::string &texturePath);
        void unload(const std::string &objectName);
        SDL_Texture* get(const std::string &objectName);

    private:
        RendererWindow& window_;
        std::map<std::string, SDL_Texture *> textures_;
    };

} // Game

#endif //ENGINE_TEXTURESTORAGE_H
