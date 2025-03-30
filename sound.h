#ifndef _SOUND__H
#define _SOUND__H

#include <iostream>
#include <vector>
#include <string>
#include <SDL_mixer.h>
#include "graphics.h"
#include "constant.h"

using namespace std;

struct Sound{
    Mix_Chunk *eat_apple;
    Mix_Music *back_ground_music;
    vector<string> music_list = {"BDSM.mp3", "Minecraft.mp3", "NOY.mp3", "TLO.mp3" };
    int cnt = 0;
    void init();
    void free();
    void playBackGroundMusic();
    void playEatAppleSound();

    Mix_Music *loadMusic(int music_index) {
        int len = music_list.size();
        music_index %= len;
        music_index += len;
        music_index %= len;
        string path = "sound\\" + music_list[music_index];
        cout << "Attempting to load: " << path << '\n';
        Mix_Music *gMusic = Mix_LoadMUS(path.c_str());
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                            "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
    Mix_Music *loadMusic(const char* path){
        Mix_Music *gMusic = Mix_LoadMUS(path);
        if (gMusic == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                            "Could not load music! SDL_mixer Error: %s", Mix_GetError());
        }
        return gMusic;
    }
    void play(Mix_Music *gMusic){
        if (gMusic == nullptr) return;

        if (Mix_PlayingMusic() == 0) {
            Mix_PlayMusic( gMusic, -1 );
        }
        else if( Mix_PausedMusic() == 1 ) {
            Mix_ResumeMusic();
        }
    }

    Mix_Chunk* loadSound(const char* path) {
        Mix_Chunk* gChunk = Mix_LoadWAV(path);
        if (gChunk == nullptr) {
            SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                       "Could not load sound! SDL_mixer Error: %s", Mix_GetError());
        }
    }
    void play(Mix_Chunk* gChunk) {
        if (gChunk != nullptr) {
            Mix_PlayChannel( -1, gChunk, 0 );
        }
    }
};

#endif // _SOUND__H
