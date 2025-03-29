#ifndef _MENU__H
#define _MENU__H

#include "graphics.h"
#include <iostream>
#include "button.h"
#include "snake.h"
#include "map.h"

using namespace std;

struct Menu{
    Button play_game, quit;
    int mouse_x, mouse_y, id;
    bool is_clicked, is_quited, is_paused = false;
    void init();
    void draw();
    void loadBackGround(string file_path);
    void wait();
};

struct MainMenu{
    Button play_game, quit;
    int mouse_x, mouse_y;
    bool is_clicked, is_quited, is_paused = false;
    void init();
    void draw(int &id);
    void loadBackGround(string file_path);
    void wait();
};

struct NormalMod{
    bool is_paused, is_alive;
    bool is_clicked, is_use_store_snake;
    Snake snake, store_snake;
    Map map;
    void init();
    int wait(int &id);
    bool run();
};

struct PauseScreen{
    Button continue_play, quit, play_again;
    int mouse_x, mouse_y;
    bool is_clicked, is_quited, is_paused = false;
    void init();
    void draw(int &id);
    // void loadBackGround(string file_path);
    void loadMiniBackGround(string file_path, SDL_Rect);
    void wait();
};

struct GameOverScreen{
    Button quit, play_again, present_score;
    int mouse_x, mouse_y;
    bool is_clicked, is_quited, is_paused = false;
    void init(int score);
    void draw(int &id);
    void loadBackGround(string file_path);
    void wait();
};

#endif // _MENU__H
