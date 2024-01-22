cmake_minimum_required(VERSION 3.27)
project(game VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(INSTALL_GTEST OFF)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3-shared)
find_package(SDL3_image REQUIRED CONFIG REQUIRED COMPONENTS SDL3_image-shared)

# Fetch GoogleTest
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

include_directories(log)
include_directories(engine/include)
include_directories(game_src)

add_subdirectory(${CMAKE_SOURCE_DIR}/log)
add_subdirectory(${CMAKE_SOURCE_DIR}/engine)

enable_testing()
add_executable(game_test test/game_test.cc
        game_src/GameApplication.cpp)
target_link_libraries(game_test PRIVATE log engine SDL3::Headers SDL3::SDL3-shared SDL3_image::SDL3_image-shared GTest::gtest_main)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$\{ORIGIN\}")

add_executable(game game_src/main.cpp
        game_src/GameApplication.cpp
)
target_link_libraries(game PRIVATE log engine SDL3::Headers SDL3::SDL3-shared SDL3_image::SDL3_image-shared)

set(INSTALL_BINARY_PATH "${CMAKE_INSTALL_PREFIX}/bin")
set(INSTALL_RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/res")

install(IMPORTED_RUNTIME_ARTIFACTS SDL3::SDL3-shared DESTINATION ${INSTALL_BINARY_PATH})
install(IMPORTED_RUNTIME_ARTIFACTS SDL3_image::SDL3_image-shared DESTINATION ${INSTALL_BINARY_PATH})
install(IMPORTED_RUNTIME_ARTIFACTS game DESTINATION ${INSTALL_BINARY_PATH})

install(DIRECTORY ${CMAKE_SOURCE_DIR}/res/png DESTINATION ${INSTALL_RESOURCE_PATH} FILES_MATCHING PATTERN "*.png")
