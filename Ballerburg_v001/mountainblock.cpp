#include "mountainblock.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"


Mountainblock::Mountainblock(Graphic& graphics, int posX, int posY) : hit(false)
{
    mblock = std::unique_ptr<Sprite>(new Sprite(graphics, "img/rock.bmp", 0, 0, 20, 20));
    x = posX;
    y = posY;
}

Mountainblock::~Mountainblock()
{

}


bool Mountainblock::isHit(Input &in)
{
    if(x<=in.getoffsetX() && in.getoffsetX()<=(x+20))
    {
        if(y<=in.getoffsetY() && in.getoffsetY()<=(y+20))
            return true;
        else
            return false;
    }
    else
        return false;
}

//To be deleted after Sprint#2
void Mountainblock::onHit(Input& in, Sound& sound)
{
    if(isHit(in) && in.wasLeftMouseButtonPressed()) {
        hit=true;
    }
}

void Mountainblock::draw(Graphic& graphics)
{
    if(!hit)
    {
        mblock->draw(graphics, x, y);
    }

}


