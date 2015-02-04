#ifndef SOUND_H
#define SOUND_H

#include <memory>
#include "sdl/SDL_mixer.h"

/*!
 * \brief Die Sound spielt die Hintergrund Musik und Sounds ab
 */
class Sound
{
public:
    Sound();
    ~Sound();

    void playSound(int soundNumber);
private:
    Mix_Music* backgroundMusic = NULL;
    Mix_Chunk* explosionSound = NULL;
    Mix_Chunk* winSound = NULL;
};

#endif // SOUND_H
