project(log VERSION 0.1)

add_library(log
    Log.cpp
)

if (${SDL3_FOUND} AND ${SDL3_image_FOUND})
    target_link_libraries(log PRIVATE SDL3::SDL3)
endif ()
