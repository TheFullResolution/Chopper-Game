//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#include "Game.h"
#include "_constants.h"
#include <SDL_ttf.h>
#include <iostream>

SDL_Event Game::event;

Game::Game() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << std::endl;
    return;
  }
  if (TTF_Init() != 0) {
    std::cerr << "Error initializing SDL TTF" << std::endl;
    return;
  }

  window = SDL_CreateWindow(constants::title.data(), SDL_WINDOWPOS_UNDEFINED,
                            SDL_WINDOWPOS_UNDEFINED, constants::WINDOW_WIDTH,
                            constants::WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE );
  if (!window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
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

  while (isRunning) {
    frame_start = SDL_GetTicks();
    ProcessInput();

    for (int i = 0; i < 20; ++i) {
      std::cout << "This machine run loop nr" << i << std::endl;
    }

    frame_end = SDL_GetTicks();
    frame_duration = frame_end - frame_start;
    frame_count++;

    if (frame_end - title_timestamp >= 1000) {
      UpdateWindowTitle(frame_count);
      frame_count = 0;
      title_timestamp = frame_end;
    }

    if (frame_duration < constants::FRAME_TARGET_TIME) {
      SDL_Delay(constants::FRAME_TARGET_TIME - frame_duration);
    }
  }
  Destroy();
}

void Game::UpdateWindowTitle(int fps) {
  std::string title{constants::title + "; FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(window, title.data());
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
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}