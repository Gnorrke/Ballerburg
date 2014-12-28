#ifndef MOUNTAINBLOCK_H
#define MOUNTAINBLOCK_H

#include "block.h"
#include <memory>

class Graphic;

class MountainBlock : public Block
{
public:
    // Param: typeNumber, defines which sprite is taken, only 1 and 2 are valid numbers
    MountainBlock(Graphic &graphics, int posX, int posY);

    void destroy() { delete this; }
};

#endif // MOUNTAINBLOCK_H
