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

void Block::onHit(Input &in, Sound &sound)
{
    if (isHit(in) && in.wasLeftMouseButtonPressed()) {
        hit = true;
        sound.playSound(1);
    }
}

bool Block::isHit(Input &in)
{
    if(posX <= in.getoffsetX() && in.getoffsetX() <= (posX + 20))
    {
        if(posY <= in.getoffsetY() && in.getoffsetY() <= (posY + 20))
            return true;
        else
            return false;
    }
    else
        return false;
}

SDL_Rect& Block::getCollisionRectangle()
{
    return *collisionRectangle;
}
