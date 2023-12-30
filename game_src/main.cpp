//
// Created by dmytro-nedavnii on 12/23/23.
//

#include <iostream>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3_image/SDL_image.h>
//#undef main

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
