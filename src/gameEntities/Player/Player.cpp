//
// Created by Jedrzej Lewandowski on 27/02/2020.
//

#include "Player.h"
Player::Player(const std::string &textureFile, int width, int height, int x,
               int y, int scale, int animationSpeed, int frameWidth,
               int frameHeight)
    : Sprite(textureFile, animationSpeed, frameWidth, frameHeight),
      PositionState(width, height, scale, x, y) {
  Sprite::Initialize(&width, &height, &scale);
}

void Player::Update(float deltaTime) {
  PositionState::Update(deltaTime);
  Sprite::Update(&position, &animationIndex, &height);
  KeyboardControl::Update(&velocity, &animationIndex);
}