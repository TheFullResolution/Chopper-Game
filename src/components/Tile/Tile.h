//
// Created by Jedrzej Lewandowski on 05/02/2020.
//

#ifndef CHOPPERGAME_TILE_H
#define CHOPPERGAME_TILE_H

#include <SDL.h>
#include <SDL_image.h>
#include "../../types.h"

class Tile {
 private:
  types::vector<int> position;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;

 public:
  Tile(int sourceRectX, int sourceRectY, int x, int y, int tileSize,
       int tileScale);

  void Render(SDL_Renderer* sdl_renderer, SDL_Texture* texture);
  void Update(types::vector<float>& cameraPosition);
};

#endif  // CHOPPERGAME_TILE_H
