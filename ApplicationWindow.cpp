//
// Created by dmytro-nedavnii on 12/23/23.
//

#include "ApplicationWindow.h"

namespace Engine {
    ApplicationWindow::ApplicationWindow(const std::string &name, int width, int height) {
        window_ = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);
        renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    }

    ApplicationWindow::~ApplicationWindow() {
        SDL_DestroyWindow(window_);
    }

    int ApplicationWindow::exec() {
        SDL_ShowWindow(window_);
        is_running_ = true;
        while (is_running_) {
            handleEvents();

            // update game state, draw the current frame
            update();
        }
        SDL_Quit();

        return 0;
    }

    void ApplicationWindow::handleEvents() {
        SDL_Event event;
        if (SDL_PollEvent(&event)) {
            // poll until all events are handled!
            // decide what to do with this event.
            switch (event.type) {
                case SDL_QUIT:
                    is_running_ = false;
                    break;
            }
        }
    }

    void ApplicationWindow::update() {
        SDL_RenderClear(renderer_);
        SDL_RenderPresent(renderer_);
    }
} // Engine