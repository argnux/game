//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_TEXTURESTORAGE_H
#define ENGINE_TEXTURESTORAGE_H

#include <string>
#include <map>

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

namespace Game {
    class RendererWindow;

    class TextureStorage {
    public:
        explicit TextureStorage(RendererWindow& window);
        ~TextureStorage();

        bool load(const std::string& objectName, const std::string &texturePath);
        SDL_Texture* get(const std::string &objectName);

        void cleanup();

    private:
        RendererWindow& window_;
        std::map<std::string, SDL_Texture *> textures_;

        static const std::string RESOURCE_PATH;
    };

} // Game

#endif //ENGINE_TEXTURESTORAGE_H
