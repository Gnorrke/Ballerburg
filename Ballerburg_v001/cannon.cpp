#include <vector>

#include "cannon.h"
#include "graphic.h"
#include "block.h"
#include "sprite.h"
#include "cannonball.h"

Cannon::Cannon(Graphic& graphics, int posX, int posY) :
    posX(posX),
    posY(posY)
{
    cannon = std::unique_ptr<Sprite>(new Sprite(graphics, "img/cannon.bmp", 0, 0, 25, 25));
}

void Cannon::draw(Graphic &graphics)
{
    cannon->draw(graphics, posX, posY);
    if(ball) ball->draw(graphics);
}

void Cannon::update(int elapsedTime, Map& map)
{
    if(ball) ball->update(elapsedTime, map);
}

void Cannon::moveLeft()
{
    if(ball) ball->moveLeft();
}

void Cannon::moveRight()
{
    if(ball) ball->moveRight();
}

void Cannon::moveUp()
{
    if(ball) ball->moveUp();
}

void Cannon::moveDown()
{
    if(ball) ball->moveDown();
}

void Cannon::shoot(Graphic& graphics)
{
    ball = std::unique_ptr<Cannonball>(new Cannonball(graphics, posX, posY));


    for (int var = 0; var < 10; ++var) {
        ball->moveUp();
        ball->moveRight();
    }
}
