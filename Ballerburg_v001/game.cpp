#include "game.h"
#include "graphic.h"
#include "input.h"
#include "sprite.h"
#include "sound.h"
#include "backdrop.h"
#include "cannonball.h"
#include "castle.h"
#include "map.h"
#include "mountain.h"
#include "cannon.h"
#include "button.h"
#include "king.h"
#include "player.h"
#include "startmenu.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <iostream>

const int kFramesPerSecond = 60;
int Game::kScreenWidth = 640;
int Game::kScreenHeight = 360;
bool Game::running = true;
bool Game::menuRunning = true;
Player player1(1);
Player player2(2);

Game::Game()
{
    SDL_WM_SetCaption("Ballerburg! <3", NULL);
    if (SDL_Init(SDL_INIT_EVERYTHING) != -1) gameLoop();
}

Game::~Game()
{
    SDL_Quit();
}

void Game::gameLoop()
{
    Graphic graphics;
    Input input;
    SDL_Event event;

    background.reset(new Backdrop(graphics));
    map.reset(Map::createMap(graphics));
    cannon.reset(new Cannon(graphics, 70, 235,0));
    cannon2.reset(new Cannon(graphics, 440, 235,1));
    sounds.reset(new Sound());
    menu.reset(new StartMenu(graphics));

    // StartMenu
    runStartMenu(input, event, graphics);

    // actual Game





    int lastUpdatedTime = SDL_GetTicks();
    while (Game::running)
    {
        if(!player1.getTurn() && !player2.getTurn()) player1.setTurn();

        const int startTime = SDL_GetTicks();
        input.beginNewFrame();

        //Input Handling: Initialisation
        while(SDL_PollEvent(&event))
        {
            input.checkInput(event);
            if(player1.getTurn()) input.moveCannonball(event, *cannon, graphics);
            if(player2.getTurn()) input.moveCannonball(event, *cannon2, graphics);
        }

        if(input.wasKeyPressed(SDLK_SPACE)){

            if(player1.getTurn()){
                player1.resetTurn();
                player2.setTurn();

            }
            else{
                player2.resetTurn();
                player1.setTurn();
            }


        }



        //exit game
        if (input.wasKeyPressed(SDLK_ESCAPE) || event.type == SDL_QUIT) running = false;

        const int curTime = SDL_GetTicks();
        const unsigned int elapsedTime = curTime - lastUpdatedTime;

        update(elapsedTime, *map);
        lastUpdatedTime = curTime;

        if(player1.getTurn()) draw(graphics, input, cannon->getPosX(), cannon->getPosY());
        if(player2.getTurn()) draw(graphics, input, cannon2->getPosX(), cannon2->getPosY());


        //Frame Cap

        const int msPerFrame = 1000 / kFramesPerSecond;
        const int elapsedTimeMS = SDL_GetTicks() - startTime;

        if (elapsedTimeMS < msPerFrame) {
            SDL_Delay(msPerFrame - elapsedTimeMS );
        }
    }

    std::cout << "TEST" << std::endl;
    // StartMenu
    runStartMenu(input, event, graphics);
    SDL_Delay(2000);
}

void::Game::update(int elapsedTime, Map& mapParam)
{
    background->update(elapsedTime);
    map->update();
    cannon->update(elapsedTime, mapParam);
    cannon2->update(elapsedTime, mapParam);
}

void Game::draw(Graphic &graphics, Input& in, int canPosX, int canPosY)
{
    graphics.cleanUp();
    background->draw(graphics);
    cannon->draw(graphics);
    cannon2->draw(graphics);
    map->draw(graphics);
    graphics.drawLine(canPosY, canPosX, in.getoffsetY(), in.getoffsetX());

    graphics.flip();
}

void Game::runStartMenu(Input& input, SDL_Event& event, Graphic &graphics)
{
     std::cout << "TEST" << std::endl;
     //menuRunning = true;
     if(player1.getTurn()) {
         std::cout << " palyer1 hat gewonnen " << std::endl;
         menu->setWon();
         menu->setWho(1);
     }
     if(player2.getTurn()){

         std::cout << " palyer2 hat gewonnen " << std::endl;
         menu->setWon();
         menu->setWho(2);
    }

     // StartMenu
    while (Game::menuRunning) {


        input.beginNewFrame();

        while(SDL_PollEvent(&event))
        {
            input.checkInput(event);
        }
        const int startTime2 = SDL_GetTicks();
        menu->update(input);
        graphics.cleanUp();
        menu->draw(graphics);
        graphics.flip();
        const int msPerFrame2 = 1000 / kFramesPerSecond;
        const int elapsedTimeMS2 = SDL_GetTicks() - startTime2;

        if (elapsedTimeMS2 < msPerFrame2) {
            SDL_Delay(msPerFrame2 - elapsedTimeMS2 );
        }
    }
}
void Game::endGame(){
    Game::running = false;
    Game::menuRunning = false;
}


