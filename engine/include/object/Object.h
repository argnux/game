//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_OBJECT_H
#define ENGINE_OBJECT_H

#include "RendererWindow.h"

#include <string>

#include <SDL3/SDL.h>

namespace Game {
    class RendererWindow;

    class Object {
    public:
//        enum class ObjectType { Player, Enemy, Item, Building };

        Object(std::string objectName, RendererWindow& rendererWindow)
            : object_name_{std::move(objectName)}, renderer_window_{rendererWindow}
        {
        }
        virtual ~Object() = default;

        virtual void display() = 0;
        virtual void place(SDL_FPoint point) = 0; // instant move
        virtual void moveTo(SDL_FPoint point) = 0; // smooth move with velocity

    protected:
        const std::string object_name_;
//        const std::string instance_name_;
        RendererWindow& renderer_window_;
    };

} // Game

#endif //ENGINE_OBJECT_H
