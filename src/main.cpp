#include <fstream>
#include "controllers/Game/Game.h"
#include "controllers/Renderer/Renderer.h"

int main() {
  std::ifstream config_json("assets/config.json");

  config::Config config = nlohmann::json::parse(config_json);

  auto* renderer = new Renderer(config.game);

  auto* game = new Game(renderer, &config);
  game->CreateGameEntities();
  game->Run();

  return 0;
}