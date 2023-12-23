//
// Created by dmytro-nedavnii on 12/23/23.
//

#ifndef ENGINE_APPLICATIONENGINE_H
#define ENGINE_APPLICATIONENGINE_H

#include <string>

#include <SDL2/SDL.h>

namespace Engine {

    class ApplicationEngine {
    public:
        explicit ApplicationEngine(const std::string& name);
        ~ApplicationEngine();

        void create(const std::string& name);
        int exec();

        void handleEvents();
        void update();

    private:
        SDL_Window *window{};

        bool isRunning{false};
    };

} // Engine

#endif //ENGINE_APPLICATIONENGINE_H
