#include "castleblock.h"
#include "graphic.h"
#include "block.h"
#include "sprite.h"
#include <iostream>

namespace{
const std::string kFilePathCastleBlock1 = "img/castle_block1.bmp";
const std::string kFilePathCastleBlock2 = "img/castle_block2.bmp";

const int kCastleBlockWidth = 15;
const int kCastleBlockHeight = 8;
}

CastleBlock::CastleBlock(Graphic& graphics, int typeNumber, int X, int Y) : Block(X, Y)
{
    if (typeNumber == 1) {
        blockSprite = std::unique_ptr<Sprite>(new Sprite(graphics, kFilePathCastleBlock1, 0, 0, kCastleBlockWidth, kCastleBlockHeight));
    }
    else blockSprite = std::unique_ptr<Sprite>(new Sprite(graphics, kFilePathCastleBlock2, 0, 0, kCastleBlockWidth, kCastleBlockHeight));
}


