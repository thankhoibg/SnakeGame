#ifndef _GRAPHICS__H
#define _GRAPHICS__H

#include <SDL.h>

void initSDL();
void quitSDL();
void show();
void logErrorAndExit(const char* msg, const char* error);
//void render(SDL_Window* )

#endif // _GRAPHICS__H
