#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <string>
#include <map>

class SDL_Surface;
class SDL_Rect;

class Graphic
{
public:
    typedef SDL_Surface* SurfaceID;

    Graphic();
    ~Graphic();

    SurfaceID loadImage(const std::string& filePath);

    void blitSurface(SurfaceID src,
                     SDL_Rect* src_rectangle,
                     SDL_Rect* dest_rectangle);


    void cleanUp();
    void flip();

private:
    typedef std::map<std::string, SDL_Surface*> SpriteMap;

    SpriteMap spriteSheets;
    SDL_Surface* screen;
};

#endif // GRAPHIC_H
