#ifndef _SNAKE__H
#define _SNAKE__H
#include <deque>
#include <iostream>
#include "Head.h"
struct Snake{
    int dir, dem = 0, length = 3;
    bool is_alive = true;
    deque<Block> snake;
    Block food;
    void init();
    void draw();
    void move();
    void getDir();
    void modify(int x, int y);
    bool isValidSnake();
};
#endif _SNAKE__H
