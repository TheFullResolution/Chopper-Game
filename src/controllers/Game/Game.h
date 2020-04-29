//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#ifndef CHOPPERGAME_GAME_H
#define CHOPPERGAME_GAME_H

#include <SDL.h>
#include "../../gameEntities/Camera/Camera.h"
#include "../../gameEntities/Decoration/Decoration.h"
#include "../../gameEntities/Map/Map.h"
#include "../../gameEntities/Player/Player.h"
#include "../Renderer/Renderer.h"

class Game {
 private:
  bool isRunning;
  Renderer* renderer;
  Map* map;
  Player* player;
  Camera* camera;
  types::Config* config;
  SDL_Event event;
  std::vector<Decoration> decorations;
  float frame_target_time;

 public:
  explicit Game(Renderer* renderer, types::Config* config);
  void Run();
  void Update(float deltaTime);
  void ProcessInput();
  void CreateGameEntities();
};

#endif  // CHOPPERGAME_GAME_H
