//
// Created by Jedrzej Lewandowski on 05/03/2020.
//

#ifndef CHOPPERGAME_KEYBOARDCONTROL_H
#define CHOPPERGAME_KEYBOARDCONTROL_H

#include <SDL.h>
#include "../../types.h"

class KeyboardControl {
 public:
  KeyboardControl();
  void Update(types::vector<int>* velocity,
              types::AnimationIndex* animationIndex, SDL_Event* event);

 private:
  SDL_Keycode upKey;
  SDL_Keycode downKey;
  SDL_Keycode rightKey;
  SDL_Keycode leftKey;
  SDL_Keycode shootKey;
};

#endif  // CHOPPERGAME_KEYBOARDCONTROL_H
