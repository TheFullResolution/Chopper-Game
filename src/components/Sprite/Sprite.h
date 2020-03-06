//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#ifndef CHOPPERGAME_SPRITE_H
#define CHOPPERGAME_SPRITE_H

#include "../../_utils.h"
#include <SDL_render.h>
#include <string>
class Sprite {

public:
  Sprite(const std::string &textureFile, int width, int height, int scale);
  Sprite(const std::string &textureFile, int animationSpeed, int frameWidth,
         int frameHeight, int width, int height, int scale);
  void Update(utils::vector *position);
  void Render();

private:
  SDL_Texture *texture;
  bool isFixed;
  bool isAnimated;
  int animationSpeed;
  int frameWidth;
  int frameHeight;
  SDL_Rect sourceRectangle;
  SDL_Rect destinationRectangle;
  void Initialize(int width, int height, int scale);
};

#endif // CHOPPERGAME_SPRITE_H
