#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <memory>
#include "graphic.h"
#include "sprite.h"



class mountain
{
public:
    mountain(Graphic& graphics);
    void update(int elapsedTime);
    void draw(Graphic& graphics);
    std::unique_ptr<Sprite> testblock;
};

#endif // MOUNTAIN_H
