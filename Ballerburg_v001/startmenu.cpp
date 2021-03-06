#include "startmenu.h"
#include "button.h"
#include "game.h"

StartMenu::StartMenu(Graphic &graphics)
{
    startButton = std::unique_ptr<Button>(new Button(
                                              Game::kScreenWidth/2 - 75,
                                              Game::kScreenHeight/2 - 40,
                                              150, 72, graphics,
                                              "img/button_start.bmp"));

    beendenButton = std::unique_ptr<Button>(new Button(
                                              Game::kScreenWidth/2 - 75,
                                              Game::kScreenHeight/2 + 40,
                                              150, 72, graphics,
                                              "img/button_beenden.bmp"));

    background = std::unique_ptr<Sprite>(new Sprite(graphics, "img/backgroundMenu.bmp", 0, 0, 640, 360));

    player1 = std::unique_ptr<Sprite>(new Sprite(graphics, "img/won1.bmp", 0, 0, 224, 90));
    player2 = std::unique_ptr<Sprite>(new Sprite(graphics, "img/won2.bmp", 0, 0, 224, 90));
}

void StartMenu::update(Input &in)
{
    if (startButton->handleEvents(in)){
        Game::startGame();
    }
    if (beendenButton->handleEvents(in)) Game::endGame();
}

void StartMenu::draw(Graphic &graphics)
{
    background->draw(graphics, 0, 0);
    startButton->draw(graphics);
    beendenButton->draw(graphics);
    if(won && who == 1) player1->draw(graphics, 0, 200);
    if(won && who == 2) player2->draw(graphics, 0, 200);
}

void StartMenu::setWon(){

    won = true;

}

void StartMenu::setWho(int nr){

    who = nr;

}
