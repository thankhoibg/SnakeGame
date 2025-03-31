#ifndef _ADMIN__H
#define _ADMIN__H

#include <iostream>
#include "menu.h"
#include "graphics.h"
#include "sound.h"

using namespace std;

struct Admin{
    int id, id1, id2;
    // 0: main menu
    // 1: playing normal mod
    // 2: pause screen
    // 3: game over screen
    // 4: high score screen
    // 5: change background music
    // 6: playing ai mod
    // -2: continue playing normal mod
    // -3: continue playing ai mod
    void init(){
        id = id1 = id2 = 0;
    }

//    void run1(){
//        id = 0;
//        MainMenu main_menu;
//        main_menu.init();
//        AIMod ai_mode;
//        ai_mode.init();
//        PauseScreen pause_screen;
//        pause_screen.init();
//        int score;
//        GameOverScreen game_over;
//        HighScore high_score;
//        high_score.init();
//        high_score.update(-1);
//        Sound back_ground_music;
//        string tmp;
//        Mix_Music *music;
//        Mix_Chunk *fail_sound = Mix_LoadWAV("sound/fail.wav");
//        id = 0;
//        while(!main_menu.quit.is_clicked){
//        //    cout << id << '\n';
//            switch (id){
//                case 0:{
//                    main_menu.draw(id, back_ground_music.cnt);
//                    show();
//                    main_menu.wait();
//                    break;
//                }
//                case 1:{
//                    // playing normal mod
//                    back_ground_music.cnt %= back_ground_music.music_list.size();
//                    tmp = "sound/" + back_ground_music.music_list[back_ground_music.cnt];
//                    cout << back_ground_music.cnt << '\n';
//                    music = Mix_LoadMUS(tmp.c_str());
//                    Mix_PlayMusic(music, -1);
//                    ai_mode.store_snake.init();
//                    score = ai_mode.wait(id);
//                    Mix_FadeOutMusic(50);
//                    Mix_FreeMusic(music);
//                    game_over.init(score);
//                    high_score.update(score);
//                    break;
//                }
//                case -2:{
//                    // continue playing normal mod
//                    back_ground_music.cnt %= back_ground_music.music_list.size();
//                    tmp = "sound/" + back_ground_music.music_list[back_ground_music.cnt];
//                    cout << back_ground_music.cnt << '\n';
//                    music = Mix_LoadMUS(tmp.c_str());
//                    Mix_PlayMusic(music, -1);
//                    score = ai_mode.wait(id);
//                    Mix_FadeOutMusic(50);
//                    Mix_FreeMusic(music);
//                    game_over.init(score);
//                    high_score.update(score);
//                    break;
//                }
//                case 2:{
//                    pause_screen.draw(id);
//                    show();
//                    pause_screen.wait();
//                    // pause screen
//                    break;
//                }
//                case 3:{
//                    Mix_PlayChannel(-1, fail_sound, 0);
//                    game_over.draw(id);
//                    show();
//                    game_over.wait();
//                    // game over screen
//                    break;
//                }
//                case 4:{
//                    high_score.draw(id);
//                    show();
//                    high_score.wait();
//                    // high score screen
//                    break;
//                }
//                case 5:{
//                    back_ground_music.cnt ++;
//                    cout << back_ground_music.cnt << '\n';
//                    back_ground_music.cnt %= back_ground_music.music_list.size();
//                    break;
//                }
//                default:{
//                    cout << "Invalid id\n";
//                    break;
//                }
//            }
//            SDL_Delay(50);
//        }
//    }

    void run(){

        // Sound my_sound;
        // my_sound.init();
        // my_sound.playBackGroundMusic();

        // SDL_Delay(50000);

        // exit(0);

        id = id1 = 0;
        MainMenu main_menu;
        main_menu.init();
        NormalMod normal_mod;
        normal_mod.init();
        AIMod ai_mode;
        ai_mode.init();
        PauseScreen pause_screen;
        pause_screen.init();
        int score;
        GameOverScreen game_over;
        HighScore high_score;
        high_score.init();
        high_score.update(-1);
        Sound back_ground_music;
        string tmp;
        Mix_Music *music;
        Mix_Chunk *fail_sound = Mix_LoadWAV("sound/fail.wav");
        while(!main_menu.quit.is_clicked){
//            cout << id << ' ' << id1 << '\n';
            switch (id){
                case 0:{
                    main_menu.draw(id, back_ground_music.cnt);
                    show();
                    main_menu.wait();
                    break;
                }
                case 1:{
                    // playing normal mod
                    back_ground_music.cnt %= back_ground_music.music_list.size();
                    tmp = "sound/" + back_ground_music.music_list[back_ground_music.cnt];
                    cout << "music.cnt is " << back_ground_music.cnt << '\n';
                    music = Mix_LoadMUS(tmp.c_str());
                    Mix_PlayMusic(music, -1);
                    normal_mod.store_snake.init();
                    normal_mod.snake.init();
                    score = normal_mod.wait(id, id1, id2);
                    if (score > 1000) score = 0;
                    score = max(score, 0);
                    Mix_FadeOutMusic(50);
                    Mix_FreeMusic(music);
                    game_over.init(score);
                    high_score.update(score);
                    break;
                }
                case -2:{
                    // continue playing normal mod
                    back_ground_music.cnt %= back_ground_music.music_list.size();
                    tmp = "sound/" + back_ground_music.music_list[back_ground_music.cnt];
                    cout << "music.cnt is " << back_ground_music.cnt << '\n';
                    music = Mix_LoadMUS(tmp.c_str());
                    Mix_PlayMusic(music, -1);
                    score = normal_mod.wait(id, id1, id2);
                    if (score > 1000) score = 0;
                    score = max(score, 0);
                    Mix_FadeOutMusic(50);
                    Mix_FreeMusic(music);
                    game_over.init(score);
                    high_score.update(score);
                    break;
                }
                case 2:{
                    pause_screen.draw(id, id1, id2);
                    show();
                    pause_screen.wait();
                    // pause screen
                    break;
                }
                case 3:{
                    Mix_PlayChannel(-1, fail_sound, 0);
                    game_over.draw(id, id1);
                    show();
                    game_over.wait();
                    // game over screen
                    break;
                }
                case 4:{
                    high_score.draw(id);
                    show();
                    high_score.wait();
                    // high score screen
                    break;
                }
                case 5:{
                    back_ground_music.cnt ++;
                    cout << "music.cnt is " << back_ground_music.cnt << '\n';
                    back_ground_music.cnt %= back_ground_music.music_list.size();
                    break;
                }
                case 6:{
                    // playing ai mod
                    back_ground_music.cnt %= back_ground_music.music_list.size();
                    tmp = "sound/" + back_ground_music.music_list[back_ground_music.cnt];
                    cout << "music.cnt is " << back_ground_music.cnt << '\n';
                    music = Mix_LoadMUS(tmp.c_str());
                    Mix_PlayMusic(music, -1);
//                    SDL_Delay(5000);
                    ai_mode.store_snake.init();
                    ai_mode.snake.init();
                    score = ai_mode.wait(id, id1, id2);
                    if (score > 1000) score = 0;
                    score = max(score, 0);
                    Mix_FadeOutMusic(50);
                    Mix_FreeMusic(music);
                    game_over.init(score);
                    high_score.update(score);
                    break;
                }
                case -3:{
                    // continue playing ai mod
                    back_ground_music.cnt %= back_ground_music.music_list.size();
                    tmp = "sound/" + back_ground_music.music_list[back_ground_music.cnt];
                    cout << "music.cnt is " << back_ground_music.cnt << '\n';
                    music = Mix_LoadMUS(tmp.c_str());
                    Mix_PlayMusic(music, -1);
                    score = ai_mode.wait(id, id1, id2);
                    if (score > 1000) score = 0;
                    score = max(score, 0);
                    Mix_FadeOutMusic(50);
                    Mix_FreeMusic(music);
                    game_over.init(score);
                    high_score.update(score);
                    break;
                }
                default:{
                    cout << "Invalid id\n";
                    break;
                }
            }
            SDL_Delay(50);
        }


//        Mix_FreeChunk(crunch_sound);
    }
};

#endif // _ADMIN__H
