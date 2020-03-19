//
// Created by Jedrzej Lewandowski on 05/02/2020.
//

#include "Tile.h"

Tile::Tile(int sourceRectX, int sourceRectY, int x, int y, int tileSize,
           int tileScale) {
  sourceRectangle.x = sourceRectX;
  sourceRectangle.y = sourceRectY;
  sourceRectangle.h = tileSize;
  sourceRectangle.w = tileSize;

  destinationRectangle.x = x;
  destinationRectangle.y = y;
  destinationRectangle.w = tileScale * tileSize;
  destinationRectangle.h = tileScale * tileSize;
}

void Tile::Render(  SDL_Renderer *sdl_renderer, SDL_Texture *texture) {
  SDL_RenderCopyEx(sdl_renderer, texture, &sourceRectangle,
                   &destinationRectangle, 0.0, nullptr, SDL_FLIP_NONE);
}