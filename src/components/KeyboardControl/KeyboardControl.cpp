//
// Created by Jedrzej Lewandowski on 05/03/2020.
//

#include "KeyboardControl.h"
#include "../../Game.h"
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
void KeyboardControl::Update(utils::vector *velocity, int *animationIndex) {
  if (Game::event.type == SDL_KEYDOWN) {
    auto keyCode = Game::event.key.keysym.sym;
    if (keyCode == upKey) {
      velocity->y = 0;
      velocity->x = -40;
      *animationIndex = 4;
    }

    if (keyCode == downKey) {
      velocity->y = 40;
      velocity->x = 0;
      *animationIndex = 1;
    }

    if (keyCode == rightKey) {
      velocity->y = 0;
      velocity->x = 40;
      *animationIndex = 2;
    }

    if (keyCode == leftKey) {
      velocity->y = 0;
      velocity->x = 40;
      *animationIndex = 3;
    }
  } else if (Game::event.type == SDL_KEYUP) {
    auto keyCode = Game::event.key.keysym.sym;
    if (keyCode == upKey) {
      velocity->x = 0;
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
