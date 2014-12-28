#ifndef CASTLEBLOCK_H
#define CASTLEBLOCK_H

#include "block.h"
#include <memory>

class Graphic;

class CastleBlock : public Block
{
public:
    // Param: typeNumber, defines which sprite is taken, only 1 and 2 are valid numbers
    CastleBlock(Graphic &graphics, int typeNumber, int posX, int posY);

    void destroy() { delete this; }
};

#endif // CASTLEBLOCK_H
