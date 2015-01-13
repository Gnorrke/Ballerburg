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

void King::update(Input &in,Sound& sound)
{
    onHit(in,sound);
    if(hit){
        std::cout << "Game over" << std::endl;
    }
}

void King::onHit(Input &in, Sound &sound)
{
    if ((isHit(in) && in.wasLeftMouseButtonPressed()) || hit) {
        hit = true;
        sound.playSound(2);
        SDL_Delay(2000);
        Game::endGame();
    }
}

void King::disable()
{
    hit = true;
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

