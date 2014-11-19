#ifndef GAME_H
#define GAME_H

#include <memory>

class Sprite;
class Graphic;
class Sound;

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
    void update();
    void draw(Graphic& graphics);

    std::unique_ptr<Sprite> background;
    std::unique_ptr<Sound> backgroundMusic;
};

#endif // GAME_H
