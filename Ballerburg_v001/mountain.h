#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "mountainblock.h"
#include <memory>

class Sprite;
class Graphic;
class Input;
class Sound;

class Mountain
{
public:
    Mountain(Graphic& graphics);
    ~Mountain();
    void update(Input &input, Sound &sound);
    void draw(Graphic& graphics);
    void checkHit(Input &in, Sound &sound);
private:
    std::unique_ptr<Mountainblock> mblocks[28];
};

#endif // MOUNTAIN_H
