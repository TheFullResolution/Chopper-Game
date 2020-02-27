//
// Created by Jedrzej Lewandowski on 05/02/2020.
//

#include "Tile.h"
#include "../TextureManager/TextureManager.h"

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

void Tile::Render(SDL_Texture *texture) {
  TextureManager::Draw(texture, sourceRectangle, destinationRectangle,
                       SDL_FLIP_NONE);
}