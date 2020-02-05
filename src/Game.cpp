//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#include "Game.h"
#include "SDL_Instances.h"
#include "_constants.h"
#include <SDL_ttf.h>
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree.hpp>
#include <iostream>

namespace pt = boost::property_tree;

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

  SDL_Instances::window = SDL_CreateWindow(
      consts::title.data(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
      consts::WINDOW_WIDTH, consts::WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
  if (!SDL_Instances::window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }
  SDL_Instances::renderer = SDL_CreateRenderer(SDL_Instances::window, -1, 0);

  if (!SDL_Instances::renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }
}

void Game::Run() {
  isRunning = true;

  Uint32 title_timestamp = SDL_GetTicks();
  Uint32 frame_start;
  Uint32 frame_end;
  Uint32 frame_duration;
  int frame_count = 0;

  pt::ptree config;
  std::ifstream jsonFile("assets/config.json");
  pt::read_json(jsonFile, config);
  auto name = config.get<std::string>("map.file");

  while (isRunning) {
    frame_start = SDL_GetTicks();
    ProcessInput();

    std::cout << "This machine " << name << std::endl;

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
  SDL_SetWindowTitle(SDL_Instances::window, title.data());
}

void Game::ProcessInput() {

  SDL_PollEvent(&SDL_Instances::event);

  switch (SDL_Instances::event.type) {
  case SDL_QUIT: {
    isRunning = false;
    break;
  }
  case SDL_KEYDOWN: {
    if (SDL_Instances::event.key.keysym.sym == SDLK_ESCAPE) {
      isRunning = false;
    }
  }
  default: {
    break;
  }
  }
}

void Game::Destroy() {
  SDL_DestroyRenderer(SDL_Instances::renderer);
  SDL_DestroyWindow(SDL_Instances::window);
  SDL_Quit();
}
void Game::Render() {}
