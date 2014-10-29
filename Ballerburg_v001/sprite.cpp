#include "sprite.h"
#include "graphic.h"
#include <SDL/SDL.h>


Sprite::Sprite(Graphic& graphics,
               const std::string& filepath,
               int src_x, int src_y,
               int width, int height)
{
    spriteSheet = graphics.loadImage(filepath);
    srcRect.x = src_x;
    srcRect.y = src_y;
    srcRect.w = width;
    srcRect.h = height;
}

void Sprite::draw(Graphic& graphics, int x, int y)
{
    SDL_Rect destRectangle;
    destRectangle.x = x;
    destRectangle.y = y;
    graphics.blitSurface(spriteSheet, &srcRect, &destRectangle);
}
