//
// Created by dmytro-nedavnii on 12/26/23.
//

#include "RendererWindow.h"
#include "object/Object.h"
#include "object/Player.h"

namespace Game {
    RendererWindow::RendererWindow(const std::string &windowName, int width, int height)
        : window_{SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN)},
          renderer_{SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC)},
          storage_{*this}
    {

    }

    RendererWindow::~RendererWindow() {
        SDL_DestroyRenderer(renderer_);
        SDL_DestroyWindow(window_);
    }

    int RendererWindow::exec() {
        SDL_ShowWindow(window_);

        is_running_ = true;
        while (is_running_) {
            handleEvents();

            // update game_src state, draw the current frame
            display();
        }

        SDL_Quit();

        return 0;
    }

    void RendererWindow::registerObject(const std::string &objectName, const std::string &texturePath) {
        storage_.load(objectName, texturePath);
    }

    void RendererWindow::display() {
        SDL_RenderClear(renderer_);
        SDL_SetRenderDrawColor(renderer_, 0, 255, 0, SDL_ALPHA_OPAQUE);
        for (auto &[key, val] : objects_) {
            displayObject(key);
        }
        SDL_RenderPresent(renderer_);
    }

    void RendererWindow::displayObject(const std::string &object) {
        if (auto player = getObject<Player>(object)) player->checkCollision(objects_);
        getObject<Object>(object)->display();
    }

    TextureStorage &RendererWindow::getTextureStorage() {
        return storage_;
    }

    SDL_Renderer *RendererWindow::getRenderer() {
        return renderer_;
    }

    void RendererWindow::handleEvents() {
        while (SDL_PollEvent(&event_)) {
            switch (event_.type) {
                case SDL_QUIT:
                    is_running_ = false;
                    break;
                case SDL_KEYDOWN:
                    handleKeyboard();
                    break;
                case SDL_KEYUP:
//                        handleKeyboardRelease();
                    break;
//                case SDL_MOUSEMOTION:
//                    motion_.x = event_.motion.x;
//                    motion_.y = event_.motion.y;
//                    handleMouse();
//                    break;
                case SDL_MOUSEBUTTONDOWN:
                    handleMouse();
                    break;
            }
        }
    }

    void RendererWindow::handleKeyboard() {

    }

    void RendererWindow::handleMouse() {
        if (event_.button.button == SDL_BUTTON_LEFT) {
            SDL_FPoint point;
            point.x = static_cast<float>(event_.button.x);
            point.y = static_cast<float>(event_.button.y);
            if (auto player = getObject<Player>("player1")) player->moveTo(point);
        }
    }
} // Game