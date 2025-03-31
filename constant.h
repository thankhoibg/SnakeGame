#ifndef _CONSTANT__H
#define _CONSTANT__H

#include <SDL.h>
#include <SDL_image.h>

const int SCREEN_WIDTH = 960;
const int SCREEN_HEIGHT = 640;
const int CELL_SIZE = 40;
const int BOARD_SIZE = 16;
const double TIME_BIG_FOOD = 4000;
const double TIME_SMALL_FOOD = 3000;
const int M = 5;
const int N = 2;
extern SDL_Window* gWindow;
extern SDL_Renderer* gRenderer;
const SDL_Color Red = {255, 0, 0, 255};
const SDL_Color White = {255, 255, 255, 255};
const SDL_Color Black = {0, 0, 0, 255};
const SDL_Color Ocean_Blue = {0, 84, 119};
const SDL_Color Yellow = {255, 255, 0};
const SDL_Color Green = {0, 128, 0};



#endif _CONSTANT__H
