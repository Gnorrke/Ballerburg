#ifndef BLOCK_H
#define BLOCK_H

#include <memory>

class Graphic;
class Input;
class Sprite;
class Sound;

class Block
{
public:
    Block(int posX, int posY);

    void update();
    void draw(Graphic& graphics);
    void destroy() { delete this; }

    void onHit(Input& in, Sound& sound);
    bool isHit(Input& in);

    int posX, posY;
    bool hit;

    std::unique_ptr<Sprite> blockSprite;

};

#endif // BLOCK_H
