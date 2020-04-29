//
// Created by Jedrzej Lewandowski on 20/11/2019.
//
#include "./Game.h"
#include <boost/property_tree/json_parser.hpp>
#include "../../../lib/config.h"

Game::Game(Renderer* renderer) : renderer(renderer) { isRunning = false; }

void Game::CreateGameEntities() {
  camera = new Camera(0, 0, consts::WINDOW_WIDTH, consts::WINDOW_HEIGHT);

  std::ifstream config_json("assets/config.json");

  config::Config config = nlohmann::json::parse(config_json);

  map = new Map(renderer->LoadTexture(config.map.map_image_file.c_str()),
                config.map);

  std::string basePath = config.assets_path + config.sprite_path;

  for (auto& decorationConfig : config.decorations) {
    std::string decorationPath = basePath + decorationConfig.file;

    Decoration decoration(renderer->LoadTexture(decorationPath.c_str()),
                          decorationConfig);

    decorations.emplace_back(decoration);
  }

  std::string playerPath = basePath + config.player.file;
  player = new Player(renderer->LoadTexture(playerPath.c_str()), config.player);
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
  for (auto& decoration : decorations) {
    decoration.Update(deltaTime, camera->getPosition());
  }
  player->Update(deltaTime, &event, camera->getPosition());

  map->Update(camera->getPosition());

  camera->Update(player->position);
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
