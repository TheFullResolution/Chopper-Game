//
// Created by Jedrzej Lewandowski on 06/03/2020.
//

#include "PositionState.h"
PositionState::PositionState(int width, int height, int scale, int x, int y): width(width), height(height), scale(scale) {
        position.x = static_cast<float>(x);
        position.y = static_cast<float>(y);
        velocity.x = 0;
        velocity.y = 0;
        animationIndex = 1;

}
void PositionState::Update(float deltaTime){
    position.x += velocity.x * deltaTime;
    position.y += velocity.y * deltaTime;
}