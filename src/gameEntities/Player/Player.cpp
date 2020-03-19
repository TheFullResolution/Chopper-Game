//
// Created by Jedrzej Lewandowski on 27/02/2020.
//

#include "Player.h"
Player::Player(SDL_Texture *texture, int width, int height, int x,
               int y, int scale, int animationSpeed, int frameWidth,
               int frameHeight)
    : Sprite(texture, animationSpeed, frameWidth, frameHeight),
      PositionState(width, height, scale, x, y) {



  Sprite::Initialize(&width, &height, &scale);
}

void Player::Update(float deltaTime, SDL_Event *event) {
  PositionState::Update(deltaTime);
  Sprite::Update(&position, &animationIndex, &height);
  KeyboardControl::Update(&velocity, &animationIndex, event);
}
