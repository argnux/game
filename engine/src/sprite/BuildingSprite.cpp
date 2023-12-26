//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "sprite/BuildingSprite.h"

namespace Game {
    BuildingSprite::BuildingSprite(RendererWindow &rendererWindow) : Sprite(rendererWindow) {

    }

    void BuildingSprite::init() {
        size_ = 64;

        setFrameX(FRAME_OUTSIDE);
        src_.y = 0;
        src_.w = size_;
        src_.h = size_;

        dst_.w = size_ * size_multiplier_;
        dst_.h = size_ * size_multiplier_;
    }

    void BuildingSprite::place(SDL_FPoint point) {
        point = getClampedCoordinates(point);

        dst_.x = point.x;
        dst_.y = point.y;
    }

    void BuildingSprite::moveTo(SDL_FPoint point) {
        // For now there are no any purpose to move buildings
        place(point);
    }

    void BuildingSprite::setFrameX(BuildingSprite::FRAMES frame) {
        src_.x = frame * size_;
        size_multiplier_ = frame == FRAME_OUTSIDE ? 2 : 3;
    }
} // Game