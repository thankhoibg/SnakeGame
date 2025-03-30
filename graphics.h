#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>
#include <SDL_mixer.h>

void initSDL();
void quitSDL();
void show();
void logErrorAndExit(const char* msg, const char* error);
Mix_Music *loadMusic(const char* path);
void play(Mix_Music *gMusic);
Mix_Chunk* loadSound(const char* path);
void play(Mix_Chunk* gChunk);
//void render(SDL_Window* )

#endif // _GRAPHICS__H
