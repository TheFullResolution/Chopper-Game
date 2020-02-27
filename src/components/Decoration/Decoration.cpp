//
// Created by Jedrzej Lewandowski on 19/02/2020.
//

#include "Decoration.h"
Decoration::Decoration(const std::string &textureFile, int width, int height,
                       int x, int y)
    : Sprite(textureFile, width, height, x, y) {}
