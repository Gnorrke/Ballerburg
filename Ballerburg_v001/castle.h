#ifndef CASTLE_H
#define CASTLE_H

#include "castleblock.h"
#include "SDL/SDL.h"
#include <memory>
#include <vector>

class Sprite;
class Graphic;
class Input;


class Castle
{
public:
    Castle(Graphic& graphics, int startposX);
    ~Castle();

    void update();
    void draw(Graphic& graphics);

    std::vector<SDL_Rect> getMap();

    void deleteBlock(int index);
    CastleBlock &getBlock(int block);

    private:
    std::vector<std::unique_ptr<CastleBlock>> cblocks;
};


#endif // CASTLE_H
