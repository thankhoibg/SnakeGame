#include <iostream>
#include <SDL.h>
#include <random>
#include <time.h>

#include "constant.h"
#include "map.h"
#include "graphics.h"
#include "snake.h"
#include "Head.h"

using namespace std;

Map map;
Snake snake;

void waitUntilKeyPressed(int &cnt)
{
    SDL_Event e;
    while (true) {
        if ( SDL_PollEvent(&e) != 0 &&
             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) ){
//                snake.getDirection(e);
                cnt ++;
                break;
            }
        SDL_Delay(100);
    }
}

void run1(){
//    snake.init();

    SDL_Event e;
    while(true){
        map.drawBoard();
//        show();
        SDL_Rect r;
//        snake.drawSnakeHead(gRenderer, 0, r, 1);
        show();
//        snake.getKey();
    }
}

void run2(){
    int x;
    while(true){
        map.drawBoard();
        Block tail_block;
        tail_block.setTail();
        tail_block.rect = {SCREEN_HEIGHT/2, SCREEN_WIDTH/2, CELL_SIZE, CELL_SIZE};
        tail_block.getTail().dir ++;
        tail_block.getTail().dir %= 4;
        cout << tail_block.getTail().dir << '\n';
        tail_block.draw();
        show();
        waitUntilKeyPressed(x);
    }
}

void run3(){
    snake.init();
    while(true){
        map.drawBoard();
        snake.draw();
        snake.getDir();
//        cnt ++;
//        cout << cnt << '\n';
        snake.move();
        show();
//        if (snake.dir == 0) snake.dir = 2;
//        else if (snake.dir == 2) snake.dir = 1;
//        else if (snake.dir == 1) snake.dir = 3;
//        else snake.dir = 0;
//        if (snake.dir == 0) snake.dir = 3;
//        else if (snake.dir == 3) snake.dir = 1;
//        else if (snake.dir == 1) snake.dir = 2;
//        else snake.dir = 0;
        SDL_Delay(50);
    }
}

int main(int argc, char* argv[]){
    srand(time(0));
    initSDL();
    initIMG();

    run3();

    freeIMG();
    quitSDL();

    return 0;
}
