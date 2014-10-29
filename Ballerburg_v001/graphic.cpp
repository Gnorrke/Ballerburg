#include "graphic.h"
#include "game.h"
#include "tracer.h"
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
                0);
    SDL_ShowCursor(SDL_DISABLE);
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
