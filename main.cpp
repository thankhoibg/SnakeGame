#include <iostream>
#include <SDL.h>
#include <random>
#include <time.h>
#include <SDL_mixer.h>

#include "constant.h"
#include "map.h"
#include "graphics.h"
#include "snake.h"
#include "Head.h"
#include "menu.h"
#include "admin.h"

using namespace std;

void useAdmin(){
    Admin ad;
    ad.run1();
}

int main(int argc, char* argv[]){
    srand(time(0));
    initSDL();
    initIMG();

    useAdmin();

    freeIMG();
    quitSDL();

    return 0;
}
