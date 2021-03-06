//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#ifndef CHOPPERGAME_DECORATION_H
#define CHOPPERGAME_DECORATION_H

#include "../../components/PositionState/PositionState.h"
#include "../../components/Sprite/Sprite.h"

class Decoration : public Sprite, public PositionState {
 public:
  Decoration(SDL_Texture* texture, const types::Decoration& config);

  void Update(float deltaTime, types::vector<float>& cameraPosition);
};

#endif  // CHOPPERGAME_DECORATION_H
