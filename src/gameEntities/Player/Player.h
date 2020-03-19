//
// Created by Jedrzej Lewandowski on 27/02/2020.
//

#ifndef CHOPPERGAME_PLAYER_H
#define CHOPPERGAME_PLAYER_H

#include "../../components/KeyboardControl/KeyboardControl.h"
#include "../../components/PositionState/PositionState.h"
#include "../../components/Sprite/Sprite.h"
#include <string>
class Player: public Sprite, public PositionState, public KeyboardControl {
public:
  Player(SDL_Texture *texture, int width, int height, int x,
         int y, int scale, int animationSpeed,int frameWidth, int frameHeight);

  void Update(float deltaTime, SDL_Event *event);

};

#endif // CHOPPERGAME_PLAYER_H
