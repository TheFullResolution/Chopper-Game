//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#ifndef CHOPPERGAME_GAME_H
#define CHOPPERGAME_GAME_H

#include "../../gameEntities/Camera/Camera.h"
#include "../../gameEntities/Decoration/Decoration.h"
#include "../../gameEntities/Map/Map.h"
#include "../../gameEntities/Player/Player.h"
#include "../Renderer/Renderer.h"
#include <SDL.h>

class Game {
private:
  bool isRunning;
  Renderer *renderer;
  Map *map;
  Player *player;
  Camera *camera;
  SDL_Event event;
  std::vector<Decoration> decorations;
public:
  explicit Game(Renderer *renderer);
  void Run();
  void Update(float deltaTime);
  void ProcessInput();
  void CreateGameEntities();

};

#endif // CHOPPERGAME_GAME_H
