#ifndef ANIMATEDSPRITE_H
#define ANIMATEDSPRITE_H

#include "sprite.h"

class Graphic;

class AnimatedSprite : public Sprite
{
public:
    AnimatedSprite(Graphic &graphics, const std::string& filepath,
                   int src_x, int src_y,
                   int width, int height,
                   int fps, int numFrames);

    void update(int elapsedTimeMs);

private:
    const int frameTime;
    const int numFrames;
    int curFrame;
    int elapsedTime; //elapsed time since the last frame change
};

#endif // ANIMATEDSPRITE_H
