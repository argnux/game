//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "sprite/CreatureSprite.h"

#include <cmath>

namespace Game {
    CreatureSprite::CreatureSprite(RendererWindow &rendererWindow) : Sprite(rendererWindow)
    {
    }

    void CreatureSprite::display() {
        tickMove();
        Sprite::display();
    }

    void CreatureSprite::init() {
        size_ = 32;

        setFrameX(FRAME_COMMON);
        src_.y = 0;
        src_.w = size_;
        src_.h = size_;
        size_multiplier_ = 5;

        dst_.w = size_ * size_multiplier_;
        dst_.h = size_ * size_multiplier_;
    }

    void CreatureSprite::setFrameX(Game::CreatureSprite::FRAMES frame) {
        src_.x = frame * size_;
    }

    void CreatureSprite::place(SDL_FPoint point) {
        point = getClampedCoordinates(point);

        dst_.x = point.x;
        dst_.y = point.y;
    }

    void CreatureSprite::moveTo(SDL_FPoint endPoint) {
        endPoint = getClampedCenterCoordinates(endPoint);
        end_point_ = endPoint;

        SDL_FPoint center = getCenter();
        SDL_FPoint distancePoint = {endPoint.x  - center.x, endPoint.y  - center.y};
        float angle = std::atan2(distancePoint.y, distancePoint.x);

        if (distancePoint.x == 0) setFrameX(FRAME_COMMON);
        else if (distancePoint.x < 0) setFrameX(FRAME_LEFT);
        else if (distancePoint.x > 0) setFrameX(FRAME_RIGHT);

        current_velocity_.x = move_step_ * std::cos(angle);
        current_velocity_.y = move_step_ * std::sin(angle);
    }

    void CreatureSprite::tickMove() {
        dst_.x += current_velocity_.x;
        dst_.y += current_velocity_.y;

        SDL_FPoint center = getCenter();
        if (std::abs(end_point_.x - center.x) <= move_step_ && std::abs(end_point_.y - center.y) <= move_step_) {
            current_velocity_.x = 0;
            current_velocity_.y = 0;

            setFrameX(FRAME_COMMON);
        }
    }

    void CreatureSprite::setMoveStep(float step) {
        move_step_ = step;
    }
} // Game
