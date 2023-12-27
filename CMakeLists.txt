cmake_minimum_required(VERSION 3.27)
project(game VERSION 0.1)

find_package(SDL2 REQUIRED)

include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})

include_directories(engine/include)
include_directories(game_src)

add_subdirectory(${CMAKE_SOURCE_DIR}/engine)

add_executable(game game_src/main.cpp
        game_src/GameApplication.cpp
)

target_link_libraries(game engine SDL2::SDL2main SDL2::SDL2 SDL2_image)
