#include "aisnake.h"
#include "constant.h"
#include "graphics.h"
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include <algorithm>
#include <random>
#include "button.h"

SDL_Surface* score_back_ground;

void AI::init(){
    // init the snake has 3 block: 1 head, 1 body and 1 tail at the middle of the board game
    score = 0;
//    food.getFood().count = 0;
    dir = 0;
    snake.clear();
    Block head;
    head.setHead();
    head.getHead().dir = 0;
    head.getPos(BOARD_SIZE/2, BOARD_SIZE/2 - 2);
    snake.push_front(head);
    Block body;
    body.setBody();
    body.getBody().dir = 0;
    body.getBody().is_straight = true;
    body.getPos(BOARD_SIZE/2, BOARD_SIZE/2 - 1);
    snake.push_back(body);
    Block tail;
    tail.setTail();
    tail.getTail().dir = 0;
    tail.getPos(BOARD_SIZE/2, BOARD_SIZE/2);
    snake.push_back(tail);

    food.setFood();
    food.genFood(snake);
    big_food.setBigFood();
    big_food.getBigFood().is_appear = false;
    small_food.setSmallFood();
    small_food.getSmallFood().is_appear = false;

    // score board will load the image in the rect{640, 0, 320, 640} at first
    // score board will load the apple image at the middle of the rect{640, 0, 320, 640}
    // score board will load the score text right after the score text
    score_board.setValue(to_string(score));
    score_board.setFont("font\\segoesc.ttf", 50);
    score_board.setRect(700, 40, 50, 70);
    score_board.color = Black;
    score_board.draw(Black, Red);
    score_back_ground = IMG_Load("img/ScoreBackGround.jpg");

    clock_t start_time = clock();
}

void AI::draw(){
    for (auto& block : snake){
        block.draw();
    }
    food.draw();
    if (food.getFood().count == M - 1 && big_food.getBigFood().is_appear == false) {
        big_food.getBigFood().is_appear = true;
        clock_t now = clock();
        big_food.getBigFood().time_appear = now - start_time;
//        cout << big_food.getBigFood().time_appear << '\n';
        big_food.genFood(snake, 1);
//        cout << "Big food has been spawned and food.count is reseted\n";
        food.getFood().count = 0;
    }
    if (food.getFood().count % N == N - 1 && small_food.getSmallFood().is_appear == false && snake.size() > 3) {
        small_food.getSmallFood().is_appear = true;
        clock_t now = clock();
        small_food.getSmallFood().time_appear = now - start_time;
//        cout << big_food.getBigFood().time_appear << '\n';
        small_food.genFood(snake, 2);
//        cout << "Big food has been spawned and food.count is reseted\n";
    }
    clock_t now = clock();
    double timee = now - start_time;
    if (timee - big_food.getBigFood().time_appear > TIME_BIG_FOOD) {
        big_food.getBigFood().is_appear = false;
        // big food disappear beacause over TIME_BIG_FOOD ms, the snake does not eat big food.
    }
    if (timee - small_food.getSmallFood().time_appear > TIME_SMALL_FOOD) {
        small_food.getSmallFood().is_appear = false;
        // big food disappear beacause over TIME_BIG_FOOD ms, the snake does not eat big food.
    }
//    cout << timee - big_food.getBigFood().time_appear << '\n';
    if (big_food.getBigFood().is_appear) big_food.draw();
    if (small_food.getSmallFood().is_appear) {
        // cout << "dang ve small food\n";
        small_food.draw();
    }

//     score board will load the image in the rect{640, 0, 960, 640} at first
//     score board will load the apple image at the rect{700, 220, 100, 100}
//     score board will load the score text right after the score text
//     the rect of the score text will be {800, 220, 50, 50}
    score_board.setValue(to_string(score));
    SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, score_back_ground);
    SDL_Rect my_rect = {640, 0, 320, 640};
    SDL_RenderCopy(gRenderer, gTexture, NULL, &my_rect);

    score_board.draw(Red, White);

    SDL_DestroyTexture(gTexture);

    // score_board.setRect()
    if (!is_alive){
        // freeIMG();
        // quitSDL();
        // exit(0);
    }
}

int AI::move(int &id) { // Takes the event as an argument
    dem ++;
    if (dem == 1) return 0;
    deque<Block> snake1;
    Block head = snake.front(); snake.pop_front();
    Block new_head = head;
    new_head.getHead().dir = dir;
    switch (dir){
        case 0:
            new_head.rect.y --;
            break;
        case 1:
            new_head.rect.y ++;
            break;
        case 2:
            new_head.rect.x --;
            break;
        case 3:
            new_head.rect.x ++;
            break;
        default:
            cout << "Error dir of snake when it is moving\n";
            exit(0);
            break;
    }
    new_head.modify();
    bool have_eat_food = false, have_eat_big_food = false, have_eat_small_food = false;
    if (new_head.rect.x == food.rect.x && new_head.rect.y == food.rect.y){
        have_eat_food = true;
    }
    if (new_head.rect.x == small_food.rect.x && new_head.rect.y == small_food.rect.y){
        have_eat_small_food = true;
    }
    if (big_food.getBigFood().is_appear && new_head.rect.x >= big_food.rect.x && new_head.rect.x <= big_food.rect.x + 1 && new_head.rect.y >= big_food.rect.y && new_head.rect.y <= big_food.rect.y + 1){
        have_eat_big_food = true;
    }
    snake1.push_front(new_head);
    SDL_Rect rect = head.rect;
    Block last = head;
    while(snake.size() > 1) {
        Block body = snake.front(); Block tmp = body;
        snake.pop_front();
        SDL_Rect rect1 = body.rect;
        body.rect = rect;
        rect = rect1;
        if (snake1.back().getType() == Block::Type::Head) body.getBody().getNextDir(snake1.back().getHead());
        else {
            body = last;
        }
        snake1.push_back(body);
        last = tmp;
    }
    if (!have_eat_food && !have_eat_big_food){
        Block tail = snake.front(); snake.pop_front();
        tail.getTail().getNextDir(snake1.back().getBody());
        tail.rect = rect;
        snake1.push_back(tail);
        length ++;
    }
    else {
        Block add_body = snake1[1];
        add_body.rect = last.rect;
        add_body.getBody().is_straight = true;
        add_body.getBody().dir = snake.front().getTail().dir;
        snake1.push_back(add_body);
        Block tail = snake.front(); snake.pop_front();
        tail.getTail().getNextDir(snake1.back().getBody());
        snake1.push_back(tail);
    }
    if (have_eat_small_food) {
        small_food.getSmallFood().is_appear = false;
        score ++;
        food.getFood().count ++;
        food.getFood().count %= M;
        snake1.pop_back();
        int tmp_dir = snake1.back().getBody().dir;
        snake1.back().setTail();
        snake1.back().getTail().dir = tmp_dir;
        Mix_Chunk *crunch_sound = Mix_LoadWAV("sound/crunch.wav");
        Mix_PlayChannel(-1, crunch_sound, 0);
    }
    snake = snake1;
    if (have_eat_big_food){
        big_food.getBigFood().is_appear = false;
        food.getFood().count = 0;
        length ++;
        score += 5;
        Mix_Chunk *crunch_sound = Mix_LoadWAV("sound/crunch.wav");
        Mix_PlayChannel(-1, crunch_sound, 0);
    }
    if (have_eat_food){
        food.genFood(snake);
        food.getFood().count ++;
        food.getFood().count %= M;
        length ++;
        score ++;
        Mix_Chunk *crunch_sound = Mix_LoadWAV("sound/crunch.wav");
        Mix_PlayChannel(-1, crunch_sound, 0);
    }

    if (!isValidSnake()){
        cout << "Snake eat itself\n";
        is_alive = false;
        id = 3;
        return score;
    }
}

int AI::move(int &id, int &id1) { // Takes the event as an argument
    dem ++;
    if (dem == 1) return 0;
    deque<Block> snake1;
    Block head = snake.front(); snake.pop_front();
    Block new_head = head;
    new_head.getHead().dir = dir;
    switch (dir){
        case 0:
            new_head.rect.y --;
            break;
        case 1:
            new_head.rect.y ++;
            break;
        case 2:
            new_head.rect.x --;
            break;
        case 3:
            new_head.rect.x ++;
            break;
        default:
            cout << "Error dir of snake when it is moving\n";
            exit(0);
            break;
    }
    new_head.modify();
    bool have_eat_food = false, have_eat_big_food = false, have_eat_small_food = false;
    if (new_head.rect.x == food.rect.x && new_head.rect.y == food.rect.y){
        have_eat_food = true;
    }
    if (new_head.rect.x == small_food.rect.x && new_head.rect.y == small_food.rect.y){
        have_eat_small_food = true;
    }
    if (big_food.getBigFood().is_appear && new_head.rect.x >= big_food.rect.x && new_head.rect.x <= big_food.rect.x + 1 && new_head.rect.y >= big_food.rect.y && new_head.rect.y <= big_food.rect.y + 1){
        have_eat_big_food = true;
    }
    snake1.push_front(new_head);
    SDL_Rect rect = head.rect;
    Block last = head;
    while(snake.size() > 1) {
        Block body = snake.front(); Block tmp = body;
        snake.pop_front();
        SDL_Rect rect1 = body.rect;
        body.rect = rect;
        rect = rect1;
        if (snake1.back().getType() == Block::Type::Head) body.getBody().getNextDir(snake1.back().getHead());
        else {
            body = last;
        }
        snake1.push_back(body);
        last = tmp;
    }
    if (!have_eat_food && !have_eat_big_food){
        Block tail = snake.front(); snake.pop_front();
        tail.getTail().getNextDir(snake1.back().getBody());
        tail.rect = rect;
        snake1.push_back(tail);
        length ++;
    }
    else {
        Block add_body = snake1[1];
        add_body.rect = last.rect;
        add_body.getBody().is_straight = true;
        add_body.getBody().dir = snake.front().getTail().dir;
        snake1.push_back(add_body);
        Block tail = snake.front(); snake.pop_front();
        tail.getTail().getNextDir(snake1.back().getBody());
        snake1.push_back(tail);
    }
    if (have_eat_small_food) {
        small_food.getSmallFood().is_appear = false;
        score ++;
        food.getFood().count ++;
        food.getFood().count %= M;
        snake1.pop_back();
        int tmp_dir = snake1.back().getBody().dir;
        snake1.back().setTail();
        snake1.back().getTail().dir = tmp_dir;
        Mix_Chunk *crunch_sound = Mix_LoadWAV("sound/crunch.wav");
        Mix_PlayChannel(-1, crunch_sound, 0);
    }
    snake = snake1;
    if (have_eat_big_food){
        big_food.getBigFood().is_appear = false;
        food.getFood().count = 0;
        length ++;
        score += 5;
        Mix_Chunk *crunch_sound = Mix_LoadWAV("sound/crunch.wav");
        Mix_PlayChannel(-1, crunch_sound, 0);
    }
    if (have_eat_food){
        food.genFood(snake);
        food.getFood().count ++;
        food.getFood().count %= M;
        length ++;
        score ++;
        Mix_Chunk *crunch_sound = Mix_LoadWAV("sound/crunch.wav");
        Mix_PlayChannel(-1, crunch_sound, 0);
    }

    if (!isValidSnake()){
        cout << "Snake eat itself\n";
        is_alive = false;
        id = 3;
        id1 = 6;
        return score;
    }
}

// int AI::move(int &id, int &id1) { // Takes the event as an argument
//     dem ++;
//     if (dem == 1) return 0;
//     deque<Block> snake1;
//     Block head = snake.front(); snake.pop_front();
//     Block new_head = head;
//     new_head.getHead().dir = dir;
//     switch (dir){
//         case 0:
//             new_head.rect.y --;
//             break;
//         case 1:
//             new_head.rect.y ++;
//             break;
//         case 2:
//             new_head.rect.x --;
//             break;
//         case 3:
//             new_head.rect.x ++;
//             break;
//         default:
//             cout << "Error dir of snake when it is moving\n";
//             exit(0);
//             break;
//     }
//     new_head.modify();
//     bool have_eat_food = false, have_eat_big_food = false;
//     if (new_head.rect.x == food.rect.x && new_head.rect.y == food.rect.y){
//         have_eat_food = true;
//     }
//     if (big_food.getBigFood().is_appear && new_head.rect.x >= big_food.rect.x && new_head.rect.x <= big_food.rect.x + 1 && new_head.rect.y >= big_food.rect.y && new_head.rect.y <= big_food.rect.y + 1){
//         have_eat_big_food = true;
//     }
//     snake1.push_front(new_head);
//     SDL_Rect rect = head.rect;
//     Block last = head;
//     while(snake.size() > 1) {
//         Block body = snake.front(); Block tmp = body;
//         snake.pop_front();
//         SDL_Rect rect1 = body.rect;
//         body.rect = rect;
//         rect = rect1;
//         if (snake1.back().getType() == Block::Type::Head) body.getBody().getNextDir(snake1.back().getHead());
//         else {
//             body = last;
//         }
//         snake1.push_back(body);
//         last = tmp;
//     }
//     if (!have_eat_food && !have_eat_big_food){
//         Block tail = snake.front(); snake.pop_front();
//         tail.getTail().getNextDir(snake1.back().getBody());
//         tail.rect = rect;
//         snake1.push_back(tail);
//         length ++;
//     }
//     else {
//         Block add_body = snake1[1];
//         add_body.rect = last.rect;
//         add_body.getBody().is_straight = true;
//         add_body.getBody().dir = snake.front().getTail().dir;
//         snake1.push_back(add_body);
//         Block tail = snake.front(); snake.pop_front();
//         tail.getTail().getNextDir(snake1.back().getBody());
//         snake1.push_back(tail);
//     }
//     snake = snake1;
//     if (have_eat_big_food){
//         big_food.getBigFood().is_appear = false;
//         food.getFood().count = 0;
//         length ++;
//         score += 5;
//         Mix_Chunk *crunch_sound = Mix_LoadWAV("sound/crunch.wav");
//         Mix_PlayChannel(-1, crunch_sound, 0);
//     }
//     if (have_eat_food){
//         food.genFood(snake);
//         food.getFood().count ++;
//         food.getFood().count %= M;
//         length ++;
//         score ++;
//         Mix_Chunk *crunch_sound = Mix_LoadWAV("sound/crunch.wav");
//         Mix_PlayChannel(-1, crunch_sound, 0);
//     }

//     if (!isValidSnake()){
//         cout << "Snake eat itself\n";
//         is_alive = false;
//         id = 3;
//         id1 = 6;
//         return score;
//     }
// }

void AI::getDir(bool &is_clicked_p, vector<int> &dir_store) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_p:
                    is_clicked_p = true;
                    break;
                default:
                    break;
            }
        }
    }

    vector<vector<bool>> is_valid_block;
    is_valid_block.resize(BOARD_SIZE);
    for(auto &v : is_valid_block) v.resize(BOARD_SIZE, true);
    for(Block block : snake){
        is_valid_block[block.rect.x][block.rect.y] = false;
    }
    pair<int, int> goal;
    if (small_food.getSmallFood().is_appear && snake.size() > 10) goal = make_pair(small_food.rect.x, small_food.rect.y);
    else if (big_food.getBigFood().is_appear) goal = make_pair(big_food.rect.x, big_food.rect.y);
    else goal = make_pair(food.rect.x, food.rect.y);
    vector<vector<vector<int>>> d;
    vector<vector<vector<pair<pair<int,int>,int>>>> trace;
    d.resize(BOARD_SIZE);
    trace.resize(BOARD_SIZE);
    for(auto &v : d) v.resize(BOARD_SIZE);
    for(auto &v : trace) v.resize(BOARD_SIZE);
    for(int i = 0; i < BOARD_SIZE; ++ i) for(int j = 0; j < BOARD_SIZE; ++ j){
        d[i][j].resize(4, (int)1e9);
        trace[i][j].resize(4);
    }
//    cout << "Toi dang fix bug o day\n" << dir << '\n';
    d[snake.front().rect.x][snake.front().rect.y][dir] = 0;
    queue<pair<pair<int,int>,int>> q;
    q.push(make_pair(make_pair(snake.front().rect.x, snake.front().rect.y), dir));
    auto checkValidDir = [](int cur_dir, int next_dir){
        int mn = min(cur_dir, next_dir);
        int mx = max(cur_dir, next_dir);
        if (mn == 0 && mx == 1) return false;
        if (mn == 2 && mx == 3) return false;
        return true;
    };


    while(!q.empty()){
        pair<pair<int,int>,int> tmp = q.front(); q.pop();
        int x, y, cur_dir;
        x = tmp.first.first;
        y = tmp.first.second;
        cur_dir = tmp.second;
//        auto [x, y, cur_dir] = q.front(); q.pop();
        for(int next_dir = 0; next_dir < 4; ++ next_dir){
            if (!checkValidDir(cur_dir, next_dir)) continue;
            int u = x, v = y;
            switch (next_dir){
                case 0:
                    v --;
                    break;
                case 1:
                    v ++;
                    break;
                case 2:
                    u --;
                    break;
                case 3:
                    u ++;
                    break;
                default:
                    cout << "Invalid next dir\n";
                    break;
            }
            u = (u + BOARD_SIZE) % BOARD_SIZE;
            v = (v + BOARD_SIZE) % BOARD_SIZE;
            if (!is_valid_block[u][v]) continue;
            if (d[u][v][next_dir] > d[x][y][cur_dir] + 1) {
                d[u][v][next_dir] = d[x][y][cur_dir] + 1;
                trace[u][v][next_dir] = make_pair(make_pair(x, y), cur_dir);
                if (u != goal.first || v != goal.second)
                    q.push(make_pair(make_pair(u, v), next_dir));
            }
        }
    }
    int dir_1 = 3;
    for(int i = 2; i >= 0; -- i) {
        if (d[goal.first][goal.second][i] < d[goal.first][goal.second][dir_1]) dir_1 = i;
    }
    int u = goal.first, v = goal.second;
//    cout << d[u][v][dir_1] << '\n';
    if (d[u][v][dir_1] == (int)1e9){
        // There is no way to reach the food, and I will make the snake run into random dir
        dir_store.push_back(rand() % 4);
        cout << "There is no way to reach the food and I will make the snake run random\n";
        return;
//        exit(0);
    }
    int dir_2;
//    cout << d[u][v][dir_1] << ' ' << dir_1 << ' ';
//    cout << "The goal of us is " << u << ' ' << v << '\n';
//    cout << "We have to go total " << d[u][v][dir_1] << " steps\n";
    while(u != snake.front().rect.x || v != snake.front().rect.y || dir_1 != dir){
        pair<pair<int,int>,int> tmp = trace[u][v][dir_1];
        dir_store.push_back(dir_1);
//        auto [x,y,z] = trace[u][v][dir_1];
        int x, y, z;
        x = tmp.first.first;
        y = tmp.first.second;
        z = tmp.second;
//        cout << x << ' ' << y << ' ' << z << '\n';
        dir_2 = dir_1;
        u = x;
        v = y;
        dir_1 = z;
    }
//    dir_store.push_back(dir_1);
    reverse(dir_store.begin(), dir_store.end());
//    cout << dir << ' ' << dir_1 << '\n';
    static int cnt = 0;
    cnt ++;
//    cout << dir << ' ' << dir_1 << '\n';
    dir = dir_1;
}

bool AI::isValidSnake(){
    vector<vector<bool>> is_occupied;
    is_occupied.resize(BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++){
        is_occupied[i].resize(BOARD_SIZE);
        for (int j = 0; j < BOARD_SIZE; j++){
            is_occupied[i][j] = false;
        }
    }
    for(Block block : snake){
        if (is_occupied[block.rect.x][block.rect.y]){
            return false;
        }
        is_occupied[block.rect.x][block.rect.y] = true;
    }
    return true;
}

