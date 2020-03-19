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
  explicit Sprite(SDL_Texture *texture);
  Sprite(SDL_Texture *texture, int animationSpeed, int frameWidth,
         int frameHeight);
  void Initialize(const int *width, const int *height, const int *scale);
  void Update(utils::vector *position,
              const consts::AnimationIndex *animationIndex, const int *height);
  void Update(utils::vector *position);
  void Render(SDL_Renderer *sdl_renderer);

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
