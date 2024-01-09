project(engine VERSION 0.1)

add_library(engine
        src/RendererWindow.cpp
        src/TextureStorage.cpp
        src/sprite/Sprite.cpp
        src/sprite/CreatureSprite.cpp
        src/object/Player.cpp
        src/sprite/ItemSprite.cpp
        src/object/Item.cpp
        src/sprite/BuildingSprite.cpp
)

target_link_libraries(engine PRIVATE log SDL3::SDL3-shared SDL3_image::SDL3_image-shared)
