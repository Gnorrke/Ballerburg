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


class Cannonball
{
public:
    Cannonball(Graphic &graphic, int posX, int posY);

    void update(int elapsedTime, std::vector<SDL_Rect> &map);
    void draw(Graphic& graphics);

private:

    double distance(int x1, int y1, int x2, int y2);
    bool checkCollision(Circle& A, std::vector<SDL_Rect> &B);

    void updateY(int elapsedTime, std::vector<SDL_Rect> &map);

    int posX, posY;
    bool collided;
    float velocityX, velocityY;

    Circle collisionCircle;

    std::unique_ptr<Sprite> spriteDot;
};

#endif // CANNONBALL_H