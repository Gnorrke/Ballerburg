#include <vector>
#include <iostream>
#include <cmath>

#include "cannon.h"
#include "graphic.h"
#include "block.h"
#include "sprite.h"
#include "input.h"
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

void Cannon::moveLeft(int x)
{
    if(ball) ball->moveLeft(x);
}

void Cannon::moveRight(int x)
{
    if(ball) ball->moveRight(x);
}

void Cannon::moveUp(int x)
{
    if(ball) ball->moveUp(x);
}

void Cannon::moveDown(int x)
{
    if(ball) ball->moveDown(x);
}

void Cannon::shoot(Graphic& graphics, int x1, int x2, int y1, int y2)
{
    ball = std::unique_ptr<Cannonball>(new Cannonball(graphics, posX, posY));
    int power = calculatePower(x1, x2, y1, y2);

    ball->moveUp(10);
    ball->moveRight(10);
    ball->stopMoving();
}


int Cannon::calculateAngle(int x1, int x2, int y1, int y2)
{
    return -atan2(x2 - y2, x1 - y1) * 180 / 3.1415;
}

int Cannon::calculatePower(int x1, int x2, int y1, int y2)
{
    return sqrt( pow( y2 - x2, 2 ) + pow( x1 - y1, 2 )) / 25;
}
