//
// Created by Jedrzej Lewandowski on 20/11/2019.
//
#include "./Game.h"
#include "../../../lib/config.h"
#include <boost/property_tree/json_parser.hpp>

Game::Game(Renderer *renderer) : renderer(renderer) { isRunning = false; }

void Game::CreateGameEntities() {

  std::ifstream config_json("assets/config.json");

  config::Config config = nlohmann::json::parse(config_json);

  auto [map_image_file, map_layout_file, map_scale, tile_size, map_size_x,
        map_size_y] = config.map;

  map = new Map(renderer->LoadTexture(map_image_file.c_str()), map_layout_file,
                map_scale, tile_size, map_size_x, map_size_y);

  std::string basePath = config.assets_path + config.sprite_path;

  for (auto &decorationConfig : config.decorations) {
    auto [file, width, height, x, y, scale, animation] = decorationConfig;

    std::string decorationPath = basePath + file;

    Decoration decoration(renderer->LoadTexture(decorationPath.c_str()),
                          width, height, x, y, scale);

    decorations.emplace_back(decoration);
  }

  auto [file, width, height, x, y, scale, animation] = config.player;
  std::string playerPath = basePath + file;
  player = new Player(renderer->LoadTexture(playerPath.c_str()),
                      width, height, x, y, scale, animation->speed,
                      animation->frame_width, animation->frame_height);
}

void Game::Run() {
  isRunning = true;

  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count{0};

  while (isRunning) {
    frame_start = SDL_GetTicks();

    float deltaTime = (frame_start - frame_end) / 1000.0f;
    deltaTime = (deltaTime > 0.05f) ? 0.05f : deltaTime;

    ProcessInput();
    Update(deltaTime);
    renderer->Render(map, &decorations, player);

    frame_end = SDL_GetTicks();
    frame_duration = frame_end - frame_start;
    frame_count++;

    if (frame_end - title_timestamp >= 1000) {
      renderer->UpdateWindowTitle(frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    if (frame_duration < consts::FRAME_TARGET_TIME) {
      SDL_Delay(consts::FRAME_TARGET_TIME - frame_duration);
    }
  }
}

void Game::Update(float deltaTime) {
  for (auto &decoration : decorations) {
    decoration.Update(deltaTime);

  }
  player->Update(deltaTime, &event);
}

void Game::ProcessInput() {

  SDL_PollEvent(&event);

  switch (event.type) {
  case SDL_QUIT: {
    isRunning = false;
    break;
  }
  case SDL_KEYDOWN: {
    if (event.key.keysym.sym == SDLK_ESCAPE) {
      isRunning = false;
    }
    break;
  }
  default: {
    break;
  }
  }
}
