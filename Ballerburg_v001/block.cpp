#include "block.h"
#include "input.h"
#include "sound.h"
#include <sprite.h>

namespace {

const int kCastleBlockWidth = 15;
const int kCastleBlockHeight = 8;
const int kMountainBlockSize = 20;

const std::string kFilePathMountainBlock = "img/rock.bmp";
}

Block::Block(int posX, int posY) :
    posX(posX),
    posY(posY),
    hit(false)
{
    collisionRectangle = std::unique_ptr<SDL_Rect>(new SDL_Rect());
    collisionRectangle->x = posX;
    collisionRectangle->y = posY;
}


void Block::draw(Graphic &graphics)
{
    blockSprite->draw(graphics, posX, posY);
}

void Block::update()
{
    if(hit) destroy();
}

SDL_Rect& Block::getCollisionRectangle()
{
    return *collisionRectangle;
}
