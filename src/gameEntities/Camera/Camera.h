//
// Created by Jedrzej Lewandowski on 22/04/2020.
//

#ifndef CHOPPERGAME_CAMERA_H
#define CHOPPERGAME_CAMERA_H

#include "../../_utils.h"
class Camera {
public:
  Camera(float x, float y, float width, float height);
  void Update(const utils::vector &playerPosition);

  utils::vector &getPosition();
private:
  utils::vector position;
  float width;
  float height;
};

#endif // CHOPPERGAME_CAMERA_H
