#ifndef CANNONBALL_H
#define CANNONBALL_H

#include <vector>
#include <cmath>
#include <memory>
#include "circle.h"

class Map;
class Sprite;
class Graphic;
class SDL_Rect;
class Block;
class Map;


class Cannonball
{
public:
    Cannonball(Graphic &graphic, int posX, int posY);

    void update(int elapsedTime, Map &map);
    void update(int elapsedTime, std::vector<Block> &map);
    void draw(Graphic& graphics);

    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();

    void stopMoving();

    bool hasCollided() { return collided; }

private:

    double distance(int x1, int y1, int x2, int y2);
    bool checkCollision(Circle& A, Map &B);

    void updateX(int elapsedTime, Map &map);
    void updateY(int elapsedTime, Map &map);

    int posX, posY;
    bool collided;
    float velocityX, velocityY;
    float accelerationX;

    Circle collisionCircle;

    std::unique_ptr<Sprite> spriteDot;
};

#endif // CANNONBALL_H
