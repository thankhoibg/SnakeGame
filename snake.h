#ifndef _SNAKE__H
#define _SNAKE__H
#include <deque>
#include <iostream>
#include <ctime>
#include "Head.h"
struct Snake{
    int dir, dem = 0, length = 3, score = 0;
    bool is_alive = true;
    deque<Block> snake;
    Block food, big_food;
    clock_t start_time;
    void init();
    void draw();
    int move(int &id); // return score
    void getDir(bool &is_clicked_p);
    void modify(int x, int y);
    bool isValidSnake();
};
#endif _SNAKE__H
