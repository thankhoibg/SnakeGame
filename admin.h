#ifndef _ADMIN__H
#define _ADMIN__H

#include <iostream>
#include "menu.h"
#include "graphics.h"
#include "sound.h"

using namespace std;

struct Admin{
    int id;
    // 0: main menu
    // 1: playing normal mod
    // 2: pause screen
    // 3: game over screen
    // 4: high score screen
    // -2: continue playing normal mod
    void init(){
        id = 0;
    }
    void run(){

        // Sound my_sound;
        // my_sound.init();
        // my_sound.playBackGroundMusic();

        // SDL_Delay(50000);

        // exit(0);

        id = 0;
        MainMenu main_menu;
        main_menu.init();
        NormalMod normal_mod;
        normal_mod.init();
        PauseScreen pause_screen;
        pause_screen.init();
        int score;
        GameOverScreen game_over;
        HighScore high_score;
        high_score.init();
        high_score.update(-1);
        Sound sound;
        sound.init();
        normal_mod.snake.sound = sound;
        normal_mod.store_snake.sound = sound;
        while(!main_menu.quit.is_clicked){
        //    cout << id << '\n';
            switch (id){
                case 0:
                    main_menu.draw(id);
                    show();
                    main_menu.wait();
                    break;
                case 1:
                    // playing normal mod
                    normal_mod.store_snake.init();
                    score = normal_mod.wait(id);
                    game_over.init(score);
                    high_score.update(score);
                    break;
                case -2:
                    // continue playing normal mod
                    score = normal_mod.wait(id);
                    game_over.init(score);
                    high_score.update(score);
                    break;
                case 2:
                    pause_screen.draw(id);
                    show();
                    pause_screen.wait();
                    // pause screen
                    break;
                case 3:
                    game_over.draw(id);
                    show();
                    game_over.wait();
                    // game over screen
                    break;
                case 4:
                    high_score.draw(id);
                    show();
                    high_score.wait();
                    // high score screen
                    break;
                default:
                    cout << "Invalid id\n";
                    break;
            }
            SDL_Delay(50);
        }
    }
};

#endif // _ADMIN__H
