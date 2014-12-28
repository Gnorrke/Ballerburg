#include "game.h"
#include "graphic.h"
#include "input.h"
#include "sprite.h"
#include "sound.h"
#include "backdrop.h"
#include "cannonball.h"
#include "castle.h"
#include "mountain.h"
#include "SDL/SDL.h"
#include "SDL/SDL_mixer.h"
#include <iostream>

const int kFramesPerSecond = 60;
int Game::kScreenWidth = 640;
int Game::kScreenHeight = 360;

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

    std::vector<SDL_Rect> box(1);

    box[0].x = 0;
    box[0].y = 360;
    box[0].w = 640;
    box[0].h = 0;

    background.reset(new Backdrop(graphics));
    testcastle.reset(new Castle(graphics, 50));
    testcastle2.reset(new Castle(graphics, 420));
    cannonball.reset(new Cannonball(graphics, 120, 0));
    mountain.reset(new Mountain(graphics));

    sounds.reset(new Sound());
    bool running = true;

    int lastUpdatedTime = SDL_GetTicks();

    while (running)
    {
        const int startTime = SDL_GetTicks();
        input.beginNewFrame();

        //Input Handling: Initialisation
        while(SDL_PollEvent(&event))
        {
            input.checkInput(event);
            input.moveCannonball(*cannonball);
        }

        //exit game
        if (input.wasKeyPressed(SDLK_ESCAPE) || event.type == SDL_QUIT) running = false;

        const int curTime = SDL_GetTicks();
        const unsigned int elapsedTime = curTime - lastUpdatedTime;

        update(elapsedTime, box, input, *sounds);
        lastUpdatedTime = curTime;

        draw(graphics);

        //Frame Cap

        const int msPerFrame = 1000 / kFramesPerSecond;
        const int elapsedTimeMS = SDL_GetTicks() - startTime;

        if (elapsedTimeMS < msPerFrame) {
            SDL_Delay(msPerFrame - elapsedTimeMS );
        }
    }
}

void::Game::update(int elapsedTime, std::vector<SDL_Rect>& map, Input& input, Sound& sound)
{
    background->update(elapsedTime);
    cannonball->update(elapsedTime, map);
    testcastle->update(input, sound);
    testcastle2->update(input, sound);
    mountain->update(input, sound);
}

void Game::draw(Graphic &graphics)
{
    graphics.cleanUp();

    background->draw(graphics);
    testcastle->draw(graphics);
    testcastle2->draw(graphics);
    cannonball->draw(graphics);
    mountain->draw(graphics);

    graphics.flip();
}
