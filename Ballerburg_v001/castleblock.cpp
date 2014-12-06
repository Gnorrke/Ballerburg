#include "castleblock.h"


Castleblock::Castleblock(Graphic& graphics, int posx, int posy, const std::string& filePath)
{
    cblock=std::unique_ptr<Sprite>(new Sprite(graphics, filePath, 0, 0, 15, 8));
    x=posx;
    y=posy;
}

Castleblock::~Castleblock()
{

}


bool Castleblock::isHit(Input in)
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
void Castleblock::onHit(Input in)
{
    if(isHit(in) && in.wasLeftMouseButtonPressed())
        hit=true;
}

void Castleblock::draw(Graphic& graphics)
{
    if(!hit)
    {
        cblock->draw(graphics, x, y);
    }

}

int Castleblock::getX() const
{
    return x;
}

int Castleblock::getY() const
{
    return y;
}

