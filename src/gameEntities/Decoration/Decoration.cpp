//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#include "Decoration.h"
Decoration::Decoration(SDL_Texture *texture, int width, int height,
                       int x, int y, int scale)
    : Sprite(texture), PositionState(width, height, scale, x, y) {
  Sprite::Initialize(&width, &height, &scale);
}

void Decoration::Update(float deltaTime, utils::vector &cameraPosition) {
  PositionState::Update(deltaTime);
  Sprite::Update(&position, cameraPosition);
}