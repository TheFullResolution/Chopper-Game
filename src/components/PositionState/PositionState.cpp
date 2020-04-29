//
// Created by Jedrzej Lewandowski on 06/03/2020.
//

#include "PositionState.h"

PositionState::PositionState(int width, int height, int scale, int x, int y)
    : width(width), height(height), scale(scale) {
  position.x = x;
  position.y = y;
  velocity.x = 0;
  velocity.y = 0;
  animationIndex = types::AnimationIndex::down;
}
void PositionState::Update(float deltaTime) {
  position.x += velocity.x * deltaTime;
  position.y += velocity.y * deltaTime;
}
void PositionState::Update(float deltaTime,
                           types::vector<float> mapDimensions) {
  position.x += velocity.x * deltaTime;
  position.y += velocity.y * deltaTime;

  position.x = position.x < 0 ? 0 : position.x;
  position.y = position.y < 0 ? 0 : position.y;

  float mapLimitX = mapDimensions.x - static_cast<float>(width);
  float mapLimitY = mapDimensions.y - static_cast<float>(height);

  position.x =
      position.x >mapLimitX ? mapLimitX : position.x;
  position.y =
      position.y > mapLimitY ? mapLimitY : position.y;
}
