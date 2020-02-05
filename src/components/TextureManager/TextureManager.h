//
// Created by Jedrzej Lewandowski on 05/02/2020.
//

#ifndef CHOPPERGAME_TEXTUREMANAGER_H
#define CHOPPERGAME_TEXTUREMANAGER_H

#include <SDL_render.h>
class TextureManager {
public:
  static SDL_Texture *LoadTexture(const char *filename);

  static void Draw(SDL_Texture *texture, SDL_Rect sourceRectangle,
                   SDL_Rect destinationRectangle, SDL_RendererFlip flip);
};

#endif // CHOPPERGAME_TEXTUREMANAGER_H
