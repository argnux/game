//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "object/Player.h"
#include "object/Item.h"
#include "Log.h"

namespace Game {
    Player::Player(const std::string &objectName, RendererWindow& rendererWindow)
        : Object(objectName, rendererWindow), sprite_(rendererWindow)
    {
        sprite_.loadTexture(renderer_window_.getTextureStorage().get(objectName));
        sprite_.init();
        Log(LogLevel::Debug) << "Player created: " << objectName;
    }

    void Player::display() {
        sprite_.display();
    }

    void Player::place(SDL_FPoint point) {
        sprite_.place(point);
    }

    void Player::moveTo(SDL_FPoint point) {
        sprite_.moveTo(point);
    }

    void Player::checkCollision(std::map<std::string, std::shared_ptr<Object>> &objects) {
        for (auto &[key, value] : objects) {
            if (auto item = dynamic_cast<Item *>(value.get())) {
                if (sprite_.collisionWith(item->sprite_) && key == "sword1") {
                    Log(LogLevel::Debug) << "found sword.";
                }
            }
        }
    }

    void Player::setMoveStep(float step) {
        sprite_.setMoveStep(step);
    }
} // Game
