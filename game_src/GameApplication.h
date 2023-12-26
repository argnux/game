//
// Created by dmytro-nedavnii on 12/26/23.
//

#ifndef ENGINE_GAME_H
#define ENGINE_GAME_H

#include "RendererWindow.h"

#include <string>

class GameApplication {
public:
    GameApplication(const std::string &windowName, int width, int height);

    void registerAll();
    void createAll();

    int exec();

private:
    Game::RendererWindow window_;
};


#endif //ENGINE_GAME_H
