//
// Created by Jedrzej Lewandowski on 20/11/2019.
//

#ifndef CHOPPERGAME__CONSTANTS_H
#define CHOPPERGAME__CONSTANTS_H

#include <string>
namespace consts {
const unsigned int WINDOW_WIDTH {800};
const unsigned int WINDOW_HEIGHT {600};

const unsigned int FPS {60};
const unsigned int FRAME_TARGET_TIME = 1000 / FPS;

std::string title ("Chopper Game");

struct vector {
  int x;
  int y;
};

} // namespace consts
#endif // CHOPPERGAME__CONSTANTS_H
