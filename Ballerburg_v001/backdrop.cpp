#include "backdrop.h"
#include "sprite.h"

Backdrop::Backdrop(Graphic& graphics) : direction(true), posCloudX(200), posCloudY(30)
{
    background = std::unique_ptr<Sprite>(new Sprite(graphics, "img/background.bmp", 0, 0, 640, 360));
    backgroundCloud = std::unique_ptr<Sprite>(new Sprite(graphics, "img/cloud.bmp", 0, 0, 70, 35));
}

void Backdrop::draw(Graphic &graphics)
{
    background->draw(graphics, 0, 0);
    backgroundCloud->draw(graphics, posCloudX, posCloudY);
}

void Backdrop::update(int elapsedTime)
{
    if(posCloudX >= 400) direction = false;
    else if(posCloudX <= 200) direction = true;

    if(direction) posCloudX += elapsedTime * 0.003f;
    else posCloudX -= elapsedTime * 0.003f;
}
