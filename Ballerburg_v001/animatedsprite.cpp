#include "animatedsprite.h"
#include "game.h"

AnimatedSprite::AnimatedSprite(Graphic& graphics,
                               const std::string& filepath,
                               int src_x, int src_y,
                               int width, int height,
                               int fps, int numFrames) :
    Sprite(graphics, filepath, src_x, src_y, width, height),
    frameTime(1000 / fps),
    numFrames(numFrames),
    curFrame(0),
    elapsedTime(0)
{
}


void AnimatedSprite::update(int elapsedTimeMs)
{
    elapsedTime += elapsedTimeMs;
    if(elapsedTime > frameTime) {
        ++curFrame;
        elapsedTime = 0;
        if(curFrame < numFrames) {
            srcRect.x += srcRect.w;
        }
        else {
            srcRect.x -= srcRect.w * (numFrames - 1);
            curFrame = 0;
        }
    }
}
