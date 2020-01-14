//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#ifndef CHOPPERGAME_GAME_H
#define CHOPPERGAME_GAME_H

#include <SDL.h>

class Game {
private:
  bool isRunning;
  SDL_Window *window;
  SDL_Renderer *renderer;

public:
  Game();
  [[nodiscard]] bool IsRunning() const;
};

#endif // CHOPPERGAME_GAME_H
