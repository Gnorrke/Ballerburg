#include "castle.h"
#include "graphic.h"
#include "sprite.h"
#include <string>

namespace  {
const std::string kBlock1 = "img/castle_block1.bmp";
const std::string kblock2 = "img/castle_block2.bmp";
}

Castle::Castle(Graphic& graphics, int startposX)
{
    int tmp = startposX;
    cblocks[0] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 352, kBlock1));
    tmp += 30;
    cblocks[1] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 352, kBlock1));
    tmp += 30;
    cblocks[2] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 352, kBlock1));

    tmp = startposX;
    cblocks[3] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 344, kblock2));
    tmp += 30;
    cblocks[4] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 344, kblock2));
    tmp += 30;
    cblocks[5] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 344, kblock2));

    tmp = startposX;
    cblocks[6] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 336, kblock2));
    tmp += 15;
    cblocks[7] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 336, kblock2));
    tmp += 15;
    cblocks[8] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 336, kBlock1));
    tmp += 15;
    cblocks[9] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 336, kBlock1));
    tmp += 15;
    cblocks[10] = std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 336, kBlock1));

}

Castle::~Castle()
{

}

void Castle::update()
{


}

void Castle::draw(Graphic& graphics)
{
    for(int i = 0; i < 11;i++)
    {
        cblocks[i]->draw(graphics);
    }
}

void Castle::checkHit(Input &in)
{
    for(int j = 0; j < 11;j++)
    {
        cblocks[j]->onHit(in);
    }
}


