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
  // Center camera over a player
  position.x = playerPosition.x - (dimensions.x / 2);
  position.y = playerPosition.y - (dimensions.y / 2);

  // Prevent from moving outside left and top boundary
  position.x = position.x < 0 ? 0 : position.x;
  position.y = position.y < 0 ? 0 : position.y;

  // Calculate space left for camera to move
  float mapLimitX = mapDimensions.x - dimensions.x;
  float mapLimitY = mapDimensions.y - dimensions.y;

  // Prevent from moving outside right and bottom boundary when camera is
  // smaller than map
  position.x = position.x > mapLimitX ? mapLimitX : position.x;
  position.y = position.y > mapLimitY ? mapLimitY : position.y;

  // Center camera when window bigger than the map
  float positionXCenter = ((dimensions.x - mapDimensions.x) / 2) * -1;
  float positionYCenter = ((dimensions.y - mapDimensions.y) / 2) * -1;

  position.x = dimensions.x > mapDimensions.x ? positionXCenter : position.x;
  position.y = dimensions.y > mapDimensions.y ? positionYCenter : position.y;
}

void Camera::setDimensions(float width, float height) {
  Camera::dimensions.x = width;
  Camera::dimensions.y = height;
}
