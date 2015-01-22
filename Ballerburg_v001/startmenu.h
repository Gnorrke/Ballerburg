#ifndef STARTMENU_H
#define STARTMENU_H

#include <memory>

class Button;
class Graphic;
class Input;
class Sprite;

/*!
 * \brief Die StartMenu Klasse stellt das Menu zu Beginn des Spiels dar
 */
class StartMenu
{
public:
    StartMenu(Graphic& graphics);

    void update(Input& in);
    void draw(Graphic& graphics);

private:
    std::unique_ptr<Button> startButton;
    std::unique_ptr<Button> beendenButton;
    std::unique_ptr<Sprite> background;
};

#endif // STARTMENU_H
