//
// Created by dmytro-nedavnii on 12/31/23.
//

#include "Log.h"

Log::Log(LogLevel level) {
    level_ = level;
}

Log::~Log() {
    SDL_LogMessage(static_cast<SDL_LogCategory>(CATEGORY), static_cast<SDL_LogPriority>(level_), "%s\n", message_.str().c_str());
}

void Log::setupLogger() {
    LogLevel level = LogLevel::Error;
    if (auto envLogLevel = SDL_getenv("LOG_LEVEL")) {
        level = static_cast<LogLevel>(std::atoi(envLogLevel));
    }

    SDL_LogSetAllPriority(static_cast<SDL_LogPriority>(LogLevel::Error));
    SDL_LogSetPriority(static_cast<SDL_LogCategory>(CATEGORY), static_cast<SDL_LogPriority>(level));
}
