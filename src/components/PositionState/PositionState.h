//
// Created by Jedrzej Lewandowski on 06/03/2020.
//

#ifndef CHOPPERGAME_POSITIONSTATE_H
#define CHOPPERGAME_POSITIONSTATE_H

#include "../../consts.h"
#include "../../types.h"

class PositionState {
public:
  PositionState(int width, int height, int scale,  int x,
                int y);
  void Update(float deltaTime);
  types::vector<int> velocity;
  types::vector<float> position;
  consts::AnimationIndex animationIndex;
  int width;
  int height;
  int scale;
};

#endif // CHOPPERGAME_POSITIONSTATE_H
