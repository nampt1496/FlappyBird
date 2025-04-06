#include "sound.h"
#include <stdio.h>
#include <iostream>
#include <string>

bool sound::init()
{
    string breath_path = "sound/breath.wav";
    string hit_path = "sound/gameover.wav";

    bool success = true;

    if (SDL_Init(SDL_INIT_AUDIO) < 0)
    {
        printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        if( Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0 )
        {
            printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
        breath = Mix_LoadWAV( breath_path.c_str() );
        Mix_VolumeChunk(breath, 30);
        if (breath == NULL)
        {
            printf( "Failed to load chord! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }
        hit = Mix_LoadWAV( hit_path.c_str() );
        Mix_VolumeChunk(hit, 40);
        if (hit == NULL)
        {
            printf( "Failed to load chord! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }

        Mix_Music* music = Mix_LoadMUS("sound/nhacgame.mp3");
        Mix_VolumeMusic(30);
        if (!music) {
            printf( "Failed to load chord! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }

        if (Mix_PlayMusic(music, -1) == -1) {
            printf( "Failed to load chord! SDL_mixer Error: %s\n", Mix_GetError() );
            success = false;
        }


        Active.x = 0; Active.y = 0; Active.w = lTexture.getWidth(); Active.h = lTexture.getHeight() / 2;

        isPlay = true;
        }
        return success;
}

void sound::Free()
{
    lTexture.free();
    Mix_FreeChunk(hit);
    hit = NULL;
    Mix_FreeMusic(music);
    music= NULL;
    Mix_Quit();
}

void sound::playBreath()
{
    Mix_PlayChannel(-1, breath, 0);
}

void sound::playHit()
{

        Mix_PlayChannel(-1, hit, 0);

}
void sound::pauseMusic()
{
    Mix_PauseMusic();
}

void sound::resumeMusic()
{
     Mix_ResumeMusic();
}

void sound::renderSound()
{

    lTexture.Render(0, 0, 0, &Active);

}
