#include <iostream>
#include <SDL.h>
#include <random>
#include <time.h>

#include "constant.h"
#include "map.h"
#include "graphics.h"
#include "snake.h"
#include "Head.h"
#include "menu.h"
#include "admin.h"

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
    bool is_pressed_p = false;
    int id;
    while(true){
        map.drawBoard();
        snake.draw();
        snake.getDir(is_pressed_p);
//        cnt ++;
//        cout << cnt << '\n';
        snake.move(id);
        show();
//        if (snake.dir == 0) snake.dir = 2;
//        else if (snake.dir == 2) snake.dir = 1;
//        else if (snake.dir == 1) snake.dir = 3;
//        else snake.dir = 0;
//        if (snake.dir == 0) snake.dir = 3;
//        else if (snake.dir == 3) snake.dir = 1;
//        else if (snake.dir == 1) snake.dir = 2;
//        else snake.dir = 0;
        SDL_Delay(80);
    }
}

void drawMenu(){
    Menu main_menu, pause_menu;
    main_menu.init(); pause_menu.init();
    main_menu.id = 1; pause_menu.id = 2;
    while(!main_menu.quit.is_clicked){
        main_menu.draw();
        show();
        main_menu.wait();
        SDL_Delay(10);
    }
}

void useAdmin(){
    Admin ad;
    ad.run();
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
