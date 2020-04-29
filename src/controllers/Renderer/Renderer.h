//
// Created by Jedrzej Lewandowski on 12/03/2020.
//

#ifndef CHOPPERGAME_RENDERER_H
#define CHOPPERGAME_RENDERER_H

#include "../../gameEntities/Decoration/Decoration.h"
#include "../../gameEntities/Map/Map.h"
#include "../../gameEntities/Player/Player.h"
#include <SDL.h>
#include <string>

class Renderer {
public:
  explicit Renderer(const types::Game& config);
  ~Renderer();
  void Render(Map *map, std::vector<Decoration> *decorations, Player *player);
  void UpdateWindowTitle(unsigned int fps);

  SDL_Texture *LoadTexture(const char *filename);

private:
  std::string title;
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  Uint32 sdl_windowID;

 public:
  Uint32 getWindowId() const;
};

#endif // CHOPPERGAME_RENDERER_H
