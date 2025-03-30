#ifndef _AISNAKE__H
#define _AISNAKE__H
#include <deque>
#include <iostream>
#include <ctime>
#include <SDL_mixer.h>
#include <vector>
#include <string>
#include <queue>
#include "Head.h"
#include "button.h"
#include "graphics.h"

struct AI{
    int dir, dem = 0, length = 3, score = 0;
    bool is_alive = true;
    deque<Block> snake;
    Block food, big_food;
    clock_t start_time;
    Button score_board;

    void init();
    void draw();
    int move(int &id); // return score
    void getDir(bool &is_clicked_p, vector<int> &dir_store);
    void modify(int x, int y);
    bool isValidSnake();
    void free();
//    void getPos(int &x, int &y){
//        x = snake.front().rect
//    }
};
#endif _AISNAKE__H

