//
// Created by Jedrzej Lewandowski on 22/04/2020.
//

#include "Camera.h"

types::vector<float>& Camera::getPosition() { return position; }

Camera::Camera(float x, float y, float width, float height) {
  position.x = x;
  position.y = y;
  dimensions.x = width;
  dimensions.y = height;
}

void Camera::Update(const types::vector<float>& playerPosition,
                    const types::vector<float>& mapDimensions) {
  position.x = playerPosition.x - (dimensions.x / 2);
  position.y = playerPosition.y - (dimensions.y / 2);

  position.x = position.x < 0 ? 0 : position.x;
  position.y = position.y < 0 ? 0 : position.y;

  float mapLimitX = mapDimensions.x - dimensions.x;
  float mapLimitY = mapDimensions.y - dimensions.y;

  position.x = position.x > mapLimitX ? mapLimitX : position.x;
  position.y = position.y > mapLimitY ? mapLimitY : position.y;
}

void Camera::setDimensions(float width, float height) {
  Camera::dimensions.x = width;
  Camera::dimensions.y = height;
}
