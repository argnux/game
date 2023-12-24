//
// Created by dmytro-nedavnii on 12/23/23.
//

#ifndef ENGINE_APPLICATIONWINDOW_H
#define ENGINE_APPLICATIONWINDOW_H

#include <string>

#include <SDL2/SDL.h>

namespace Engine {

    class ApplicationWindow {
    public:
        explicit ApplicationWindow(const std::string& name, int width, int height);
        ~ApplicationWindow();

        int exec();

        void handleEvents();
        void update();

    private:
        SDL_Window *window_{};
        SDL_Renderer *renderer_{};

        bool is_running_{false};
    };

} // Engine

#endif //ENGINE_APPLICATIONWINDOW_H
