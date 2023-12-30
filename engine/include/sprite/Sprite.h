//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_SPRITE_H
#define ENGINE_SPRITE_H

#include <SDL3/SDL.h>

#include "RendererWindow.h"

namespace Game {
    class RendererWindow;

    class Sprite {
    public:
        explicit Sprite(Game::RendererWindow& window);
        virtual ~Sprite() = default;

        void loadTexture(SDL_Texture *texture);
        bool collisionWith(const Sprite& other);
        virtual void display();

        virtual void init() = 0;
        virtual void place(SDL_FPoint point) = 0;
        virtual void moveTo(SDL_FPoint point) = 0;

    protected:
        [[nodiscard]] SDL_FPoint getCenter() const;
        SDL_FPoint getClampedCoordinates(SDL_FPoint point);
        SDL_FPoint getClampedCenterCoordinates(SDL_FPoint point);

    protected:
        int size_{};
        int size_multiplier_{};
        SDL_Texture *texture_{};

        SDL_FRect src_{};
        SDL_FRect dst_{};

    private:
        RendererWindow& renderer_window_;
    };

} // Game

#endif //ENGINE_SPRITE_H
