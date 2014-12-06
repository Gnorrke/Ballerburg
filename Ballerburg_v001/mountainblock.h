#ifndef MOUNTAINBLOCK_H
#define MOUNTAINBLOCK_H

#include <graphic.h>
#include <input.h>
#include <sprite.h>
#include <memory>

class Mountainblock
{
public:
    Mountainblock(Graphic& graphics, int posX, int posY);
    ~Mountainblock();

    //onHit erkennt, ob der entsprechende Block angeklickt wurde; muss in späteren Sprints entfernt werden
    void onHit(Input in);
    void draw(Graphic& draw);

    int getX() const;
    int getY() const;

private:
    //isHit kann später entfernt werden, da Kollisionserkennung über Cannonball realisiert wird
    bool isHit(Input in);
    //wird hit auf true gesetzt, wird der entsprechende Block nicht mehr gezeichnet
    bool hit;

    int x,y;

    std::unique_ptr<Sprite> mblock;
};

#endif // MOUNTAINBLOCK_H
