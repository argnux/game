//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "GameApplication.h"
#include "object/Player.h"
#include "object/Item.h"

GameApplication::GameApplication(const std::string &windowName, int width, int height)
    : window_{windowName, width, height}
{

}

void GameApplication::registerAll() {
    window_.registerObject("player", "player.png");
    window_.registerObject("sword", "sword.png");
}

void GameApplication::createAll() {
    // Creating
    window_.createObject<Game::Player>("player", "player1");
    window_.createObject<Game::Item>("sword", "sword1");
    window_.createObject<Game::Item>("sword", "sword2");

    // Configuring
    window_.getObject<Game::Object>("player1")->place({0.f, 0.f});
    window_.getObject<Game::Player>("player1")->setMoveStep(5.f);
    window_.getObject<Game::Object>("sword1")->place({300.f, 300.f});
    window_.getObject<Game::Object>("sword2")->place({1100.f, 500.f});
}

int GameApplication::exec() {
    registerAll();
    createAll();
    return window_.exec();
}
