//
// Created by Jedrzej Lewandowski on 05/02/2020.
//
#include <SDL.h>

#ifndef CHOPPERGAME_SDLINSTANCES_H
#define CHOPPERGAME_SDLINSTANCES_H

class SDL_Instances {
public:
  static SDL_Renderer *renderer;
  static SDL_Window *window;
  static SDL_Event event;
};

#endif // CHOPPERGAME_SDLINSTANCES_H
