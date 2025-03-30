#include "snake.h"
#include "constant.h"
#include "graphics.h"
#include <ctime>
#include <SDL.h>
#include <SDL_image.h>
#include "button.h"

SDL_Surface* score_back_ground;

void Snake::init(){
    score = 0;
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

    // score board will load the image in the rect{640, 0, 320, 640} at first
    // score board will load the apple image at the middle of the rect{640, 0, 320, 640}
    // score board will load the score text right after the score text
    score_board.setValue(to_string(score));
    score_board.setFont("segoesc.ttf", 50);
    score_board.setRect(700, 40, 50, 70);
    score_board.color = Black;
    score_board.draw(Black, Red);
    score_back_ground = IMG_Load("img/ScoreBackGround.jpg");

    clock_t start_time = clock();
}

void Snake::draw(){
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
    clock_t now = clock();
    double timee = now - start_time;
    if (timee - big_food.getBigFood().time_appear > TIME_BIG_FOOD) {
        big_food.getBigFood().is_appear = false;
        // big food disappear beacause over TIME_BIG_FOOD ms, the snake does not eat big food.
    }
//    cout << timee - big_food.getBigFood().time_appear << '\n';
    if (big_food.getBigFood().is_appear) big_food.draw();

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

int Snake::move(int &id) { // Takes the event as an argument
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
    bool have_eat_food = false, have_eat_big_food = false;
    if (new_head.rect.x == food.rect.x && new_head.rect.y == food.rect.y){
        have_eat_food = true;
    }
    if (big_food.getBigFood().is_appear && new_head.rect.x >= big_food.rect.x && new_head.rect.x <= big_food.rect.x + 1 && new_head.rect.y >= big_food.rect.y && new_head.rect.y <= big_food.rect.y + 1){
        have_eat_big_food = true;
        cout << "Big food has been eaten\n";
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
    snake = snake1;
    if (have_eat_big_food){
        big_food.getBigFood().is_appear = false;
        food.getFood().count = 0;
        length ++;
        score += 5;
    }
    if (have_eat_food){
        food.genFood(snake);
        food.getFood().count ++;
        food.getFood().count %= M;
        length ++;
        score ++;
    }
    if (!isValidSnake()){
        cout << "Snake eat itself\n";
        is_alive = false;
        id = 3;
        return score;
    }
}



// void Snake::getDir() {
//     // cout << dir << '\n';
//     SDL_Event e;
//     if (SDL_PollEvent(&e) != 0) {
//         if (e.type == SDL_KEYDOWN) {
//             switch (e.key.keysym.sym) {
//                 case SDLK_w:
//                     if (dir != 1) dir = 0;
//                     dem ++;
//                     // ok = 1;
//                     break;
//                 case SDLK_a:
//                     if (dir != 3) dir = 2;
//                     dem ++;
//                     // ok = 1;
//                     break;
//                 case SDLK_s:
//                     if (dir != 0) dir = 1;
//                     dem ++;
//                     // ok = 1;
//                     break;
//                 case SDLK_d:
//                     if (dir != 2) dir = 3;
//                     dem ++;
//                     // ok = 1;
//                     break;
//                 case SDLK_UP: // Arrow up key
//                     if (dir != 1) dir = 0;
//                     dem ++;
//                     // ok = 1;
//                     break;
//                 case SDLK_DOWN: // Arrow down key
//                     if (dir != 0) dir = 1;
//                     dem ++;
//                     // ok = 1;
//                     break;
//                 case SDLK_LEFT: // Arrow left key
//                     if (dir != 3) dir = 2;
//                     dem ++;
//                     // ok = 1;
//                     break;
//                 case SDLK_RIGHT: // Arrow right key
//                     if (dir != 2) dir = 3;
//                     dem ++;
//                     // ok = 1;
//                     break;
//                 default:
//                     break;
//             }
//         }
//     }
// }

void Snake::getDir(bool &is_clicked_p) {
    SDL_Event e;
    int last_dir = dir; // Store the current direction as a default

    while (SDL_PollEvent(&e) != 0) { // Process ALL events in the queue
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_w:
                    if (last_dir != 1) last_dir = 0;
                    else last_dir = 1;
                    dem ++;
                    break;
                case SDLK_a:
                    if (last_dir != 3) last_dir = 2;
                    else last_dir = 3;
                    dem ++;
                    break;
                case SDLK_s:
                    if (last_dir != 0) last_dir = 1;
                    else last_dir = 0;
                    dem ++;
                    break;
                case SDLK_d:
                    if (last_dir != 2) last_dir = 3;
                    else last_dir = 2;
                    dem ++;
                    break;
                case SDLK_UP:
                    if (last_dir != 1) last_dir = 0;
                    else last_dir = 1;
                    dem ++;
                    break;
                case SDLK_DOWN:
                    if (last_dir != 0) last_dir = 1;
                    else last_dir = 0;
                    dem ++;
                    break;
                case SDLK_LEFT:
                    if (last_dir != 3) last_dir = 2;
                    else last_dir = 3;
                    dem ++;
                    break;
                case SDLK_RIGHT:
                    if (last_dir != 2) last_dir = 3;
                    else last_dir = 2;
                    dem ++;
                    break;
                case SDLK_p:
                    is_clicked_p = true;
                    break;
                default:
                    break;
            }
        }
    }
    dir = last_dir; // Update the actual snake direction with the last processed input
}

bool Snake::isValidSnake(){
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
