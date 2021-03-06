#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>
#include "SDL/SDL.h"

class Sprite;
class Graphic;
class Sound;
class Backdrop;
class Cannon;
class Castle;
class SDL_Rect;
class Input;
class CastleBlock;
class Mountain;
class Map;
class Button;
class King;
class StartMenu;
class Player;

class Game
{
public:
    Game();
    ~Game();

    static int kScreenWidth;
    static int kScreenHeight;
    static bool running;
    static bool menuRunning;

    static void startGame() { Game::running = true; Game::menuRunning = false; }
    static void endGame();
    //void Line( float x1, float y1, float x2, float y2, const Color& color)
private:
    void gameLoop();
    void update(int elapsedTime, Map &map);
    void draw(Graphic& graphics, Input &in, int canPosX, int canPosY);

    void runStartMenu(Input &input, SDL_Event &event, Graphic &graphics);

    std::unique_ptr<Backdrop> background;
    std::unique_ptr<Cannon> cannon;
    std::unique_ptr<Cannon> cannon2;
    std::unique_ptr<Sound> sounds;
    std::unique_ptr<Map> map;
    std::unique_ptr<StartMenu> menu;

};

#endif // GAME_H
