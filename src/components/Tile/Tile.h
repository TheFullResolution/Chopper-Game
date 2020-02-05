//
// Created by Jedrzej Lewandowski on 05/02/2020.
//

#ifndef CHOPPERGAME_TILE_H
#define CHOPPERGAME_TILE_H

#include "../../_constants.h"
#include <SDL_render.h>
class Tile {
public:
  Tile(SDL_Texture *texture, int sourceRectX, int sourceRectY, int x, int y,
       int tileSize, int tileScale);

  virtual ~Tile();
  void Render();

  SDL_Texture *texture;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;
  consts::vector position;

};

#endif // CHOPPERGAME_TILE_H
