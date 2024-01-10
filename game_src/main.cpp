//
// Created by dmytro-nedavnii on 12/23/23.
//

#include <SDL3/SDL.h>
#include <SDL3_image/SDL_image.h>

#include "GameApplication.h"
#include "Log.h"

int main() {
    Log::setupLogger();

    if (SDL_InitSubSystem(SDL_INIT_VIDEO) != 0) {
        Log(LogLevel::Error) << "Init Video subsystem error.";
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        Log(LogLevel::Error) << "Init Image subsystem error.";
        return 2;
    }

    atexit([](){
        IMG_Quit();
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    });

    GameApplication app("Testing", 1280, 720);

    return app.exec();
}
