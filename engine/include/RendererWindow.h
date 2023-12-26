//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_RENDERERWINDOW_H
#define ENGINE_RENDERERWINDOW_H

#include "object/Object.h"
#include "TextureStorage.h"

#include <string>
#include <map>
#include <memory>

namespace Game {
    class Object;

    class RendererWindow {
    public:
        RendererWindow(const std::string &windowName, int width, int height);
        ~RendererWindow();

        int exec();

        // FIXME: maybe need to use configPath instead of texturePath
        void registerObject(const std::string &objectName, const std::string &texturePath);

        template<class T>
        void createObject(const std::string &objectName, const std::string &instanceName) {
            objects_.insert({instanceName, std::make_shared<T>(objectName, *this)});
        }

        template<class T>
        std::shared_ptr<T> getObject(const std::string &instanceName) {
            return std::dynamic_pointer_cast<T>(objects_.at(instanceName));
        }

        void display();
        void displayObject(const std::string &instanceName);
        TextureStorage& getTextureStorage();
        SDL_Renderer *getRenderer();

        // Events handling
        void handleEvents();
        void handleKeyboard();
        void handleMouse();

    private:
        SDL_Window *window_{};
        SDL_Renderer *renderer_{};

        SDL_Event event_{};
        bool is_running_{false};

        std::map<std::string, std::shared_ptr<Object>> objects_;
        TextureStorage storage_;
    };

} // Game

#endif //ENGINE_RENDERERWINDOW_H
