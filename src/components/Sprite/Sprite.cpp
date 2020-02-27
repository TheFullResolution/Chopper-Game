//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#include "Sprite.h"
#include "../TextureManager/TextureManager.h"

Sprite::Sprite(const std::string& textureFile, int width, int height, int x, int y) : isFixed(false), isAnimated(false) {
  texture = TextureManager::LoadTexture(textureFile.c_str());

  sourceRectangle.x = 0;
  sourceRectangle.y = 0;
  sourceRectangle.h = width;
  sourceRectangle.w = height;

  destinationRectangle.x = x;
  destinationRectangle.y = y;
  destinationRectangle.w = width;
  destinationRectangle.h = height;

}
void Sprite::Render() {
  TextureManager::Draw(texture, sourceRectangle, destinationRectangle, SDL_FLIP_NONE);
}
