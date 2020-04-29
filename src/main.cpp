#include "./consts.h"
#include "controllers/Game/Game.h"
#include "controllers/Renderer/Renderer.h"
#include <iostream>

int main() {
  auto *renderer =
      new Renderer(consts::WINDOW_WIDTH, consts::WINDOW_HEIGHT, consts::title);

  auto *game = new Game(renderer);
  game->CreateGameEntities();
  game->Run();

  return 0;
}