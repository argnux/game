//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_ITEMSPRITE_H
#define ENGINE_ITEMSPRITE_H

#include "sprite/Sprite.h"

namespace Game {

    class ItemSprite : public Sprite {
        enum FRAMES { FRAME_COMMON = 0, FRAME_COUNT };

    public:
        explicit ItemSprite(RendererWindow& rendererWindow);

        ~ItemSprite() override = default;
        void init() override;
        void place(SDL_FPoint point) override;
        void moveTo(SDL_FPoint point) override;

    private:
        void setFrameX(FRAMES frame);
    };

} // Game

#endif //ENGINE_ITEMSPRITE_H
