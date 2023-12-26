//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "object/Item.h"

namespace Game {
    Item::Item(const std::string &objectName, RendererWindow &rendererWindow)
        : Object(objectName, rendererWindow), sprite_(rendererWindow)
    {
        sprite_.loadTexture(renderer_window_.getTextureStorage().get(objectName));
        sprite_.init();
    }

    void Item::display() {
        sprite_.display();
    }

    void Item::place(SDL_FPoint point) {
        sprite_.place(point);
    }

    void Item::moveTo(SDL_FPoint point) {
        sprite_.moveTo(point);
    }
} // Game
