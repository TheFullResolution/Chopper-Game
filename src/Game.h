//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#ifndef CHOPPERGAME_GAME_H
#define CHOPPERGAME_GAME_H

#include <SDL.h>

class Game {
private:
  bool isRunning;
  static SDL_Window *sdl_window;

public:
  Game();
  void Run();
  static void Update(float deltaTime);
  static void Destroy();
  void ProcessInput();
  static void UpdateWindowTitle(int fps);
  static void Render();
  static void LoadLevel();

  static SDL_Renderer *sdl_renderer;
  static SDL_Event event;
};

#endif // CHOPPERGAME_GAME_H
