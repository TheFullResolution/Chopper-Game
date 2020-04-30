//
// Created by Jedrzej Lewandowski on 27/02/2020.
//

#ifndef CHOPPERGAME_PLAYER_H
#define CHOPPERGAME_PLAYER_H

#include <string>
#include "../../components/KeyboardControl/KeyboardControl.h"
#include "../../components/PositionState/PositionState.h"
#include "../../components/Sprite/Sprite.h"

class Player : public Sprite, public PositionState, public KeyboardControl {
 public:
  Player(SDL_Texture* texture, const types::Player& config);

  void Update(float deltaTime, SDL_Event* event,
              types::vector<float>& cameraPosition,
              const types::vector<float>& mapDimensions);
};

#endif  // CHOPPERGAME_PLAYER_H
