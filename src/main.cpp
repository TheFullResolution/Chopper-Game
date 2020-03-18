#include "controllers/Game/Game.h"
#include "controllers/Renderer/Renderer.h"
#include <iostream>
#include "./_consts.h"

int main() {
  auto *renderer = new Renderer(consts::WINDOW_WIDTH, consts::WINDOW_HEIGHT, consts::title);

  Game *game = new Game(renderer);

  game->Run();

  return 0;
}