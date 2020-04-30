//
// Created by Jedrzej Lewandowski on 22/04/2020.
//

#ifndef CHOPPERGAME_CAMERA_H
#define CHOPPERGAME_CAMERA_H

#include "../../types.h"
class Camera {
 private:
  types::vector<float> position{};
  types::vector<float> dimensions{};

 public:
  Camera(float x, float y, float width, float height);
  void Update(const types::vector<float>& playerPosition,
              const types::vector<float>& mapDimensions);

  types::vector<float>& getPosition();
  void setDimensions(float width, float height);
};

#endif  // CHOPPERGAME_CAMERA_H
