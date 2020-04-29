//
// Created by Jedrzej Lewandowski on 12/03/2020.
//

#include "Renderer.h"
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

Renderer::Renderer(const types::Game& config) : title(config.title) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << std::endl;
    return;
  }
  if (TTF_Init() != 0) {
    std::cerr << "Error initializing SDL TTF" << std::endl;
    return;
  }

  sdl_window =
      SDL_CreateWindow(title.data(), SDL_WINDOWPOS_UNDEFINED,
                       SDL_WINDOWPOS_UNDEFINED, config.initial_window_width,
                       config.initial_window_height, SDL_WINDOW_RESIZABLE);

  sdl_windowID = SDL_GetWindowID(sdl_window);

  if (nullptr == sdl_window) {
    std::cerr << "Error creating SDL window." << std::endl;
    return;
  }

  sdl_renderer = SDL_CreateRenderer(sdl_window, -1, SDL_RENDERER_ACCELERATED);

  if (nullptr == sdl_renderer) {
    std::cerr << "Error creating SDL renderer." << std::endl;
    return;
  }
}

void Renderer::UpdateWindowTitle(unsigned int fps) {
  std::string newTitle{title + "; FPS: " + std::to_string(fps)};
  SDL_SetWindowTitle(sdl_window, newTitle.data());
}
Renderer::~Renderer() {
  SDL_DestroyRenderer(sdl_renderer);
  SDL_DestroyWindow(sdl_window);
  SDL_Quit();
}

void Renderer::Render(Map* map, std::vector<Decoration>* decorations,
                      Player* player) {
  SDL_SetRenderDrawColor(sdl_renderer, 158, 200, 92, 255);
  SDL_RenderClear(sdl_renderer);
  map->Render(sdl_renderer);

  for (auto& decoration : *decorations) {
    decoration.Render(sdl_renderer);
  }
  player->Render(sdl_renderer);

  SDL_RenderPresent(sdl_renderer);
}

SDL_Texture* Renderer::LoadTexture(const char* filename) {
  SDL_Surface* surface = IMG_Load(filename);
  SDL_Texture* texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}

Uint32 Renderer::getWindowId() const { return sdl_windowID; }
