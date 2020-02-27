cmake_minimum_required(VERSION 3.15)
project(ChopperGame)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_ttf REQUIRED)
find_package(Boost REQUIRED)
find_package(nlohmann_json 3.7.3 REQUIRED)
include_directories(
        ${SDL2_INCLUDE_DIR}
        ${SDL2_IMAGE_INCLUDE_DIR}
        ${SDL2_TTF_INCLUDE_DIR}
        ${Boost_INCLUDE_DIRS}
)
add_compile_options(-Wall -Wextra -Wpedantic)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../.)
add_executable(ChopperGame src/main.cpp src/Game.cpp src/Game.h src/_consts.h src/components/Map/Map.cpp src/components/Map/Map.h src/components/Tile/Tile.cpp src/components/Tile/Tile.h src/components/TextureManager/TextureManager.cpp src/components/TextureManager/TextureManager.h src/_stucts.h src/components/Decoration/Decoration.cpp src/components/Decoration/Decoration.h src/components/Sprite/Sprite.cpp src/components/Sprite/Sprite.h src/components/Player/Player.cpp src/components/Player/Player.h)

target_link_libraries(
        ChopperGame
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        ${Boost_LIBRARIES}
        nlohmann_json::nlohmann_json
)