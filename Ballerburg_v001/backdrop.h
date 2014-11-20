#ifndef BACKLOG_H
#define BACKLOG_H

#include <memory>

class Sprite;
class Graphic;

class Backdrop
{
public:
    Backdrop(Graphic& graphics);

    void draw(Graphic& graphics);
    void update(int elapsedTime);

private:
    bool direction;
    float posCloudX, posCloudY;

    std::unique_ptr<Sprite> background;
    std::unique_ptr<Sprite> backgroundCloud;
};

#endif // BACKLOG_H
