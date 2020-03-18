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
  Renderer(unsigned int screenWidth, unsigned int screenHeight,
           std::string title);
  ~Renderer();
  void Render(Map *map, std::vector<Decoration> *decorations, Player *player);
  void UpdateWindowTitle(unsigned int fps);

  SDL_Texture *LoadTexture(const char *filename);
  void Draw(SDL_Texture *texture, SDL_Rect sourceRectangle,
                   SDL_Rect destinationRectangle, SDL_RendererFlip flip);
private:
  std::string title;
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
};

#endif // CHOPPERGAME_RENDERER_H
