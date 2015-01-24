#include "graphic.h"
#include "game.h"
#include "tracer.h"
#include <cmath>
#include "SDL/SDL.h"

namespace {

const int kBitsPerPixel = 32;

}

Graphic::Graphic()
{
    screen = SDL_SetVideoMode(
                Game::kScreenWidth,
                Game::kScreenHeight,
                kBitsPerPixel,
                SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_ShowCursor(SDL_ENABLE);
}
Graphic::~Graphic()
{
    for (SpriteMap::iterator iter = spriteSheets.begin(); iter != spriteSheets.end(); ++iter) {
        SDL_FreeSurface(iter->second);
    }
    SDL_FreeSurface(screen);
}

void Graphic::blitSurface(SurfaceID src, SDL_Rect *src_rectangle, SDL_Rect *dest_rectangle)
{
    SDL_BlitSurface(src, src_rectangle, screen, dest_rectangle);
}

void Graphic::cleanUp()
{
    SDL_FillRect(screen, NULL, 0);
}

void Graphic::flip()
{
    SDL_Flip(screen);
}

void Graphic::drawLine(float x1, float y1, float x2, float y2)
{
    // Bresenham's line algorithm
     const bool steep = (fabs(y2 - y1) > fabs(x2 - x1));
     if(steep)
     {
         std::swap(x1, y1);
         std::swap(x2, y2);
     }

     if(x1 > x2)
     {
         std::swap(x1, x2);
         std::swap(y1, y2);
     }

     const float dx = x2 - x1;
     const float dy = fabs(y2 - y1);

     float error = dx / 2.0f;
     const int ystep = (y1 < y2) ? 1 : -1;
     int y = (int)y1;

     const int maxX = (int)x2;

     for(int x=(int)x1; x<maxX; x++)
     {
         if(steep)
         {
             setPixel(y, x);
         }
         else
         {
             setPixel(x, y);
         }

         error -= dy;
         if(error < 0)
         {
             y += ystep;
             error += dx;
         }
     }
}

void Graphic::setPixel(float x, float y)
{
    //Convert the pixels to 32 bit
    Uint32 *pixels = (Uint32 *)screen->pixels;

    //Set the pixel
    pixels[ ( (int)x * screen->w ) + (int)y ] = 0;
}

Graphic::SurfaceID Graphic::loadImage(const std::string &filePath)
{
    TRACE;
    //if the sheet isn't loaded yet
    if (spriteSheets.count(filePath) == 0) {
        spriteSheets[filePath] = SDL_DisplayFormat( SDL_LoadBMP(filePath.c_str()) );
        const Uint32 colorKey = SDL_MapRGB(spriteSheets[filePath]->format, 255, 0, 255);
        SDL_SetColorKey(spriteSheets[filePath], SDL_SRCCOLORKEY, colorKey);
    }
    return spriteSheets[filePath];
}
