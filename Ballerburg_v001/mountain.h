#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include "mountainblock.h"
#include "input.h"
#include <memory>

class Sprite;
class Graphic;


class Mountain
{
public:
    Mountain(Graphic& graphics);
    ~Mountain();
    void update();
    void draw(Graphic& graphics);
    void checkHit(Input in);
private:
    std::unique_ptr<Mountainblock> mblocks[28];
};

#endif // MOUNTAIN_H
