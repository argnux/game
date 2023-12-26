//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_BUILDINGSPRITE_H
#define ENGINE_BUILDINGSPRITE_H

#include "sprite/Sprite.h"

namespace Game {

    class BuildingSprite : public Sprite {
        enum FRAMES { FRAME_OUTSIDE = 0, FRAME_INSIDE, FRAME_COUNT };

    public:
        explicit BuildingSprite(RendererWindow& rendererWindow);

        ~BuildingSprite() override = default;
        void init() override;
        void place(SDL_FPoint point) override;
        void moveTo(SDL_FPoint point) override;

    private:
        void setFrameX(FRAMES frame);
    };

} // Game

#endif //ENGINE_BUILDINGSPRITE_H
