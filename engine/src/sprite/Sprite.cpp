//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "sprite/Sprite.h"

#include <algorithm>

namespace Game {
    void Sprite::loadTexture(SDL_Texture *texture) {
        texture_ = texture;
    }

    Sprite::Sprite(RendererWindow &window)
        : renderer_window_{window}
    {

    }

    SDL_FPoint Sprite::getCenter() const {
        SDL_FPoint center;
        center.x = dst_.x + dst_.w * 0.5f;
        center.y = dst_.y + dst_.h * 0.5f;
        return center;
    }

    SDL_FPoint Sprite::getClampedCoordinates(SDL_FPoint point) {
        int windowWidth, windowHeight;
        SDL_GetCurrentRenderOutputSize(renderer_window_.getRenderer(), &windowWidth, &windowHeight);

        SDL_FPoint clamped;
        clamped.x = std::clamp(point.x, 0.f, windowWidth - dst_.w);
        clamped.y = std::clamp(point.y, 0.f, windowHeight - dst_.h);
        return clamped;
    }

    SDL_FPoint Sprite::getClampedCenterCoordinates(SDL_FPoint point) {
        int windowWidth, windowHeight;
        SDL_GetCurrentRenderOutputSize(renderer_window_.getRenderer(), &windowWidth, &windowHeight);

        SDL_FPoint clamped;
        clamped.x = std::clamp(point.x, 0.f + dst_.w * 0.5f, windowWidth - dst_.w * 0.5f);
        clamped.y = std::clamp(point.y, 0.f + dst_.h * 0.5f, windowHeight - dst_.h * 0.5f);
        return clamped;
    }

    void Sprite::display() {
        SDL_RenderTexture(renderer_window_.getRenderer(), texture_, &src_, &dst_);
    }

    bool Sprite::collisionWith(const Sprite& other) {
        return SDL_HasRectIntersectionFloat(&dst_, &other.dst_);
    }
} // Game
