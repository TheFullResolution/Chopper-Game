//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#include "Sprite.h"
#include "../TextureManager/TextureManager.h"
#include <SDL_timer.h>

Sprite::Sprite(const std::string &textureFile)
    : isFixed(false), isAnimated(false), animationSpeed(0), frameWidth(0),
      frameHeight(0) {
  texture = TextureManager::LoadTexture(textureFile.c_str());
}

Sprite::Sprite(const std::string &textureFile, int animationSpeed,
               int frameWidth, int frameHeight)
    : isFixed(false), isAnimated(true), animationSpeed(animationSpeed),
      frameWidth(frameWidth), frameHeight(frameHeight) {

  texture = TextureManager::LoadTexture(textureFile.c_str());
}

void Sprite::Initialize(const int *width, const int *height, const int *scale) {
  sourceRectangle.x = 0;
  sourceRectangle.y = 0;
  sourceRectangle.h = *width;
  sourceRectangle.w = *height;

  destinationRectangle.w = *width * *scale;
  destinationRectangle.h = *height * *scale;
}

void Sprite::Update(utils::vector *position) {
  if (isAnimated) {
    sourceRectangle.x =
        sourceRectangle.w *
        static_cast<int>((SDL_GetTicks() / animationSpeed) % frameWidth);
  }
  destinationRectangle.x = static_cast<int>(position->x);
  destinationRectangle.y = static_cast<int>(position->y);
}

void Sprite::Update(utils::vector *position, const int *animationIndex,
                    const int *height) {
  if (isAnimated) {
    sourceRectangle.x =
        sourceRectangle.w *
        static_cast<int>((SDL_GetTicks() / animationSpeed) % frameWidth);
  }
  sourceRectangle.y = *animationIndex * *height;
  destinationRectangle.x = static_cast<int>(position->x);
  destinationRectangle.y = static_cast<int>(position->y);
}

void Sprite::Render() {
  TextureManager::Draw(texture, sourceRectangle, destinationRectangle,
                       SDL_FLIP_NONE);
}
