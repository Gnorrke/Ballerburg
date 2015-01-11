#include <vector>
#include <iostream>
#include <cmath>

#include "cannonball.h"
#include "sprite.h"
#include "graphic.h"
#include "circle.h"
#include "tracer.h"
#include "block.h"
#include "map.h"
#include "cannon.h"

namespace {
    const int kDotWidth = 20;
    const float kGravity = 0.0012f;
    const float kMaxSpeedX = 0.150f;
    const float kMaxSpeedY = 0.150f;
    const Circle kCollisionCircle(10, 10, 10);
}

Cannonball::Cannonball(Graphic &graphic, int posX, int posY) :
    posX(posX),
    posY(posY),
    collided(false),
    velocityX(0.0f),
    velocityY(0.0f),
    collisionCircle(kCollisionCircle)
{
    TRACE;
    spriteDot = std::unique_ptr<Sprite>(new Sprite(graphic, "img/dot.bmp", 0, 0, kDotWidth, kDotWidth));
}

void Cannonball::update(int elapsedTime, Map& map)
{
    //Physik
    updateX(elapsedTime, map);
    updateY(elapsedTime, map);
}

void Cannonball::draw(Graphic& graphics)
{
    spriteDot->draw(graphics, posX, posY);
}

void Cannonball::moveRight()
{
    velocityX = 2 * kMaxSpeedX;
}

void Cannonball::moveLeft()
{
    velocityX = 2 * -kMaxSpeedX;
}

void Cannonball::moveUp()
{
    velocityY = 4 * -kMaxSpeedY;
}

void Cannonball::moveDown()
{
    velocityY = kMaxSpeedY;
}

double Cannonball::distance(int x1, int y1, int x2, int y2)
{
    //Rückgabe: Distanz zwischen 2 Punkten zurück
    return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}

bool Cannonball::checkCollision(Circle &A, Map& B)
{
    //Closest point on collision box
    int cX, cY;

    //Go through the B boxes
    for(unsigned int Bbox = 0; Bbox < B.getCollisionMap().size(); Bbox++ )
    {
        //Find closest x offset
        if( A.x < B.getCollisionMap()[ Bbox ].x )
        {
            cX = B.getCollisionMap()[ Bbox ].x;
        }
        else if( A.x > B.getCollisionMap()[ Bbox ].x + B.getCollisionMap()[ Bbox ].w )
        {
            cX = B.getCollisionMap()[ Bbox ].x + B.getCollisionMap()[ Bbox ].w;
        }
        else
        {
            cX = A.x;
        }

        //Find closest y offset
        if( A.y < B.getCollisionMap()[ Bbox ].y )
        {
            cY = B.getCollisionMap()[ Bbox ].y;
        }
        else if( A.y > B.getCollisionMap()[ Bbox ].y + B.getCollisionMap()[ Bbox ].h )
        {
            cY = B.getCollisionMap()[ Bbox ].y + B.getCollisionMap()[ Bbox ].h;
        }
        else
        {
            cY = A.y;
        }

        //If the closest point is inside the circle
        if( distance( A.x, A.y, cX, cY ) < A.r )
        {
            //This box and the circle have collided
            B.deleteBlock(Bbox);
            return true;
        }
    }

    //If the shapes have not collided
    return false;
}

void Cannonball::updateX(int elapsedTime, Map& map)
{
    if(!collided) {
        if(checkCollision(collisionCircle, map)) {
            velocityX = 0.0f;
            collided = true;
        }
        else {
            if (velocityX < 0.0f) {
                velocityX = std::max(velocityX * elapsedTime, -kMaxSpeedX);
            }
            else {
                velocityX = std::min(velocityX * elapsedTime, kMaxSpeedX);
            }
            posX += (int)round(velocityX * elapsedTime);
            collisionCircle.x = posX;
        }
    }
}


void Cannonball::updateY(int elapsedTime, Map& map)
{
    if(!collided) {
        if(checkCollision(collisionCircle, map)) {
            velocityY = 0.0f;
            collided = true;
        }
        else {
            velocityY = std::min(velocityY + kGravity * elapsedTime, kMaxSpeedY);
            posY += (int)round(velocityY * elapsedTime);
            collisionCircle.y = posY;
        }
    }
}
