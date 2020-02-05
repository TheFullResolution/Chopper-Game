//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#ifndef CHOPPERGAME_GAME_H
#define CHOPPERGAME_GAME_H

#include <SDL.h>

class Game {
private:
  bool isRunning;

public:
  Game();
  void Run();
  void Destroy();
  void ProcessInput();
  static void UpdateWindowTitle(int fps);
  void Render();
};

#endif // CHOPPERGAME_GAME_H
