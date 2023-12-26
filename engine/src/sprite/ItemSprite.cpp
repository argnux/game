//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "sprite/ItemSprite.h"

namespace Game {
    ItemSprite::ItemSprite(RendererWindow &rendererWindow) : Sprite(rendererWindow) {

    }

    void ItemSprite::init() {
        size_ = 32;

        setFrameX(FRAME_COMMON);
        src_.y = 0;
        src_.w = size_;
        src_.h = size_;
        size_multiplier_ = 2;

        dst_.w = size_ * size_multiplier_;
        dst_.h = size_ * size_multiplier_;
    }

    void ItemSprite::place(SDL_FPoint point) {
        point = getClampedCoordinates(point);

        dst_.x = point.x;
        dst_.y = point.y;
    }

    void ItemSprite::moveTo(SDL_FPoint point) {
        // For now there are no any purpose to move items
        place(point);
    }

    void ItemSprite::setFrameX(ItemSprite::FRAMES frame) {
        src_.x = frame * size_;
    }
} // Game
