#ifndef CASTLE_H
#define CASTLE_H

#include "castleblock.h"
#include <memory>

class Sprite;
class Graphic;
class Input;


class Castle
{
public:
    Castle(Graphic& graphics, int startposX);
    ~Castle();

    void update(Input &input, Sound &sound);
    void draw(Graphic& graphics);
    void checkHit(Input& in, Sound &sound);

private:
    std::unique_ptr<Castleblock> cblocks[11];
};


#endif // CASTLE_H
