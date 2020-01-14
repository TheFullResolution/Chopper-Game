//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#include "Game.h"
#include "_constants.h"
#include <SDL_ttf.h>
#include <iostream>

Game::Game() {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << std::endl;
    return;
  }
  if (TTF_Init() != 0) {
    std::cerr << "Error initializing SDL TTF" << std::endl;
    return;
  }

  window = SDL_CreateWindow(nullptr, SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, constants::WINDOW_WIDTH,
                            constants::WINDOW_HEIGHT, SDL_WINDOW_BORDERLESS);
  if (!window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }
  renderer = SDL_CreateRenderer(window, -1, 0);

  if (!renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }

  isRunning = true;
}

bool Game::IsRunning() const { return isRunning; }
