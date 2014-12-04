#include <vector>

#include "cannonball.h"
#include "sprite.h"
#include "graphic.h"
#include "circle.h"
#include "tracer.h"

namespace {
    const int kDotWidth = 10;
    const Circle kCollisionCircle(10, 10, 10);
}

Cannonball::Cannonball(Graphic &graphic, int posX, int posY) :
    posX(posX),
    posY(posY),
    velocityX(0.0f),
    velocityY(0.0f),
    collisionCircle(kCollisionCircle)
{
    TRACE;
    spriteDot = std::unique_ptr<Sprite>(new Sprite(graphic, "img/dot.bmp", 0, 0, kDotWidth, kDotWidth));
}

void Cannonball::update()
{
    //TODO
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
    int cX, cY;

    for( unsigned int Bbox = 0; Bbox < B.size(); Bbox++ )
    {
        //suche den geringsten Abstand zu X
        if( A.offsetX < B[ Bbox ].x )
        {
            cX = B[ Bbox ].x;
        }

        else if( A.offsetX > B[ Bbox ].x + B[ Bbox ].w )
        {
            cX = B[ Bbox ].x + B[ Bbox ].w;
        }

        else
        {
            cX = A.offsetX;
        }

        //suche den geringsten Abstand zu Y
        if( A.offsetY < B[ Bbox ].y )
        {
            cY = B[ Bbox ].y;
        }
        else if( A.offsetY > B[ Bbox ].y + B[ Bbox ].h )
        {
            cY = B[ Bbox ].y + B[ Bbox ].h;
        }
        else
        {
            cY = A.offsetY;
        }

        if( distance( A.offsetX, A.offsetY, cX, cY ) < A.radius )
        {
            return true;
        }
    }
    //falls keine Kollision eintrat
    return false;
}

