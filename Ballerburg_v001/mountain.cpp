#include "mountain.h"
#include "graphic.h"
#include "sprite.h"


Mountain::Mountain(Graphic& graphics)
{
    mblocks[0] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 240, 340));
    mblocks[1] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 260, 340));
    mblocks[2] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 280, 340));
    mblocks[3] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 300, 340));
    mblocks[4] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 320, 340));
    mblocks[5] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 340, 340));
    mblocks[6] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 360, 340));

    mblocks[7] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 250, 320));
    mblocks[8] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 270, 320));
    mblocks[9] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 290, 320));
    mblocks[10] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 310, 320));
    mblocks[11] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 330, 320));
    mblocks[12] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 350, 320));

    mblocks[13] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 260, 300));
    mblocks[14] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 280, 300));
    mblocks[15] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 300, 300));
    mblocks[16] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 320, 300));
    mblocks[17] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 340, 300));

    mblocks[18] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 270, 280));
    mblocks[19] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 290, 280));
    mblocks[20] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 310, 280));
    mblocks[21] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 330, 280));

    mblocks[22] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 280, 260));
    mblocks[23] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 300, 260));
    mblocks[24] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 320, 260));

    mblocks[25] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 290, 240));
    mblocks[26] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 310, 240));

    mblocks[27] = std::unique_ptr<Mountainblock>(new Mountainblock(graphics, 300, 220));
}

Mountain::~Mountain()
{

}

void Mountain::update()
{


}

void Mountain::draw(Graphic& graphics)
{
    for(int i=0; i<28;i++)
    {
        mblocks[i]->draw(graphics);
    }
}

void Mountain::checkHit(Input in)
{
    for(int j=0; j<28;j++)
    {
        mblocks[j]->onHit(in);
    }
}

