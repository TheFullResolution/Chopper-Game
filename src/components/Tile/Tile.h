//
// Created by Jedrzej Lewandowski on 05/02/2020.
//

#ifndef CHOPPERGAME_TILE_H
#define CHOPPERGAME_TILE_H

#include "../../_utils.h"
#include <SDL_render.h>

class Tile {
public:
  Tile(int sourceRectX, int sourceRectY, int x, int y, int tileSize,
       int tileScale);

  void Render(SDL_Renderer *sdl_renderer, SDL_Texture *texture);
  void Update(utils::vector &cameraPosition);

private:
  utils::vector position;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;
};

#endif // CHOPPERGAME_TILE_H
