//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#include "Sprite.h"
#include <SDL_timer.h>
#include "../../consts.h"

Sprite::Sprite(SDL_Texture* texture)
    : texture(texture),
      isFixed(false),
      isAnimated(false),
      animationSpeed(0),
      frameWidth(0),
      frameHeight(0) {}

Sprite::Sprite(SDL_Texture* texture, int animationSpeed, int frameWidth,
               int frameHeight)
    : texture(texture),
      isFixed(false),
      isAnimated(true),
      animationSpeed(animationSpeed),
      frameWidth(frameWidth),
      frameHeight(frameHeight) {}

void Sprite::Initialize(const int* width, const int* height, const int* scale) {
  sourceRectangle.x = 0;
  sourceRectangle.y = 0;
  sourceRectangle.h = *width;
  sourceRectangle.w = *height;

  destinationRectangle.w = *width * *scale;
  destinationRectangle.h = *height * *scale;
  destinationRectangle.x = 0;
  destinationRectangle.y = 0;
}

void Sprite::Update(types::vector<float>* position,
                    types::vector<float>& cameraPosition) {
  if (isAnimated) {
    sourceRectangle.x =
        sourceRectangle.w *
        static_cast<int>((SDL_GetTicks() / animationSpeed) % frameWidth);
  }
  destinationRectangle.x = static_cast<int>(position->x - (isFixed ? 0 : cameraPosition.x));
  destinationRectangle.y = static_cast<int>(position->y - (isFixed ? 0 : cameraPosition.y));
}

void Sprite::Update(types::vector<float>* position,
                    types::vector<float>& cameraPosition,
                    const consts::AnimationIndex* animationIndex,
                    const int* height) {
  if (isAnimated) {
    sourceRectangle.x =
        sourceRectangle.w *
        static_cast<int>((SDL_GetTicks() / animationSpeed) % frameWidth);
  }
  sourceRectangle.y = *animationIndex * *height;
  destinationRectangle.x = static_cast<int>(position->x - (isFixed ? 0 : cameraPosition.x));
  destinationRectangle.y = static_cast<int>(position->y - (isFixed ? 0 : cameraPosition.y));
}

void Sprite::Render(SDL_Renderer* sdl_renderer) {
  SDL_RenderCopyEx(sdl_renderer, texture, &sourceRectangle,
                   &destinationRectangle, 0.0, nullptr, SDL_FLIP_NONE);
}
