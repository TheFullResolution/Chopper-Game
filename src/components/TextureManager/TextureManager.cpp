//
// Created by Jedrzej Lewandowski on 05/02/2020.
//
#include "TextureManager.h"
#include "../../Game.h"
#include <SDL_image.h>

SDL_Texture *TextureManager::LoadTexture(const char *filename) {
  SDL_Surface *surface = IMG_Load(filename);
  SDL_Texture *texture =
      SDL_CreateTextureFromSurface(Game::sdl_renderer, surface);
  SDL_FreeSurface(surface);
  return texture;
}
void TextureManager::Draw(SDL_Texture *texture, SDL_Rect sourceRectangle,
                          SDL_Rect destinationRectangle,
                          SDL_RendererFlip flip) {
  SDL_RenderCopyEx(Game::sdl_renderer, texture, &sourceRectangle,
                   &destinationRectangle, 0.0, nullptr, flip);
}
