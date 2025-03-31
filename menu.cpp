#include "menu.h"
#include "constant.h"
#include <cstring>
#include <iostream>

using namespace std;

void Menu::init(){
    play_game.setValue("Play game");
    play_game.setFont("font\\Arial.ttf", 20);
    play_game.setRect(100, 100, 300, 200);
    play_game.color = White;
    play_game.is_clicked = false;

    quit.setValue("Quit");
    quit.setFont("font\\Arial.ttf", 20);
    quit.setRect(100, 335, 150, 200);
    quit.color = White;
    quit.is_clicked = false;
}

void Menu::draw(){
    loadBackGround("img/MenuBackground.jpg");
    if (play_game.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) play_game.draw(Red, Black);
        else {
            play_game.is_clicked = true;
            cout << "Game started\n";
        }
    }
    else play_game.draw(White, Black);
    if (quit.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) quit.draw(Red, Black);
        else {
            quit.is_clicked = true;
            cout << "Game quited\n";
        }
    }
    else quit.draw(White, Black);
}

void Menu::loadBackGround(string file_path){
    SDL_Surface* back_ground;
    back_ground = IMG_Load(file_path.c_str());
    SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, back_ground);
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
    SDL_FreeSurface(back_ground);
    SDL_DestroyTexture(gTexture);
}

void Menu::wait(){
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        int x = -1, y = -1;
        is_clicked = false;
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEMOTION)
             {
                SDL_GetMouseState(&x, &y);
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN){
                is_clicked = true;
            }
        }

        if (x != -1) {
            mouse_x = x;
            mouse_y = y;
        }
//        cout << mouse_x << ' ' << mouse_y << '\n';

        // Delay (optional, but helps reduce CPU usage)
        SDL_Delay(50);
        break;
    }
}

void MainMenu::init(){
    play_game.setValue("Play game");
    play_game.setFont("font\\Arial.ttf", 20);
    play_game.setRect(100, 100, 300, 100);
    play_game.color = White;
    play_game.is_clicked = false;

    quit.setValue("Quit");
    quit.setFont("font\\Arial.ttf", 20);
    quit.setRect(100, 450, 150, 100);
    quit.color = White;
    quit.is_clicked = false;

    view_high_score.setValue("High Score");
    view_high_score.setFont("font\\Arial.ttf", 20);
    view_high_score.setRect(100, 215, 300, 100);
    view_high_score.color = Ocean_Blue;
    view_high_score.is_clicked = false;

    change_back_ground_music.setValue("Change game music");
    change_back_ground_music.setFont("font\\Arial.ttf", 20);
    change_back_ground_music.setRect(100, 335, 600, 100);
    change_back_ground_music.color = Ocean_Blue;
    change_back_ground_music.is_clicked = false;

    ai_mode.setValue("Play AI Mode");
    ai_mode.setFont("font\\Arial.ttf", 20);
    ai_mode.setRect(640, 100, 600, 100);
    ai_mode.color = Ocean_Blue;
    ai_mode.is_clicked = false;
}

void MainMenu::draw(int &id){
   loadBackGround("img/MenuBackground.jpg");
   if (play_game.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) play_game.draw(Red, Black);
       else {
           play_game.is_clicked = true;
           id = 1;
           cout << "Game started\n";
       }
   }
   else play_game.draw(White, Black);
   if (quit.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) quit.draw(Red, Black);
       else {
           quit.is_clicked = true;
           id = -1;
           cout << "Game quited\n";
       }
   }
   else quit.draw(White, Black);
   if (view_high_score.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) view_high_score.draw(Red, Black);
       else {
           view_high_score.is_clicked = true;
           id = 4;
           cout << "View high score screen\n";
       }
   }
   else view_high_score.draw(White, Black);
   if (change_back_ground_music.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) change_back_ground_music.draw(Red, Black);
       else {
            change_back_ground_music.is_clicked = true;
            id = 0;
            cout << "Change background music\n";
       }
   }
   else change_back_ground_music.draw(White, Black);
   if (ai_mode.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) ai_mode.draw(Red, Black);
       else {
            ai_mode.is_clicked = true;
            id = 6;
            cout << "Play AI Mode\n";
       }
   }
   else ai_mode.draw(White, Black);
}

void MainMenu::draw(int &id, int &cnt){
   loadBackGround("img/MenuBackground.jpg");
   if (play_game.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) play_game.draw(Red, Black);
       else {
           play_game.is_clicked = true;
           id = 1;
           cout << "Game started\n";
       }
   }
   else play_game.draw(White, Black);
   if (quit.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) quit.draw(Red, Black);
       else {
           quit.is_clicked = true;
           id = -1;
           cout << "Game quited\n";
       }
   }
   else quit.draw(White, Black);
   if (view_high_score.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) view_high_score.draw(Red, Black);
       else {
           view_high_score.is_clicked = true;
           id = 4;
           cout << "View high score screen\n";
       }
   }
   else view_high_score.draw(White, Black);
   if (change_back_ground_music.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) change_back_ground_music.draw(Red, Black);
       else {
            change_back_ground_music.is_clicked = true;
            id = 0;
            cnt ++;
            cout << "Change background music\n";
       }
   }
   else change_back_ground_music.draw(White, Black);
   if (ai_mode.isFocused(mouse_x, mouse_y)) {
       if (!is_clicked) ai_mode.draw(Red, Black);
       else {
            ai_mode.is_clicked = true;
            id = 6;
            cout << "Play AI Mode\n";
       }
   }
   else ai_mode.draw(White, Black);
}

void MainMenu::loadBackGround(string file_path){
    SDL_Surface* back_ground;
    back_ground = IMG_Load(file_path.c_str());
    SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, back_ground);
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
    SDL_FreeSurface(back_ground);
    SDL_DestroyTexture(gTexture);
}

void MainMenu::wait(){
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        int x = -1, y = -1;
        is_clicked = false;
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEMOTION)
             {
                SDL_GetMouseState(&x, &y);
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN){
                is_clicked = true;
            }
            else if (event.type == SDL_QUIT){
                freeIMG();
                quitSDL();
                exit(0);
            }
        }

        if (x != -1) {
            mouse_x = x;
            mouse_y = y;
        }
//        cout << mouse_x << ' ' << mouse_y << '\n';

        // Delay (optional, but helps reduce CPU usage)
        SDL_Delay(50);
        break;
    }
}

void NormalMod::init(){
    is_paused = false;
    is_alive = true;
    is_clicked = false;
}

int NormalMod::wait(int &id, int &id1){
    // cout << "Has entered\n";
    snake = store_snake;
    // while(true){
    //     map.drawBoard();
    //     snake.draw();
    //     snake.getDir();
    //     snake.move();
    //     show();
    //     SDL_Delay(80);
    // }


    SDL_Event event;
    bool quit = false;
    int score = 0;

    while (!quit) {
        SDL_Event event;
        bool pKeyPressed = false;

        if (!snake.is_alive) {
            id = 3;
            store_snake.init();
            return score;
        }
        map.drawBoard();
        snake.draw();
        snake.getDir(pKeyPressed);
        score = snake.move(id);
        show();

        if (pKeyPressed) {
            quit = true;
            cout << "Player has paused the game\n";
            id = 2;
            id1 = -2;
            store_snake = snake;
        }

        SDL_Delay(80);

    }

    return score;
}

int NormalMod::wait(int &id, int &id1, int &id3){
    id1 = 1;
    // cout << "Has entered\n";
    snake = store_snake;
    // while(true){
    //     map.drawBoard();
    //     snake.draw();
    //     snake.getDir();
    //     snake.move();
    //     show();
    //     SDL_Delay(80);
    // }


    SDL_Event event;
    bool quit = false;
    int score = 0;

    while (!quit) {
        SDL_Event event;
        bool pKeyPressed = false;

        if (!snake.is_alive) {
            id = 3;
            store_snake.init();
            return score;
        }
        map.drawBoard();
        snake.draw();
        snake.getDir(pKeyPressed);
        score = snake.move(id);
        show();

        if (pKeyPressed) {
            quit = true;
            cout << "Player has paused the game\n";
            id = 2;
            id1 = -2;
            id3 = 1;
            store_snake = snake;
        }

        SDL_Delay(80);

    }

    return score;
}

int NormalMod::wait(int &id){
    // cout << "Has entered\n";
    snake = store_snake;
    // while(true){
    //     map.drawBoard();
    //     snake.draw();
    //     snake.getDir();
    //     snake.move();
    //     show();
    //     SDL_Delay(80);
    // }


    SDL_Event event;
    bool quit = false;
    int score = 0;

    while (!quit) {
        SDL_Event event;
        bool pKeyPressed = false;

        if (!snake.is_alive) {
            id = 3;
            store_snake.init();
            return score;
        }
        map.drawBoard();
        snake.draw();
        snake.getDir(pKeyPressed);
        score = snake.move(id);
        show();

        if (pKeyPressed) {
            quit = true;
            cout << "Player has paused the game\n";
            id = 2;
            store_snake = snake;
        }

        SDL_Delay(80);

    }

    return score;
}

void AIMod::init(){
    is_paused = false;
    is_alive = true;
    is_clicked = false;
}

int AIMod::wait(int &id, int &id1){
    snake = store_snake;

    SDL_Event event;
    bool quit = false;
    int score = 0;

    vector<int> dir_stored;
    dir_stored.clear();

    while (!quit) {
        SDL_Event event;
        bool pKeyPressed = false;

        if (!snake.is_alive) {
            id = 3;
            store_snake.init();
            return score;
        }


        map.drawBoard();
        snake.draw();
        if (dir_stored.empty())
            snake.getDir(pKeyPressed, dir_stored);
        int x = snake.snake.front().rect.x, y = snake.snake.front().rect.y;
        snake.dir = dir_stored[0];
        score = snake.move(id, id1);
        if (snake.snake.front().rect.x != x || snake.snake.front().rect.y != y) {
            dir_stored.erase(dir_stored.begin());
        }
        show();

        if (pKeyPressed) {
            quit = true;
            cout << "Player has paused the game\n";
            id = 2;
            id1 = -3;
            store_snake = snake;
        }

        SDL_Delay(80);

    }

    return score;
}

int AIMod::wait(int &id, int &id1, int &id2){
    id1 = 6;
    snake = store_snake;

    SDL_Event event;
    bool quit = false;
    int score = 0;

    vector<int> dir_stored;
    dir_stored.clear();

    while (!quit) {
        SDL_Event event;
        bool pKeyPressed = false;

        if (!snake.is_alive) {
            id = 3;
            store_snake.init();
            return score;
        }


        map.drawBoard();
        snake.draw();
        if (dir_stored.empty())
            snake.getDir(pKeyPressed, dir_stored);
        int x = snake.snake.front().rect.x, y = snake.snake.front().rect.y;
        snake.dir = dir_stored[0];
        score = snake.move(id, id1);
        if (snake.snake.front().rect.x != x || snake.snake.front().rect.y != y) {
            dir_stored.erase(dir_stored.begin());
        }
        show();

        if (pKeyPressed) {
            quit = true;
            cout << "Player has paused the game\n";
            id = 2;
            id1 = -3;
            id2 = 6;
            store_snake = snake;
        }

        SDL_Delay(80);

    }

    return score;
}


int AIMod::wait(int &id){
    snake = store_snake;

    SDL_Event event;
    bool quit = false;
    int score = 0;

    vector<int> dir_stored;
    dir_stored.clear();

    while (!quit) {
        SDL_Event event;
        bool pKeyPressed = false;

        if (!snake.is_alive) {
            id = 3;
            store_snake.init();
            return score;
        }
        map.drawBoard();
        snake.draw();
        if (dir_stored.empty())
            snake.getDir(pKeyPressed, dir_stored);
        int x = snake.snake.front().rect.x, y = snake.snake.front().rect.y;
        snake.dir = dir_stored[0];
        score = snake.move(id);
        if (snake.snake.front().rect.x != x || snake.snake.front().rect.y != y) {
            dir_stored.erase(dir_stored.begin());
        }
        show();

        if (pKeyPressed) {
            quit = true;
            cout << "Player has paused the game\n";
            id = 2;
            store_snake = snake;
        }

        SDL_Delay(80);

    }

    return score;
}

void PauseScreen::init(){
    is_clicked = is_quited = is_paused = false;
    continue_play.setValue("Continue Play?");
    continue_play.setFont("font\\segoesc.ttf", 10);
    continue_play.setRect(100, 150, 300, 100);
    continue_play.color = Ocean_Blue;
    continue_play.is_clicked = false;

    quit.setValue("Quit");
    quit.setFont("font\\segoesc.ttf", 20);
    quit.setRect(100, 280, 100, 100);
    quit.color = Ocean_Blue;
    quit.is_clicked = false;

    play_again.setValue("Play Again");
    play_again.setFont("font\\segoesc.ttf", 20);
    play_again.setRect(100, 400, 280, 100);
    play_again.color = Ocean_Blue;
    play_again.is_clicked = false;
}

void PauseScreen::wait(){
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        int x = -1, y = -1;
        is_clicked = false;
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEMOTION)
             {
                SDL_GetMouseState(&x, &y);
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN){
                is_clicked = true;
            }
        }

        if (x != -1) {
            mouse_x = x;
            mouse_y = y;
        }

        SDL_Delay(50);
        break;
    }
}

void PauseScreen::draw(int &id, int id1){
    loadMiniBackGround("img/PauseBackground.jpg", {0, 0, 640, 640});
    if (continue_play.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) continue_play.draw(Ocean_Blue, Black);
        else {
            continue_play.is_clicked = true;
            id = id1;
            if (id1 != -2 && id1 != -3){
                cout << "Unidentify id1\n";
                exit(0);
            }
            cout << "Game continued\n";
        }
    }
    else continue_play.draw(White, Black);
    if (quit.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) quit.draw(Red, Black);
        else {
            quit.is_clicked = true;
            id = 0;
            cout << "Return main menu\n";
        }
    }
    else quit.draw(White, Black);
    if (play_again.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) play_again.draw(Yellow, Black);
        else {
            play_again.is_clicked = true;
            id = id1;
            cout << "Play again\n";
        }
    }
    else play_again.draw(White, Black);
}

void PauseScreen::draw(int &id, int id1, int id2){
    loadMiniBackGround("img/PauseBackground.jpg", {0, 0, 640, 640});
    if (continue_play.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) continue_play.draw(Ocean_Blue, Black);
        else {
            continue_play.is_clicked = true;
            id = id1;
            if (id1 != -2 && id1 != -3){
                cout << "Unidentify id1\n";
                exit(0);
            }
            cout << "Game continued\n";
        }
    }
    else continue_play.draw(White, Black);
    if (quit.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) quit.draw(Red, Black);
        else {
            quit.is_clicked = true;
            id = 0;
            cout << "Return main menu\n";
        }
    }
    else quit.draw(White, Black);
    if (play_again.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) play_again.draw(Yellow, Black);
        else {
            play_again.is_clicked = true;
            id = id2;
            cout << "Play again\n";
            cout << "The id now is " << id2 << '\n';
        }
    }
    else play_again.draw(White, Black);
}

void PauseScreen::draw(int &id){
    loadMiniBackGround("img/PauseBackground.jpg", {0, 0, 640, 640});
    if (continue_play.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) continue_play.draw(Ocean_Blue, Black);
        else {
            continue_play.is_clicked = true;
            id = -2;
            cout << "Game continued\n";
        }
    }
    else continue_play.draw(White, Black);
    if (quit.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) quit.draw(Red, Black);
        else {
            quit.is_clicked = true;
            id = 0;
            cout << "Return main menu\n";
        }
    }
    else quit.draw(White, Black);
    if (play_again.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) play_again.draw(Yellow, Black);
        else {
            play_again.is_clicked = true;
            id = 1;
            cout << "Play again\n";
        }
    }
    else play_again.draw(White, Black);
}

void PauseScreen::loadMiniBackGround(string file_path, SDL_Rect rect){
    SDL_Surface* back_ground;
    back_ground = IMG_Load(file_path.c_str());
    SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, back_ground);
    SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
    SDL_FreeSurface(back_ground);
    SDL_DestroyTexture(gTexture);
}

void GameOverScreen::init(int score){
    is_clicked = is_quited = false;

    quit.setValue("Quit");
    quit.setFont("font\\segoesc.ttf", 20);
    quit.setRect(100, 280, 100, 100);
    quit.color = Ocean_Blue;
    quit.is_clicked = false;

    play_again.setValue("Play Again");
    play_again.setFont("font\\segoesc.ttf", 20);
    play_again.setRect(100, 400, 280, 100);
    play_again.color = Ocean_Blue;
    play_again.is_clicked = false;

    present_score.setValue("Your score is " + to_string(score));
    present_score.setFont("font\\segoesc.ttf", 20);
    present_score.setRect(100, 150, 300, 100);
    present_score.color = Ocean_Blue;
    present_score.is_clicked = false;
}

void GameOverScreen::loadBackGround(string file_path){
    SDL_Surface* back_ground;
    back_ground = IMG_Load(file_path.c_str());
    SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, back_ground);
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
    SDL_FreeSurface(back_ground);
    SDL_DestroyTexture(gTexture);
}

void GameOverScreen::wait(){
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        int x = -1, y = -1;
        is_clicked = false;
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEMOTION)
             {
                SDL_GetMouseState(&x, &y);
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN){
                is_clicked = true;
            }
        }

        if (x != -1) {
            mouse_x = x;
            mouse_y = y;
        }

        SDL_Delay(50);
        break;
    }
}

void GameOverScreen::draw(int &id){
    loadBackGround("img/GameOverBackground.jpg");
    if (present_score.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) present_score.draw(Ocean_Blue, Black);
        else {
            present_score.is_clicked = true;
            cout << "Viewing high score\n";
        }
    }
    else present_score.draw(White, Black);
    if (quit.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) quit.draw(Red, Black);
        else {
            quit.is_clicked = true;
            id = 0;
            cout << "Return main menu\n";
        }
    }
    else quit.draw(White, Black);
    if (play_again.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) play_again.draw(Yellow, Black);
        else {
            play_again.is_clicked = true;
            id = 1;
            cout << "Play again\n";
        }
    }
    else play_again.draw(White, Black);
}

void GameOverScreen::draw(int &id, int id1){
    loadBackGround("img/GameOverBackground.jpg");
    if (present_score.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) present_score.draw(Ocean_Blue, Black);
        else {
            present_score.is_clicked = true;
            cout << "Viewing high score\n";
        }
    }
    else present_score.draw(White, Black);
    if (quit.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) quit.draw(Red, Black);
        else {
            quit.is_clicked = true;
            id = 0;
            cout << "Return main menu\n";
        }
    }
    else quit.draw(White, Black);
    if (play_again.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) play_again.draw(Yellow, Black);
        else {
            play_again.is_clicked = true;
            id = id1;
            cout << "Play again\n";
        }
    }
    else play_again.draw(White, Black);
}

void HighScore::init(){
    is_clicked = is_quited = false;
    high_score.setValue("");
    high_score.setFont("font\\segoesc.ttf", 20);
    high_score.setRect(480, 220, 50, 80);
    high_score.color = Ocean_Blue;
    high_score.is_clicked = false;
    score_highest_stored_path = "HighestScore.txt";

    quit.setValue("Quit");
    quit.setFont("font\\segoesc.ttf", 20);
    quit.setRect(430, 335, 150, 100);
    quit.color = White;
    quit.is_clicked = false;
}

void HighScore::update(int new_score){
    ifstream inp;
    inp.open(score_highest_stored_path.c_str());
    if(!inp.is_open()){
        cout << "Can not open file\n";
        return;
    }
    ofstream out;
    out.open(score_highest_stored_path.c_str());
    if (!out.is_open()){
        cout << "Can open file\n";
        return;
    }
    int score = 0;
    inp >> score;
    if (new_score != -1) score = max(score, new_score);
    else score = 0;
    out << score;
    inp.close();
    out.close();
}

void HighScore::draw(int &id){
    loadBackGround("img/HighestScoreBackGround.jpg");
    int score = getHighScore();
    high_score.setValue(to_string(score));
    high_score.draw(Black, Ocean_Blue);
    quit.draw(Black, Ocean_Blue);
    if (quit.isFocused(mouse_x, mouse_y)) {
        if (!is_clicked) quit.draw(Red, Black);
        else {
            quit.is_clicked = true;
            id = 0;
            cout << "Return main menu\n";
        }
    }
}

void HighScore::wait(){
    SDL_Event event;
    bool quit = false;

    while (!quit) {
        int x = -1, y = -1;
        is_clicked = false;
        // Handle events
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEMOTION)
             {
                SDL_GetMouseState(&x, &y);
                is_clicked = false;
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN){
                is_clicked = true;
            }
        }

        if (x != -1) {
            mouse_x = x;
            mouse_y = y;
        }

        SDL_Delay(50);
        break;
    }
}

void HighScore::loadBackGround(string file_path){
    SDL_Surface* back_ground;
    back_ground = IMG_Load(file_path.c_str());
    SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, back_ground);
    SDL_Rect rect = {0, 0, SCREEN_WIDTH, SCREEN_HEIGHT};
    SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);
    SDL_FreeSurface(back_ground);
    SDL_DestroyTexture(gTexture);
}
