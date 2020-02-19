//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#ifndef CHOPPERGAME_DECORATION_H
#define CHOPPERGAME_DECORATION_H

#include "../Sprite/Sprite.h"
class Decoration: public Sprite {
public:
  Decoration(const std::string &textureFile, int width, int height, int x,
             int y);
};

#endif // CHOPPERGAME_DECORATION_H
