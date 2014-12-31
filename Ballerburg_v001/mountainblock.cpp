#include "mountainblock.h"
#include "graphic.h"
#include "block.h"
#include "sprite.h"
#include <iostream>

namespace{
const std::string kFilePathMountainBlock = "img/rock.bmp";

const int kMountainBlockWidth = 20;
const int kMountainBlockHeight = 20;
}

MountainBlock::MountainBlock(Graphic& graphics,int X, int Y) : Block(X, Y)
{
    collisionRectangle->w = kMountainBlockWidth;
    collisionRectangle->h = kMountainBlockHeight;
    blockSprite = std::unique_ptr<Sprite>(new Sprite(graphics, kFilePathMountainBlock, 0, 0, kMountainBlockWidth, kMountainBlockHeight));
}

