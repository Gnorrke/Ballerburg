#ifndef BLOCK_H
#define BLOCK_H

#include <memory>

class Graphic;
class Input;
class Sprite;
class Sound;
class SDL_Rect;


/*!
 * \brief Die Block Klasse bildet die Grundlage für die CastleBlock und MountainBlock Klassen.
 */
class Block
{
public:
    Block(int posX, int posY);

    void update();
    void draw(Graphic& graphics);
    void destroy() { delete this; }

    void onHit(Input& in, Sound& sound);
    bool isHit(Input& in);

    SDL_Rect &getCollisionRectangle();

    int posX, posY;
    bool hit;

    std::unique_ptr<Sprite> blockSprite;
    std::unique_ptr<SDL_Rect> collisionRectangle;

};

#endif // BLOCK_H
