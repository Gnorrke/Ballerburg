#ifndef GAME_H
#define GAME_H

#include <memory>
#include <vector>

class Sprite;
class Graphic;
class Sound;
class Backdrop;
class Mountain;
class Cannonball;
class Castle;
class SDL_Rect;
class Input;

class Game
{
public:
    Game();
    ~Game();

    static int kTileSize;
    static int kSmallPlayerWidth;
    static int kSmallPlayerHeight;
    static int kBigPlayerWidth;
    static int kBigPlayerHeight;
    static int kScreenWidth;
    static int kScreenHeight;

private:
    void gameLoop();
    void update(int elapsedTime, std::vector<SDL_Rect>& map, Input &input, Sound &sound);
    void draw(Graphic& graphics);

    std::unique_ptr<Backdrop> background;
    std::unique_ptr<Castle> testcastle;
    std::unique_ptr<Castle> testcastle2;
    std::unique_ptr<Mountain> mountain;
    std::unique_ptr<Cannonball> cannonball;

    std::unique_ptr<Sound> sounds;
};

#endif // GAME_H
