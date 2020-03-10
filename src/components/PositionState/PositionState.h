//
// Created by Jedrzej Lewandowski on 06/03/2020.
//

#ifndef CHOPPERGAME_POSITIONSTATE_H
#define CHOPPERGAME_POSITIONSTATE_H

#include "../../_consts.h"
#include "../../_utils.h"

class PositionState {
public:
  PositionState(int width, int height, int scale,  int x,
                int y);
  virtual void Update(float deltaTime);
  utils::vector velocity;
  utils::vector position;
  consts::AnimationIndex animationIndex;
  int width;
  int height;
  int scale;
};

#endif // CHOPPERGAME_POSITIONSTATE_H
