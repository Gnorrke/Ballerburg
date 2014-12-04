#include <vector>
#include <iostream>
#include <cmath>

#include "cannonball.h"
#include "sprite.h"
#include "graphic.h"
#include "circle.h"
#include "tracer.h"

namespace {
    const int kDotWidth = 20;
    const float kGravity = 0.0012f;
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

void Cannonball::update(int elapsedTime, std::vector<SDL_Rect>& map)
{
    //Physik
    updateY(elapsedTime, map);
}

void Cannonball::draw(Graphic& graphics)
{
    spriteDot->draw(graphics, posX, posY);
}


double Cannonball::distance(int x1, int y1, int x2, int y2)
{
    //Rückgabe: Distanz zwischen 2 Punkten zurück
    return sqrt( pow( x2 - x1, 2 ) + pow( y2 - y1, 2 ) );
}

bool Cannonball::checkCollision(Circle &A, std::vector<SDL_Rect>& B)
{
    //Closest point on collision box
    int cX, cY;

    //Go through the B boxes
    for(unsigned int Bbox = 0; Bbox < B.size(); Bbox++ )
    {
        //Find closest x offset
        if( A.x < B[ Bbox ].x )
        {
            cX = B[ Bbox ].x;
        }
        else if( A.x > B[ Bbox ].x + B[ Bbox ].w )
        {
            cX = B[ Bbox ].x + B[ Bbox ].w;
        }
        else
        {
            cX = A.x;
        }

        //Find closest y offset
        if( A.y < B[ Bbox ].y )
        {
            cY = B[ Bbox ].y;
        }
        else if( A.y > B[ Bbox ].y + B[ Bbox ].h )
        {
            cY = B[ Bbox ].y + B[ Bbox ].h;
        }
        else
        {
            cY = A.y;
        }

        //If the closest point is inside the circle
        if( distance( A.x, A.y, cX, cY ) < A.r )
        {
            //This box and the circle have collided
            return true;
        }
    }

    //If the shapes have not collided
    return false;
}

void Cannonball::updateY(int elapsedTime, std::vector<SDL_Rect> &map)
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
