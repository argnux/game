//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_PLAYER_H
#define ENGINE_PLAYER_H

#include <string>
#include <map>
#include <memory>

#include "RendererWindow.h"
#include "object/Object.h"
#include "sprite/Sprite.h"
#include "sprite/CreatureSprite.h"

namespace Game {

    class Player : public Object {
    public:
        Player(const std::string &objectName, RendererWindow& rendererWindow);

        void display() override;
        void place(SDL_FPoint point) override;
        void moveTo(SDL_FPoint point) override;

        void setMoveStep(float step);
        void checkCollision(std::map<std::string, std::shared_ptr<Object>>& objects);

    private:
        CreatureSprite sprite_;
    };

} // Game

#endif //ENGINE_PLAYER_H
