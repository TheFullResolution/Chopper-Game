//
// Created by Jedrzej Lewandowski on 20/11/2019.
//
#ifndef consts_H
#define consts_H

#include <string>
namespace consts {
constexpr unsigned int WINDOW_WIDTH{800};
constexpr unsigned int WINDOW_HEIGHT{600};
constexpr unsigned int FPS{60};
constexpr unsigned int FRAME_TARGET_TIME{1000 / FPS};

inline std::string title("Chopper Game");

enum AnimationIndex {down, right, left, up};
} // namespace consts
#endif