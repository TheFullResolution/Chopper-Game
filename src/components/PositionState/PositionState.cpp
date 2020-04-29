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
  animationIndex = consts::AnimationIndex::down;
}
void PositionState::Update(float deltaTime) {
  position.x += velocity.x * deltaTime;
  position.y += velocity.y * deltaTime;
}
