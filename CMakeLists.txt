cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_NAME "ChopperGame")

project(${PROJECT_NAME})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

option(WASM "Compiles to WASM" OFF)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

if (NOT WASM)
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)
    find_package(nlohmann_json 3.7.3 REQUIRED)
    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../.)

    include_directories(
            ${SDL2_INCLUDE_DIR}
            ${SDL2_IMAGE_INCLUDE_DIR}
            ${SDL2_TTF_INCLUDE_DIR}
    )
endif (NOT WASM)


if (WASM)
    message(STATUS "Setting compilation target to WASM")
    SET(CMAKE_C_COMPILER emcc)
    SET(CMAKE_CPP_COMPILER em++)
    set(JSON_BuildTests OFF CACHE INTERNAL "")
    add_subdirectory(third_party/nlohmann_json)

    set(USE_FLAGS " -s WASM=1 -s USE_SDL=2 -s USE_SDL_IMAGE=2 -s USE_SDL_TTF=2 --preload-file ../assets -s SDL2_IMAGE_FORMATS='[\"png\"]'")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${USE_FLAGS}")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${USE_FLAGS}")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} ${USE_FLAGS}")

    set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/public")
    set(CMAKE_EXECUTABLE_SUFFIX ".html")
    include_directories(
            ${SDL2_INCLUDE_DIRS}
            ${SDL2_IMAGE_INCLUDE_DIR}
            ${SDL2_TTF_INCLUDE_DIR}
    )
endif (WASM)

add_executable(${PROJECT_NAME} src/main.cpp src/controllers/Game/Game.cpp src/controllers/Game/Game.h src/gameEntities/Map/Map.cpp src/gameEntities/Map/Map.h src/components/Tile/Tile.cpp src/components/Tile/Tile.h src/types.h src/gameEntities/Decoration/Decoration.cpp src/gameEntities/Decoration/Decoration.h src/components/Sprite/Sprite.cpp src/components/Sprite/Sprite.h src/gameEntities/Player/Player.cpp src/gameEntities/Player/Player.h src/components/KeyboardControl/KeyboardControl.cpp src/components/KeyboardControl/KeyboardControl.h src/components/PositionState/PositionState.cpp src/components/PositionState/PositionState.h src/controllers/Renderer/Renderer.cpp src/controllers/Renderer/Renderer.h src/gameEntities/Camera/Camera.cpp src/gameEntities/Camera/Camera.h)

target_link_libraries(
        ${PROJECT_NAME}
        ${SDL2_LIBRARY}
        ${SDL2_IMAGE_LIBRARIES}
        ${SDL2_TTF_LIBRARIES}
        nlohmann_json::nlohmann_json
)



