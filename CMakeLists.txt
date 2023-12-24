cmake_minimum_required(VERSION 3.27)
project(engine VERSION 0.1)

find_package(SDL2 REQUIRED CONFIG REQUIRED COMPONENTS SDL2)

include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

# FIXME: temporary, later it will be library
add_executable(engine main.cpp
        ApplicationWindow.cpp
        ApplicationWindow.h)

target_link_libraries(engine SDL2::SDL2)
