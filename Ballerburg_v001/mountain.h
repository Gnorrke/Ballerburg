#ifndef MOUNTAIN_H
#define MOUNTAIN_H

#include <memory>
class Sprite;
class Graphic;


class Mountain
{
public:
    Mountain(Graphic& graphics);
    void update(int elapsedTime);
    void draw(Graphic& graphics);
private:
    std::unique_ptr<Sprite> testblock;
};

#endif // MOUNTAIN_H
