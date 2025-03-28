#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

#include "graphics.h"
#include "constant.h"

using namespace std;

void initSDL(){
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << endl;
        return ;
    }

    gWindow = SDL_CreateWindow("Caro Board", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (gWindow == NULL) {
        cout << "Window could not be created! SDL_Error: " << SDL_GetError() << endl;
        return ;
    }

    gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
    if (gRenderer == NULL) {
        cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << endl;
        return ;
    }

    cout << "Init Successfully\n";
}

void quitSDL(){
    IMG_Quit();

    SDL_DestroyRenderer(gRenderer);
    SDL_DestroyWindow(gWindow);

    SDL_Quit();
}

void show(){
    SDL_RenderPresent(gRenderer);
}
