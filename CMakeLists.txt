cmake_minimum_required(VERSION 3.27)
project(game VERSION 0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL3 REQUIRED CONFIG COMPONENTS SDL3)
find_package(SDL3_image REQUIRED CONFIG)

include_directories(SDL3Test ${SDL3_INCLUDE_DIRS} ${SDL3_IMAGE_INCLUDE_DIRS})
include_directories(log)
include_directories(engine/include)
include_directories(game_src)

#link_directories(${CMAKE_PREFIX_PATH}/lib)

add_subdirectory(${CMAKE_SOURCE_DIR}/log)
add_subdirectory(${CMAKE_SOURCE_DIR}/engine)

add_executable(game game_src/main.cpp
        game_src/GameApplication.cpp
)

target_link_libraries(game PRIVATE log engine SDL3_image::SDL3_image-shared SDL3::SDL3-shared)

install(CODE [[
  function(install_library LIBRARY)
    file(INSTALL
      DESTINATION "${CMAKE_INSTALL_PREFIX}"
      TYPE SHARED_LIBRARY
      FOLLOW_SYMLINK_CHAIN
      FILES "${LIBRARY}"
    )
  endfunction()
  file(GET_RUNTIME_DEPENDENCIES
    EXECUTABLES  $<TARGET_FILE:game>
    RESOLVED_DEPENDENCIES_VAR RESOLVED_DEPS
    UNRESOLVED_DEPENDENCIES_VAR UNRESOLVED_DEPS
  )
  foreach(FILE ${RESOLVED_DEPS})
    install_library(${FILE})
  endforeach()
  foreach(FILE ${UNRESOLVED_DEPS})
    message(STATUS "Unresolved: ${FILE}")
  endforeach()
]])
install(TARGETS game DESTINATION "${CMAKE_INSTALL_PREFIX}")
install(DIRECTORY ${CMAKE_SOURCE_DIR}/res/png DESTINATION ${CMAKE_INSTALL_PREFIX}/res FILES_MATCHING PATTERN "*.png")
