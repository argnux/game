project(engine VERSION 0.1)

add_library(engine
        RendererWindow.cpp
        TextureStorage.cpp
        src/sprite/Sprite.cpp
        src/sprite/CreatureSprite.cpp
        src/object/Player.cpp
        src/sprite/ItemSprite.cpp
        src/object/Item.cpp
        src/sprite/BuildingSprite.cpp
)

target_link_libraries(engine ${SDL2_LIBRARIES} SDL2_image)
