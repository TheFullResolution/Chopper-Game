//
// Created by Jedrzej Lewandowski on 27/02/2020.
//

#include "Player.h"
Player::Player(SDL_Texture* texture, const types::Player& config)
    : Sprite(texture, config.animation->speed, config.animation->frame_width,
             config.animation->frame_height),
      PositionState(config.width, config.height, config.scale, config.x,
                    config.y) {
  Sprite::Initialize(&width, &height, &scale);
}

void Player::Update(float deltaTime, SDL_Event* event,
                    types::vector<float>& cameraPosition,
                    const types::vector<float>& mapDimensions) {
  KeyboardControl::Update(&velocity, &animationIndex, event);
  PositionState::Update(deltaTime, mapDimensions);
  Sprite::Update(&position, cameraPosition, &animationIndex, &height);
}
