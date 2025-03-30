#ifndef _MENU__H
#define _MENU__H

#include "graphics.h"
#include <iostream>
#include <fstream>
#include "button.h"
#include "snake.h"
#include "map.h"
#include "aisnake.h"

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
    Button play_game, quit, view_high_score, change_back_ground_music, ai_mode;
    int mouse_x, mouse_y;
    bool is_clicked, is_quited, is_paused = false;
    void init();
    void draw(int &id);
    void draw(int &id, int &cnt);
    void loadBackGround(string file_path);
    void wait();
};

struct NormalMod{
    bool is_paused, is_alive;
    bool is_clicked, is_use_store_snake;
    Snake snake, store_snake;
    Map map;
    void init();
    int wait(int &id, int &id1);
    int wait(int &id);
    bool run();
};

struct AIMod{
    bool is_paused, is_alive;
    bool is_clicked, is_use_store_snake;
    AI snake, store_snake;
    Map map;
    void init();
    int wait(int &id, int &id1);
    int wait(int &id);
    bool run();
};

struct PauseScreen{
    Button continue_play, quit, play_again;
    int mouse_x, mouse_y;
    bool is_clicked, is_quited, is_paused = false;
    void init();
    void draw(int &id, int id1, int id2);
    void draw(int &id, int id1);
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
    void draw(int &id, int id1);
    void loadBackGround(string file_path);
    void wait();
};

struct HighScore{
    string score_highest_stored_path;
    int mouse_x, mouse_y;
    bool is_clicked, is_quited, is_paused = false;
    Button high_score, quit;
    void init();
    void update(int score);
    void draw(int &id);
    void wait();
    void loadBackGround(string file_path);
    int getHighScore(){
        ifstream input_file(score_highest_stored_path);
        if (!input_file.is_open()){
            cout << "Cannot open file\n";
            return 0;
        }
        int high_score;
        input_file >> high_score;
        input_file.close();
        return high_score;
    }
};

#endif // _MENU__H
