//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#include "Sprite.h"
#include "../TextureManager/TextureManager.h"
#include <SDL_timer.h>

Sprite::Sprite(const std::string &textureFile, int width, int height, int scale)
    : isFixed(false), isAnimated(false) {
  texture = TextureManager::LoadTexture(textureFile.c_str());

  Initialize(width, height, scale);
}

Sprite::Sprite(const std::string &textureFile, int animationSpeed,
               int frameWidth, int frameHeight, int width, int height, int scale)
    : isFixed(false), isAnimated(true), animationSpeed(animationSpeed),
      frameWidth(frameWidth), frameHeight(frameHeight) {

  texture = TextureManager::LoadTexture(textureFile.c_str());

  Initialize(width, height, scale);
}

void Sprite::Initialize(int width, int height, int scale) {
  sourceRectangle.x = 0;
  sourceRectangle.y = height;
  sourceRectangle.h = width;
  sourceRectangle.w = height;

  destinationRectangle.w = width * scale;
  destinationRectangle.h = height * scale;
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

void Sprite::Render() {
  TextureManager::Draw(texture, sourceRectangle, destinationRectangle,
                       SDL_FLIP_NONE);
}
