#ifndef CASTLE_H
#define CASTLE_H

#include "castleblock.h"
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

    void update(Input &input, Sound &sound);
    void draw(Graphic& graphics);
    void checkHit(Input& in, Sound &sound);

private:
    std::vector<std::unique_ptr<CastleBlock>> cblocks;
};


#endif // CASTLE_H
