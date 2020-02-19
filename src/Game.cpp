//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#include "Game.h"
#include "_consts.h"
#include "components/Decoration/Decoration.h"
#include <SDL_ttf.h>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>

namespace pt = boost::property_tree;

Map *map;
SDL_Renderer *Game::sdl_renderer;
SDL_Window *Game::sdl_window;
SDL_Event Game::event;
Decoration *decoration;

Game::Game() {
  isRunning = false;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << std::endl;
    return;
  }
  if (TTF_Init() != 0) {
    std::cerr << "Error initializing SDL TTF" << std::endl;
    return;
  }

  sdl_window = SDL_CreateWindow(
      consts::title.data(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      consts::WINDOW_WIDTH, consts::WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
  if (nullptr == sdl_window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }
  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);
  if (nullptr == sdl_renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }

  LoadLevel();
}

void Game::LoadLevel() {
  pt::ptree config;
  std::ifstream jsonFile("assets/config.json");
  pt::read_json(jsonFile, config);
  auto mapLayoutFile = config.get<std::string>("map.mapLayoutFile");
  auto mapImageFile = config.get<std::string>("map.mapImageFile");
  auto scale = config.get<int>("map.scale");
  auto tileSize = config.get<int>("map.tileSize");
  auto mapSizeX = config.get<int>("map.mapSizeX");
  auto mapSizeY = config.get<int>("map.mapSizeY");

  map =
      new Map(mapImageFile, mapLayoutFile, scale, tileSize, mapSizeX, mapSizeY);

  auto decorationFile = config.get<std::string>("decorations.1.file");
  auto width = config.get<int>("decorations.1.width");
  auto height = config.get<int>("decorations.1.height");
  auto x = config.get<int>("decorations.1.x");
  auto y = config.get<int>("decorations.1.y");

  decoration = new Decoration(decorationFile, width, height, x, y );
}

void Game::Run() {
  isRunning = true;

  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  while (isRunning) {
    frame_start = SDL_GetTicks();
    ProcessInput();
    Render();
    frame_end = SDL_GetTicks();
    frame_duration = frame_end - frame_start;
    frame_count++;

    if (frame_end - title_timestamp >= 1000) {
      UpdateWindowTitle(frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    if (frame_duration < consts::FRAME_TARGET_TIME) {
      SDL_Delay(consts::FRAME_TARGET_TIME - frame_duration);
    }
  }
  Destroy();
}

void Game::UpdateWindowTitle(int fps) {
  std::string title{consts::title + "; FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, title.data());
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
  }
  default: {
    break;
  }
  }
}

void Game::Destroy() {
  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Game::Render() {

  SDL_SetRenderDrawColor(sdl_renderer, 158, 200, 92, 255);
  SDL_RenderClear(sdl_renderer);
  map->Render();
  decoration->Render();

  SDL_RenderPresent(sdl_renderer);
}
