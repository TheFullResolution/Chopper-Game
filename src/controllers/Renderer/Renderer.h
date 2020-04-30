//
// Created by Jedrzej Lewandowski on 12/03/2020.
//

#ifndef CHOPPERGAME_RENDERER_H
#define CHOPPERGAME_RENDERER_H

#include <SDL.h>
#include <string>
#include "../../gameEntities/Decoration/Decoration.h"
#include "../../gameEntities/Map/Map.h"
#include "../../gameEntities/Player/Player.h"

class Renderer {
 public:
  explicit Renderer(const types::Game& config);
  ~Renderer();
  void Render(Map* map, std::vector<Decoration>* decorations, Player* player);
  void UpdateWindowTitle(unsigned int fps);

  SDL_Texture* LoadTexture(const char* filename);
  Uint32 getWindowId() const;

 private:
  std::string title;
  SDL_Window* sdl_window;
  SDL_Renderer* sdl_renderer;
  Uint32 sdl_windowID;
};

#endif  // CHOPPERGAME_RENDERER_H
