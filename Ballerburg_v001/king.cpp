#include "king.h"
#include "sprite.h"
#include "graphic.h"
#include "input.h"
#include "sound.h"
#include <iostream>


King::King(Graphic &graphic, int posX, int posY) :
    posX(posX),
    posY(posY),
    hit(false)
{

     king = std::unique_ptr<Sprite>(new Sprite(graphic, "img/king.bmp", 0, 0, 30, 24));
}


void King::draw(Graphic& graphics)
{
    king->draw(graphics, posX, posY);
}

void King::update(Input &in,Sound& sound)
{
    onHit(in,sound);
    if(hit){
        std::cout << "Game over" << std::endl;

        hit = false;
    }
}

void King::onHit(Input &in, Sound &sound)
{
    if (isHit(in) && in.wasLeftMouseButtonPressed()) {
        hit = true;
        sound.playSound(2);
    }
}

bool King::isHit(Input &in)
{
    if(posX <= in.getoffsetX() && in.getoffsetX() <= (posX + 30))
    {
        if(posY <= in.getoffsetY() && in.getoffsetY() <= (posY + 24))
            return true;
        else
            return false;
    }
    else
        return false;
}
