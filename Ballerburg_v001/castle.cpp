#include "castle.h"
#include "graphic.h"
#include "sprite.h"
#include "sound.h"
#include <string>

namespace  {
const std::string kBlock1 = "img/castle_block1.bmp";
const std::string kblock2 = "img/castle_block2.bmp";
}

Castle::Castle(Graphic& graphics, int startposX)
{



    int tmp = startposX;

    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 352, kBlock1)));
        tmp += 15;
    }

    tmp = startposX;

    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 344, kblock2)));
        tmp += 15;
    }
    tmp = startposX;
    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 336, kBlock1)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 328, kblock2)));
        tmp += 15;
    }
    tmp = startposX + 105;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 328, kBlock1)));
        tmp += 15;
    }
    tmp = startposX + 105;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 320, kblock2)));
        tmp += 15;
    }
    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 320, kblock2)));
        tmp += 15;
    }
    tmp = startposX + 105;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 312, kblock2)));
        tmp += 15;
    }
    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 312, kblock2)));
        tmp += 15;
    }


    tmp = startposX;
    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 304, kBlock1)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 298, kblock2)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 290, kBlock1)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 282, kblock2)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 276, kBlock1)));
        tmp += 15;
    }
    tmp = startposX + 10 ;
    for(int i = 0;i<=2;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 268, kBlock1)));
        tmp += 15;
    }
    tmp = startposX + 15 ;
    for(int i = 0;i<=1;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 260, kBlock1)));
        tmp += 15;
    }

    tmp = startposX + 30;
    for(int i = 0;i<=4;i++){
        cblocks.push_back(std::unique_ptr<Castleblock>(new Castleblock(graphics, tmp, 290, kBlock1)));
        tmp += 30;
    }


}

Castle::~Castle()
{

}

void Castle::update(Input& input, Sound& sound)
{
    checkHit(input, sound);
}

void Castle::draw(Graphic& graphics)
{
    for(int i = 0; i < cblocks.size();i++)
    {
        cblocks[i]->draw(graphics);
    }
}

void Castle::checkHit(Input &in, Sound& sound)
{
    for(int j = 0; j < cblocks.size();j++)
    {
        cblocks[j]->onHit(in, sound);
    }
}


