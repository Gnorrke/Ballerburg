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
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 352)));
        tmp += 15;
    }

    tmp = startposX;

    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 2, tmp, 344)));
        tmp += 15;
    }
    tmp = startposX;
    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 336)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 2, tmp, 328)));
        tmp += 15;
    }
    tmp = startposX + 105;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 328)));
        tmp += 15;
    }
    tmp = startposX + 105;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 2, tmp, 320)));
        tmp += 15;
    }
    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 2, tmp, 320)));
        tmp += 15;
    }
    tmp = startposX + 105;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 2, tmp, 312)));
        tmp += 15;
    }
    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 2, tmp, 312)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 304)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=10;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 2, tmp, 298)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 290)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 2, tmp, 282)));
        tmp += 15;
    }

    tmp = startposX;
    for(int i = 0;i<=3;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 276)));
        tmp += 15;
    }
    tmp = startposX + 10 ;
    for(int i = 0;i<=2;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 268)));
        tmp += 15;
    }
    tmp = startposX + 15 ;
    for(int i = 0;i<=1;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 260)));
        tmp += 15;
    }

    tmp = startposX + 30;
    for(int i = 0;i<=4;i++){
        cblocks.push_back(std::unique_ptr<CastleBlock>(new CastleBlock(graphics, 1, tmp, 290)));
        tmp += 30;
    }


}

Castle::~Castle()
{

}

void Castle::update(Input& input, Sound& sound)
{
    checkHit(input, sound);
    for(unsigned int i = 0; i < cblocks.size();i++)
    {
        if (!cblocks[i]->hit) cblocks[i]->update();
    }
}

void Castle::draw(Graphic& graphics)
{
    for(unsigned int i = 0; i < cblocks.size();i++)
    {
        if (!cblocks[i]->hit) cblocks[i]->draw(graphics);
    }
}

void Castle::checkHit(Input &in, Sound& sound)
{
    for(unsigned int j = 0; j < cblocks.size();j++)
    {
        if (!cblocks[j]->hit) cblocks[j]->onHit(in, sound);
    }
}

std::vector<SDL_Rect> Castle::getMap()
{
    std::vector<SDL_Rect> tmp(cblocks.size());

    for (unsigned int var = 0; var < cblocks.size(); ++var) {
        tmp[var] = *(new SDL_Rect(cblocks[var]->getCollisionRectangle()));
    }
    return tmp;
}

void Castle::deleteBlock(int index)
{
    cblocks.erase(cblocks.begin() + index);
}

