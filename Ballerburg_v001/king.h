#ifndef KING_H
#define KING_H

#include <memory>

class Sprite;
class Graphic;
class Input;
class Sound;
class SDL_Rect;

class King
{
public:
    King(Graphic& graphics,int posX, int posY);
    void draw(Graphic& graphics);
    void destroy() { delete this; }

    void disable();
    SDL_Rect& getCollisionRectangle() { return *collisionRectangle; }

private:
    int posX, posY;
    bool hit;

    std::unique_ptr<Sprite> king;
    SDL_Rect* collisionRectangle;
};

#endif // KING_H
