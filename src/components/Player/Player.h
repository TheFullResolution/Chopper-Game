//
// Created by Jedrzej Lewandowski on 27/02/2020.
//

#ifndef CHOPPERGAME_PLAYER_H
#define CHOPPERGAME_PLAYER_H

#include "../Sprite/Sprite.h"
#include <string>
class Player: public Sprite {
public:
  Player(const std::string &textureFile, int width, int height, int x,
         int y);
};

#endif // CHOPPERGAME_PLAYER_H
