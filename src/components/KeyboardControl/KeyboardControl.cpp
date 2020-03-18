//
// Created by Jedrzej Lewandowski on 05/03/2020.
//

#include "KeyboardControl.h"
#include "../../_consts.h"
#include "../../_utils.h"
#include <SDL_events.h>
#include <SDL_keycode.h>

KeyboardControl::KeyboardControl() {
  upKey = SDLK_UP;
  downKey = SDLK_DOWN;
  rightKey = SDLK_RIGHT;
  leftKey = SDLK_LEFT;
  shootKey = SDLK_SPACE;
}
void KeyboardControl::Update(utils::vector *velocity, consts::AnimationIndex *animationIndex,   SDL_Event *event) {
  if (event->type == SDL_KEYDOWN) {
    auto keyCode = event->key.keysym.sym;
    if (keyCode == upKey) {
      velocity->y = -40;
      velocity->x = 0;
      *animationIndex = consts::AnimationIndex::up;
    }

    if (keyCode == downKey) {
      velocity->y = 40;
      velocity->x = 0;
      *animationIndex = consts::AnimationIndex::down;
    }

    if (keyCode == rightKey) {
      velocity->y = 0;
      velocity->x = 40;
      *animationIndex = consts::AnimationIndex::right;
    }

    if (keyCode == leftKey) {
      velocity->y = 0;
      velocity->x = -40;
      *animationIndex = consts::AnimationIndex::left;
    }
  } else if (event->type == SDL_KEYUP) {
    auto keyCode = event->key.keysym.sym;
    if (keyCode == upKey) {
      velocity->y = 0;
    }

    if (keyCode == downKey) {
      velocity->y = 0;
    }

    if (keyCode == rightKey) {
      velocity->x = 0;
    }

    if (keyCode == leftKey) {
      velocity->x = 0;
    }
  }
}
