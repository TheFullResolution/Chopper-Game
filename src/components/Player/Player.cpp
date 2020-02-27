//
// Created by Jedrzej Lewandowski on 27/02/2020.
//

#include "Player.h"
Player::Player(const std::string &textureFile, int width, int height, int x,
               int y)
    : Sprite(textureFile, width, height, x, y) {}
