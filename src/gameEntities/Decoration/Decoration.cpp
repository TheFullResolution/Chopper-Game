//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#include "Decoration.h"
Decoration::Decoration(SDL_Texture* texture, const types::Decoration& config)
    : Sprite(texture),
      PositionState(config.width, config.height, config.scale, config.x,
                    config.y) {
  Sprite::Initialize(&width, &height, &scale);
}

void Decoration::Update(float deltaTime, types::vector<float>& cameraPosition) {
  PositionState::Update(deltaTime);
  Sprite::Update(&position, cameraPosition);
}