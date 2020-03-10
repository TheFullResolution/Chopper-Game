//
// Created by Jedrzej Lewandowski on 20/11/2019.
//
#ifndef consts_H
#define consts_H

#include <string>
namespace consts {
const unsigned int WINDOW_WIDTH{800};
const unsigned int WINDOW_HEIGHT{600};

const unsigned int FPS{60};
const unsigned int FRAME_TARGET_TIME{1000 / FPS};

inline std::string title("Chopper Game");

enum AnimationIndex {down, right, left, up};
} // namespace consts
#endif