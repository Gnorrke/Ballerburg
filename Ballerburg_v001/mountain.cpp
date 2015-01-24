#include "mountain.h"
#include "graphic.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"


Mountain::Mountain(Graphic& graphics)
{
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 240, 340)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 260, 340)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 280, 340)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 300, 340)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 320, 340)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 340, 340)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 360, 340)));

    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 250, 320)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 270, 320)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 290, 320)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 310, 320)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 330, 320)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 350, 320)));

    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 260, 300)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 280, 300)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 300, 300)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 320, 300)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 340, 300)));

    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 270, 280)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 290, 280)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 310, 280)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 330, 280)));

    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 280, 260)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 300, 260)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 320, 260)));

    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 290, 240)));
    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 310, 240)));

    mblocks.push_back(std::unique_ptr<MountainBlock>(new MountainBlock(graphics, 300, 220)));
}

void Mountain::draw(Graphic& graphics)
{
    for(unsigned int i = 0; i < mblocks.size(); i++)
    {
        if(!mblocks[i]->hit) mblocks[i]->draw(graphics);
    }
}


std::vector<SDL_Rect> Mountain::getMap()
{
    std::vector<SDL_Rect> tmp(mblocks.size());

    for (unsigned int var = 0; var < mblocks.size(); ++var) {
        tmp[var] = *(new SDL_Rect(mblocks[var]->getCollisionRectangle()));
    }
    return tmp;
}

void Mountain::deleteBlock(int index)
{
    mblocks.erase(mblocks.begin() + index);
}
