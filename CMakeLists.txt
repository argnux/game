cmake_minimum_required(VERSION 3.27)
project(game VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL2 REQUIRED)

include_directories(SDL2Test ${SDL2_INCLUDE_DIRS})
include_directories(engine/include)
include_directories(game_src)

if (MSVC)
    link_directories(${CMAKE_PREFIX_PATH}/lib)
endif (MSVC)

add_subdirectory(${CMAKE_SOURCE_DIR}/engine)

add_executable(game game_src/main.cpp
        game_src/GameApplication.cpp
)

target_link_libraries(game engine ${SDL2_LIBRARIES} SDL2_image)
