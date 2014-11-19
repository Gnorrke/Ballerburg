#include "sound.h"
#include <iostream>
#include "SDL/SDL_mixer.h"

Sound::Sound()
{
    if (Mix_OpenAudio( 44000, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1) std::cout << "Fehler" << std::endl;
    backgroundMusic = Mix_LoadMUS("sounds/theme.mp3");
    Mix_PlayMusic( backgroundMusic, -1 );
}

Sound::~Sound()
{
    Mix_FreeMusic(backgroundMusic);
    Mix_CloseAudio();
}
