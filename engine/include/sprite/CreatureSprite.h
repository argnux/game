//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_CREATURESPRITE_H
#define ENGINE_CREATURESPRITE_H

#include "sprite/Sprite.h"
#include "RendererWindow.h"

namespace Game {

    class CreatureSprite : public Sprite {
        enum FRAMES { FRAME_COMMON = 0, FRAME_LEFT, FRAME_RIGHT, FRAME_COUNT };

    public:
        explicit CreatureSprite(RendererWindow& rendererWindow);

        ~CreatureSprite() = default;
        void display() override;
        void init() override;
        void place(SDL_FPoint point) override;
        void moveTo(SDL_FPoint point) override;

        // Step is 10 by default
        void setMoveStep(float step);

    private:
        void tickMove();

        void setFrameX(FRAMES frame);

    private:
        SDL_FPoint current_velocity_{};
        SDL_FPoint end_point_{};

        float move_step_{10.f};
    };

} // Game

#endif //ENGINE_CREATURESPRITE_H
