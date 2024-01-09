cmake_minimum_required(VERSION 3.27)
project(game VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_SKIP_BUILD_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/bin")

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(SDL3_image REQUIRED CONFIG REQUIRED COMPONENTS SDL3_image-shared)

include_directories(log)
include_directories(engine/include)
include_directories(game_src)

add_subdirectory(${CMAKE_SOURCE_DIR}/log)
add_subdirectory(${CMAKE_SOURCE_DIR}/engine)

add_executable(game game_src/main.cpp
        game_src/GameApplication.cpp
)
target_link_libraries(game PRIVATE log engine SDL3::Headers SDL3::SDL3-shared SDL3_image::SDL3_image-shared)

install(IMPORTED_RUNTIME_ARTIFACTS SDL3::SDL3-shared DESTINATION "${CMAKE_INSTALL_RPATH}")
install(IMPORTED_RUNTIME_ARTIFACTS SDL3_image::SDL3_image-shared DESTINATION "${CMAKE_INSTALL_RPATH}")
install(IMPORTED_RUNTIME_ARTIFACTS game DESTINATION "${CMAKE_INSTALL_RPATH}")

install(DIRECTORY ${CMAKE_SOURCE_DIR}/res/png DESTINATION ${CMAKE_INSTALL_PREFIX}/res FILES_MATCHING PATTERN "*.png")
