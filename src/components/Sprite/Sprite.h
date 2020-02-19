//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#ifndef CHOPPERGAME_SPRITE_H
#define CHOPPERGAME_SPRITE_H

#include "../../_stucts.h"
#include <SDL_render.h>
#include <string>
class Sprite {
public:
  Sprite(const std::string &textureFile, int width, int height, int x, int y);
  void Render();

private:
  SDL_Texture *texture;
  bool isFixed;
  bool isAnimated;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;
};

#endif // CHOPPERGAME_SPRITE_H
