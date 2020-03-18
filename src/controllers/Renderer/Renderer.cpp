//
// Created by Jedrzej Lewandowski on 12/03/2020.
//

#include "Renderer.h"

#include <SDL_image.h>
#include <SDL_ttf.h>
#include <iostream>

Renderer::Renderer(unsigned int screenWidth, unsigned int screenHeight,
                   std::string title): title(title) {
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "Error initializing SDL." << std::endl;
    return;
  }
  if (TTF_Init() != 0) {
    std::cerr << "Error initializing SDL TTF" << std::endl;
    return;
  }

  sdl_window = SDL_CreateWindow(title.data(), SDL_WINDOWPOS_UNDEFINED,
                                SDL_WINDOWPOS_UNDEFINED, screenWidth,
                                screenHeight, SDL_WINDOW_RESIZABLE);
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

void Renderer::Render(Map *map, std::vector<Decoration> *decorations,
                      Player *player) {
  SDL_SetRenderDrawColor(sdl_renderer, 158, 200, 92, 255);
  SDL_RenderClear(sdl_renderer);
  map->Render();

  for (auto &decoration : *decorations) {
    decoration.Render();
  }
  player->Render();

  SDL_RenderPresent(sdl_renderer);
}

SDL_Texture *Renderer::LoadTexture(const char *filename) {
  SDL_Surface *surface = IMG_Load(filename);
  SDL_Texture *texture = SDL_CreateTextureFromSurface(sdl_renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}

void Renderer::Draw(SDL_Texture *texture, SDL_Rect sourceRectangle,
                    SDL_Rect destinationRectangle, SDL_RendererFlip flip) {
  SDL_RenderCopyEx(sdl_renderer, texture, &sourceRectangle,
                   &destinationRectangle, 0.0, nullptr, flip);
}
