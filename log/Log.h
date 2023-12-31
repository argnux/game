//
// Created by dmytro-nedavnii on 12/31/23.
//

#ifndef GAME_LOG_H
#define GAME_LOG_H

#include <SDL3/SDL_log.h>
#include <sstream>
#include <memory>

/*
 * Set current log level using environment variable LOG_LEVEL.
 * By default, only error messages will be shown.
 * LogLevel::Debug: LOG_LEVEL <= 2
 * LogLevel::Info: LOG_LEVEL <= 3
 * LogLevel::Warning: LOG_LEVEL <= 4
 * LogLevel::Error: LOG_LEVEL <= 5
 */
enum class LogLevel {
    Debug = SDL_LOG_PRIORITY_DEBUG,
    Info = SDL_LOG_PRIORITY_INFO,
    Warning = SDL_LOG_PRIORITY_WARN,
    Error = SDL_LOG_PRIORITY_ERROR
};

enum class LogCategory {
    Game = SDL_LOG_CATEGORY_CUSTOM
};

class Log {
public:
    template<typename... Args>
    Log(LogLevel level, const char *format, Args... args) {
        level_ = level;

        int sz = std::snprintf(nullptr, 0, format, args...) + 1;
        if (sz <= 0) return;
        std::unique_ptr<char[]> buf{new char[sz]};
        std::snprintf(buf.get(), sz, format, args...);

        message_ << buf.get();
    }

    explicit Log(LogLevel level);
    ~Log();

    template<class T>
    Log &operator<<(const T &data) {
        message_ << data;
        return *this;
    }

    static void setupLogger();

private:
    static const LogCategory CATEGORY = LogCategory::Game;
    LogLevel level_;
    std::stringstream message_{};
};

#endif //GAME_LOG_H
