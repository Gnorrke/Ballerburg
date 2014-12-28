#include "castleblock.h"
#include "sprite.h"
#include "input.h"
#include "sound.h"


CastleblockOLD::CastleblockOLD(Graphic& graphics, int posX, int posY, const std::string& filePath) : hit(false)
{
    cblock = std::unique_ptr<Sprite>(new Sprite(graphics, filePath, 0, 0, 15, 8));
    x = posX;
    y = posY;
}

CastleblockOLD::~CastleblockOLD()
{

}



//To be deleted after Sprint#2
void CastleblockOLD::onHit(Input& in, Sound& sound)
{
    if(isHit(in) && in.wasLeftMouseButtonPressed()) {
        hit=true;
        sound.playSound(1);
    }

}

void CastleblockOLD::draw(Graphic& graphics)
{
    if(!hit)
    {
        cblock->draw(graphics, x, y);
    }

}


bool CastleblockOLD::isHit(Input &in)
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
