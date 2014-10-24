#ifndef SPRITE_H
#define SPRITE_H

#include <string>
#include <SDL/SDL.h>

class Graphic;
class Sprite
{
public:
    Sprite(Graphic &graphics,
           const std::string& filepath,
           int src_x, int src_y,
           int width, int height);

    virtual void update(int) {}
    void draw(Graphic& graphics, int x, int y);

protected:
    SDL_Rect srcRect;

private:
    SDL_Surface* spriteSheet;
};

#endif // SPRITE_H
