#include "button.h"
#include "input.h"
#include "sprite.h"

Button::Button(int x, int y, int w, int h, Graphic& graphics, const std::string filepath)
{
    box = std::unique_ptr<SDL_Rect>(new SDL_Rect());
    sprite = std::unique_ptr<Sprite>(new Sprite(graphics, filepath, 0, 0, 150, 72));
    box->x = x;
    box->y = y;
    box->w = w;
    box->h = h;
}

bool Button::handleEvents(Input &in)
{
    if (in.wasLeftMouseButtonPressed()) {
        if (box->x <= in.getoffsetX() && in.getoffsetX() <= (box->x + box->w)) {
            if (box->y <= in.getoffsetY() && in.getoffsetY() <= (box->y + box->h)) {
                return true;
            }
            else return false;
        }
        else return false;
    }
    else return false;
}

void Button::draw(Graphic &graphics)
{
    sprite->draw(graphics, box->x, box->y);
}
