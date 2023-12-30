//
// Created by dmytro-nedavnii on 12/31/23.
//

#include "Log.h"

Log::Log(LogLevel level) {
    level_ = level;
}

Log::~Log() {
    SDL_LogMessage(CATEGORY, static_cast<SDL_LogPriority>(level_), "%s\n", message_.str().c_str());
}
