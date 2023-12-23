//
// Created by dmytro-nedavnii on 12/23/23.
//

#include "ApplicationEngine.h"

namespace Engine {
    ApplicationEngine::ApplicationEngine(const std::string &name) {
        create(name);
    }

    ApplicationEngine::~ApplicationEngine() {
        SDL_DestroyWindow(window);
    }

    void ApplicationEngine::create(const std::string &name) {
        window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 480, 320, SDL_WINDOW_SHOWN);
        SDL_Surface *surface = SDL_GetWindowSurface(window);
        SDL_FillRect(surface, nullptr, SDL_MapRGB(surface->format, 0, 255, 0));
        SDL_UpdateWindowSurface(window);
    }

    int ApplicationEngine::exec() {
        SDL_ShowWindow(window);
        isRunning = true;
        while (isRunning) {
            handleEvents();
        }
        SDL_Quit();

        return 0;
    }

    void ApplicationEngine::handleEvents() {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            // poll until all events are handled!
            // decide what to do with this event.
            if (event.type == SDL_EventType::SDL_QUIT) {
                isRunning = false;
            }
        }

        // update game state, draw the current frame
        update();
    }

    void ApplicationEngine::update() {

    }
} // Engine