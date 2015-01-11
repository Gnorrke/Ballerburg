#ifndef CANNON_H
#define CANNON_H

#include <memory>
#include <vector>

class Graphic;
class Cannonball;
class Block;
class Sprite;
class SDL_Rect;
class Map;

class Cannon
{
public:
    Cannon(Graphic &graphics, int posX, int posY);

    void draw(Graphic& graphics);
    void update(int elapsedTime, Map &map);

    void moveLeft();
    void moveRight();

    void moveUp();
    void moveDown();

    void shoot(Graphic &graphics);

private:
    float posX, posY;

    std::unique_ptr<Cannonball> ball;
    std::unique_ptr<Sprite> cannon;
};

#endif // CANNON_H
