#include "king.h"
#include "sprite.h"
#include "graphic.h"
#include "input.h"
#include "sound.h"
#include "unistd.h"
#include "game.h"
#include <iostream>


King::King(Graphic &graphic, int posX, int posY) :
    posX(posX),
    posY(posY),
    hit(false)
{
    collisionRectangle = new SDL_Rect();
    collisionRectangle->h = 24;
    collisionRectangle->w = 30;
    collisionRectangle->x = posX;
    collisionRectangle->y = posY;
    king = std::unique_ptr<Sprite>(new Sprite(graphic, "img/king.bmp", 0, 0, 30, 24));
}


void King::draw(Graphic& graphics)
{
    if (!hit)king->draw(graphics, posX, posY);
}

void King::disable()
{
    hit = true;
}
