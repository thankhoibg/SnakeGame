#ifndef _SNAKE__H
#define _SNAKE__H
#include <deque>
#include <iostream>
#include <ctime>
#include <SDL_mixer.h>
#include <vector>
#include <string>
#include "Head.h"
#include "button.h"
#include "graphics.h"

struct Snake{
    int dir, dem = 0, length = 3, score = 0;
    bool is_alive = true;
    deque<Block> snake;
    Block food, big_food;
    clock_t start_time;
    Button score_board;

    void init();
    void draw();
    int move(int &id); // return score
    int move(int &id, int &id1); // return score
    void getDir(bool &is_clicked_p);
    void modify(int x, int y);
    bool isValidSnake();
    void free();
};
#endif _SNAKE__H
