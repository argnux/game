//
// Created by dmytro-nedavnii on 12/23/23.
//

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "GameApplication.h"
#include "Log.h"

int main() {
    Log::setupLogger();

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        Log(LogLevel::Error) << "SDL_Init: " << SDL_GetError();
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG))) {
        Log(LogLevel::Error) << "IMG_Init: " << SDL_GetError();
        return 2;
    }

    GameApplication app("Testing", 1280, 720);

    return app.exec();
}
