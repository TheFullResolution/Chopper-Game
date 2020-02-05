#include "Game.h"
#include "SDL_Instances.h"
#include <iostream>

int main() {
  Game *game = new Game();
  new SDL_Instances();

  game->Run();

  return 0;
}