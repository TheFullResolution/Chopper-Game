//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#include "Decoration.h"
Decoration::Decoration(const std::string &textureFile, int width, int height,
                       int x, int y, int scale)
    : Sprite(textureFile, width, height, scale),
      PositionState(width, height, scale, x, y) {}

void Decoration::Update(float deltaTime) {
  PositionState::Update(deltaTime);
  Sprite::Update(&position);
}