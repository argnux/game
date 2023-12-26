//
// Created by dmytro-nedavnii on 12/23/23.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "GameApplication.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        std::cout << "IMG_Init Error: " << SDL_GetError() << std::endl;
        return 2;
    }

    GameApplication app("Testing", 1280, 720);

    return app.exec();
}
