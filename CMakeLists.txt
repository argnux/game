cmake_minimum_required(VERSION 3.27)
project(game VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

#set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

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

install(CODE [[
    file(GET_RUNTIME_DEPENDENCIES
        RESOLVED_DEPENDENCIES_VAR RES
        UNRESOLVED_DEPENDENCIES_VAR UNRES
        CONFLICTING_DEPENDENCIES_PREFIX CONFLICTING_DEPENDENCIES
        EXECUTABLES $<TARGET_FILE:game>
        LIBRARIES $<TARGET_FILE:SDL3::SDL3-shared> $<TARGET_FILE:SDL3_image::SDL3_image-shared>
    )

    message("\n\nFound dependencies :")
    foreach(DEP ${RES})
        message("${DEP}")
        file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES ${DEP}
      FOLLOW_SYMLINK_CHAIN)
    endforeach()
    message("\n\nNot found dependencies :")
    foreach(DEP ${UNRES})
        message("${DEP}")
    endforeach()
]])

#install(IMPORTED_RUNTIME_ARTIFACTS SDL3::SDL3-shared)
#install(IMPORTED_RUNTIME_ARTIFACTS game)
#install(IMPORTED_RUNTIME_ARTIFACTS game)
#install(IMPORTED_RUNTIME_ARTIFACTS SDL3_image::SDL3_image-shared FRAMEWORK EXCLUDE_FROM_ALL)
install(TARGETS game log engine)

install(DIRECTORY ${CMAKE_SOURCE_DIR}/res/png DESTINATION ${CMAKE_INSTALL_PREFIX}/res FILES_MATCHING PATTERN "*.png")
