#include "mountain.h"


mountain::mountain(Graphic& graphics)
{
    testblock.reset(new Sprite(graphics, "img/rock.bmp", 0, 0, 20, 20));
    mountain::draw(graphics);

}

void mountain::update(int elapsedTime){


}

void mountain::draw(Graphic& graphics){



    testblock->draw(graphics,240,340);
    testblock->draw(graphics,260,340);
    testblock->draw(graphics,280,340);
    testblock->draw(graphics,300,340);
    testblock->draw(graphics,320,340);
    testblock->draw(graphics,340,340);
    testblock->draw(graphics,360,340);


    testblock->draw(graphics,250,320);
    testblock->draw(graphics,260,320);
    testblock->draw(graphics,280,320);
    testblock->draw(graphics,300,320);
    testblock->draw(graphics,320,320);
    testblock->draw(graphics,340,320);
    testblock->draw(graphics,350,320);

    testblock->draw(graphics,260,300);
    testblock->draw(graphics,280,300);
    testblock->draw(graphics,300,300);
    testblock->draw(graphics,320,300);
    testblock->draw(graphics,340,300);

    testblock->draw(graphics,280,280);
    testblock->draw(graphics,300,280);
    testblock->draw(graphics,320,280);
    testblock->draw(graphics,330,280);

    testblock->draw(graphics,290,260);
    testblock->draw(graphics,310,260);
    testblock->draw(graphics,330,260);

    testblock->draw(graphics,300,240);
    testblock->draw(graphics,320,240);

    testblock->draw(graphics,310,220);




}

