#include "mountainblock.h"


Mountainblock::Mountainblock(Graphic& graphics, int posx, int posy)
{
    mblock=std::unique_ptr<Sprite>(new Sprite(graphics, "img/rock.bmp", 0, 0, 20, 20));
    x=posx;
    y=posy;
}

Mountainblock::~Mountainblock()
{

}


bool Mountainblock::isHit(Input in)
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
void Mountainblock::onHit(Input in)
{
    if(isHit(in) && in.wasLeftMouseButtonPressed())
        hit=true;
}

void Mountainblock::draw(Graphic& graphics)
{
    if(!hit)
    {
        mblock->draw(graphics, x, y);
    }

}

int Mountainblock::getX() const
{
    return x;
}

int Mountainblock::getY() const
{
    return y;
}
