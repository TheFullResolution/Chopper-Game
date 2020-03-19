//
// Created by Jedrzej Lewandowski on 05/03/2020.
//

#ifndef CHOPPERGAME_KEYBOARDCONTROL_H
#define CHOPPERGAME_KEYBOARDCONTROL_H

#include "../../_consts.h"
#include "../../_utils.h"
#include <SDL_events.h>
#include <SDL_keycode.h>

class KeyboardControl {
public:
  KeyboardControl();
  void Update(utils::vector *velocity, consts::AnimationIndex *animationIndex,
              SDL_Event *event);

private:
  SDL_Keycode upKey;
  SDL_Keycode downKey;
  SDL_Keycode rightKey;
  SDL_Keycode leftKey;
  SDL_Keycode shootKey;
};

#endif // CHOPPERGAME_KEYBOARDCONTROL_H
