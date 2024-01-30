cmake_minimum_required(VERSION 3.27)
project(game VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_SKIP_BUILD_RPATH FALSE)
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)
set(CMAKE_INSTALL_RPATH "$\{ORIGIN\}")

set(INSTALL_BINARY_PATH "${CMAKE_INSTALL_PREFIX}/bin")
set(INSTALL_RESOURCE_PATH "${CMAKE_INSTALL_PREFIX}/res")

set(EXTERNAL_INSTALL_LOCATION ${CMAKE_BINARY_DIR}/external)
include_directories(${EXTERNAL_INSTALL_LOCATION}/include)
set(CMAKE_PREFIX_PATH ${EXTERNAL_INSTALL_LOCATION})

find_package(SDL3 CONFIG COMPONENTS SDL3-shared)
find_package(SDL3_image CONFIG COMPONENTS SDL3_image-shared)

include(ExternalProject)

ExternalProject_Add(sdl
        GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
        GIT_TAG main
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

ExternalProject_Add(sdl_image
        GIT_REPOSITORY https://github.com/libsdl-org/SDL_image.git
        GIT_TAG main
        CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${EXTERNAL_INSTALL_LOCATION}
)

include_directories(log)
include_directories(engine/include)
include_directories(game_src)

if((NOT ${SDL3_FOUND}) AND (NOT ${SDL3_image_FOUND}))
    # rerun cmake in initial build
    # will update cmakecache/project files on first build
    # so you may have to reload project after first build
    add_custom_target(Rescan ${CMAKE_COMMAND} ${CMAKE_SOURCE_DIR} DEPENDS sdl sdl_image)

    add_executable(game
            game_src/dummy_main.cpp
    )
else()
    #Rescan becomes a dummy target after first build
    #this prevents cmake from rebuilding cache/projects on subsequent builds
    add_custom_target(Rescan)

    add_subdirectory(${CMAKE_SOURCE_DIR}/log)
    add_subdirectory(${CMAKE_SOURCE_DIR}/engine)

    add_executable(game
            game_src/main.cpp
            game_src/GameApplication.cpp
    )
    target_link_libraries(game PRIVATE log engine SDL3::SDL3 SDL3_image::SDL3_image)
endif()

add_dependencies(game Rescan)

if (WIN32)
    add_compile_options(-static-libgcc -static-libstdc++ --static)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -static-libgcc -static-libstdc++ --static")
endif ()

if (${SDL3_FOUND} AND ${SDL3_image_FOUND})
    install(IMPORTED_RUNTIME_ARTIFACTS SDL3::SDL3-shared DESTINATION ${INSTALL_BINARY_PATH})
    install(IMPORTED_RUNTIME_ARTIFACTS SDL3_image::SDL3_image-shared DESTINATION ${INSTALL_BINARY_PATH})
    install(IMPORTED_RUNTIME_ARTIFACTS game DESTINATION ${INSTALL_BINARY_PATH})
    install(DIRECTORY ${CMAKE_SOURCE_DIR}/res/png DESTINATION ${INSTALL_RESOURCE_PATH} FILES_MATCHING PATTERN "*.png")
endif ()
