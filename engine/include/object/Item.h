//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_ITEM_H
#define ENGINE_ITEM_H

#include "object/Object.h"
#include "object/Player.h"
#include "sprite/ItemSprite.h"

namespace Game {

    class Item : public Object {
    public:
        Item(const std::string &objectName, RendererWindow& rendererWindow);

        void display() override;
        void place(SDL_FPoint point) override;
        void moveTo(SDL_FPoint point) override;

        friend void Player::checkCollision(std::map<std::string, std::shared_ptr<Object>> &objects);

    private:
        ItemSprite sprite_;
    };

} // Game

#endif //ENGINE_ITEM_H
