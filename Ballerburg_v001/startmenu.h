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
    void setWon();
    void setWho(int nr);
private:
    std::unique_ptr<Button> startButton;
    std::unique_ptr<Button> beendenButton;
    std::unique_ptr<Sprite> background;
    std::unique_ptr<Sprite> player1;
    std::unique_ptr<Sprite> player2;
    bool won = false;
    int who = 0;
};

#endif // STARTMENU_H
