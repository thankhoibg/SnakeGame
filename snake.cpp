#include "snake.h"
#include "constant.h"
#include "graphics.h"

void Snake::init(){
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
}

void Snake::draw(){
    for (auto& block : snake){
        block.draw();
    }
    food.draw();
    if (!is_alive){
        freeIMG();
        quitSDL();
        exit(0);
    }
}

void Snake::move() { // Takes the event as an argument
    dem ++;
    if (dem == 1) return;
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
    bool have_eat_food = false;
    if (food.getFood().type == 0 && new_head.rect.x == food.rect.x && new_head.rect.y == food.rect.y){
        have_eat_food = true;
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
            // body.getBody().getNextDir(snake1.back().getBody());
            body = last;
        }
        snake1.push_back(body);
        last = tmp;
    }
    if (!have_eat_food){
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
    if (have_eat_food){
        food.genFood(snake);
    }
    if (!isValidSnake()){
        cout << "Snake eat itself\n";
        is_alive = false;
    }
}



void Snake::getDir() {
    // cout << dir << '\n';
    SDL_Event e;
    if (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_KEYDOWN) {
            switch (e.key.keysym.sym) {
                case SDLK_w:
                    if (dir != 1) dir = 0;
                    dem ++;
                    // ok = 1;
                    break;
                case SDLK_a:
                    if (dir != 3) dir = 2;
                    dem ++;
                    // ok = 1;
                    break;
                case SDLK_s:
                    if (dir != 0) dir = 1;
                    dem ++;
                    // ok = 1;
                    break;
                case SDLK_d:
                    if (dir != 2) dir = 3;
                    dem ++;
                    // ok = 1;
                    break;
                case SDLK_UP: // Arrow up key
                    if (dir != 1) dir = 0;
                    dem ++;
                    // ok = 1;
                    break;
                case SDLK_DOWN: // Arrow down key
                    if (dir != 0) dir = 1;
                    dem ++;
                    // ok = 1;
                    break;
                case SDLK_LEFT: // Arrow left key
                    if (dir != 3) dir = 2;
                    dem ++;
                    // ok = 1;
                    break;
                case SDLK_RIGHT: // Arrow right key
                    if (dir != 2) dir = 3;
                    dem ++;
                    // ok = 1;
                    break;
                default:
                    break;
            }
        }
    }
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
