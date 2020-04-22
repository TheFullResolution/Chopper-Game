//
// Created by Jedrzej Lewandowski on 22/04/2020.
//

#include "Camera.h"
utils::vector &Camera::getPosition() { return position; }


Camera::Camera(float x, float y, float width, float height)
    : width(width), height(height) {
  position.x = x;
  position.y = y;
}
void Camera::Update(const utils::vector &playerPosition) {
  position.x  = playerPosition.x - (width / 2);
  position.y = playerPosition.y - (height / 2);

  position.x = position.x < 0 ? 0 : position.x;
  position.y = position.y < 0 ? 0 : position.y;
  position.x = position.x > width ? width : position.x;
  position.y = position.y > height ? height : position.y;
}
