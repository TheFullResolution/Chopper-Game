//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#ifndef CHOPPERGAME_SPRITE_H
#define CHOPPERGAME_SPRITE_H

#include "../../_consts.h"
#include "../../_utils.h"
#include <SDL_render.h>
#include <string>
class Sprite {

public:
  Sprite(const std::string &textureFile);
  Sprite(const std::string &textureFile, int animationSpeed, int frameWidth,
         int frameHeight);
  void Initialize(const int *width, const int *height, const int *scale);
  void Update(utils::vector *position,
              const consts::AnimationIndex *animationIndex, const int *height);
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
};

#endif // CHOPPERGAME_SPRITE_H
