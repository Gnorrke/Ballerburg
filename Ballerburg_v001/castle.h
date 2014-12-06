#ifndef CASTLE_H
#define CASTLE_H

#include "castleblock.h"
#include "input.h"
#include <memory>

class Sprite;
class Graphic;


class Castle
{
public:
    Castle(Graphic& graphics, int startposX);
    ~Castle();
    void update();
    void draw(Graphic& graphics);
    void checkHit(Input in);
private:
    std::unique_ptr<Castleblock> cblocks[11];
    const std::string block1 = "img/castle_block1.bmp";
    const std::string block2 = "img/castle_block2.bmp";
};


#endif // CASTLE_H
