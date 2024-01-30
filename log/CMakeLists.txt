project(log VERSION 0.1)

add_library(log
    Log.cpp
)
target_link_libraries(log PRIVATE SDL3::SDL3)
