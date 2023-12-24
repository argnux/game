//
// Created by dmytro-nedavnii on 12/23/23.
//

#include <iostream>
#include "SDL2/SDL.h"

#include "ApplicationWindow.h"

int main() {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    Engine::ApplicationWindow app("Test", 1280, 720);

    return app.exec();
}
