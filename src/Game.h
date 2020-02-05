//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#ifndef CHOPPERGAME_GAME_H
#define CHOPPERGAME_GAME_H

#include "components/Map/Map.h"
#include <SDL.h>

class Game {
private:
  bool isRunning;

public:
  Game();
  void Run();
  static void Destroy();
  void ProcessInput();
  static void UpdateWindowTitle(int fps);
  static void Render();
  static void LoadLevel();
};

#endif // CHOPPERGAME_GAME_H
