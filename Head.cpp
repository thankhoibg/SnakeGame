#include "Head.h"
#include "constant.h"
#include <iostream>
#include <SDL.h>

using namespace std;

SDL_Surface* head_up;
SDL_Surface* head_down;
SDL_Surface* head_left;
SDL_Surface* head_right;

SDL_Surface* tail_up;
SDL_Surface* tail_down;
SDL_Surface* tail_left;
SDL_Surface* tail_right;

SDL_Surface* body_vertical;
SDL_Surface* body_horizontal;
SDL_Surface* body_topleft;
SDL_Surface* body_bottomleft;
SDL_Surface* body_topright;
SDL_Surface* body_bottomright;

SDL_Surface* apple;

void initIMG(){
    head_up = IMG_Load("img/head_up.png");
    head_down = IMG_Load("img/head_down.png");
    head_left = IMG_Load("img/head_left.png");
    head_right = IMG_Load("img/head_right.png");

    tail_up = IMG_Load("img/tail_up.png");
    tail_down = IMG_Load("img/tail_down.png");
    tail_left = IMG_Load("img/tail_left.png");
    tail_right = IMG_Load("img/tail_right.png");

    body_vertical      = IMG_Load("img/body_vertical.png");
    body_horizontal      = IMG_Load("img/body_horizontal.png");
    body_topleft      = IMG_Load("img/body_topleft.png");
    body_bottomleft      = IMG_Load("img/body_bottomleft.png");
    body_topright      = IMG_Load("img/body_topright.png");
    body_bottomright      = IMG_Load("img/body_bottomright.png");

    apple = IMG_Load("img/apple.png");

}
void freeIMG(){
    SDL_FreeSurface(head_up);
    SDL_FreeSurface(head_down);
    SDL_FreeSurface(head_left);
    SDL_FreeSurface(head_right);

    SDL_FreeSurface(tail_up);
    SDL_FreeSurface(tail_down);
    SDL_FreeSurface(tail_left);
    SDL_FreeSurface(tail_right);

    SDL_FreeSurface(body_vertical);
    SDL_FreeSurface(body_horizontal);
    SDL_FreeSurface(body_topleft);
    SDL_FreeSurface(body_bottomleft);
    SDL_FreeSurface(body_topright);
    SDL_FreeSurface(body_bottomright);

    SDL_FreeSurface(apple);
}

void Block::draw(){
    switch (type){
        case Type::Head:
            drawHead();
            break;
        case Type::Body:
            drawBody();
            break;
        case Type::Tail:
            drawTail();
            break;
        case Type::Wall:
            drawWall();
            break;
        case Type::Food:
            drawFood();
            break;
        default:
            cout << "Cann't regconize type of Block when draw\n";
            exit(0);
            break;
    }
}

void Block::drawHead(){
    SDL_Texture* gTexture;

    int dir = head.dir;
    if (dir == 0) gTexture = SDL_CreateTextureFromSurface(gRenderer, head_up);
    else if (dir == 1) gTexture = SDL_CreateTextureFromSurface(gRenderer, head_down);
    else if (dir == 2) gTexture = SDL_CreateTextureFromSurface(gRenderer, head_left);
    else if (dir == 3) gTexture = SDL_CreateTextureFromSurface(gRenderer, head_right);
    else {
        cout << "Can not regconize the direction of Head\n";
        exit(0);
    }
    SDL_Rect rect1;
    rect1.x = rect.x * CELL_SIZE;
    rect1.y = rect.y * CELL_SIZE;
    rect1.w = CELL_SIZE;
    rect1.h = CELL_SIZE;
    SDL_RenderCopy(gRenderer, gTexture, nullptr, &rect1);

    SDL_DestroyTexture(gTexture);
}

void Block::drawBody(){
    SDL_Texture* gTexture;

    int dir = body.dir;
    bool is_straight = body.is_straight;
    if (is_straight) {
        if (dir == 0 || dir == 1) gTexture = SDL_CreateTextureFromSurface(gRenderer, body_vertical);
        else if (dir == 2 || dir == 3) gTexture = SDL_CreateTextureFromSurface(gRenderer, body_horizontal);
        else {
            cout << "Can not regconize the direction of Body when it is straight\n";
            exit(0);
        }
    } else {
        if (dir == 0) gTexture = SDL_CreateTextureFromSurface(gRenderer, body_bottomleft);
        else if (dir == 1) gTexture = SDL_CreateTextureFromSurface(gRenderer, body_bottomright);
        else if (dir == 2) gTexture = SDL_CreateTextureFromSurface(gRenderer, body_topright);
        else if (dir == 3) gTexture = SDL_CreateTextureFromSurface(gRenderer, body_topleft);
        else {
            cout << "Can not regconize the direction of Body when it it not straight\n";
            exit(0);
        }
    }
    SDL_Rect rect1;
    rect1.x = rect.x * CELL_SIZE;
    rect1.y = rect.y * CELL_SIZE;
    rect1.w = CELL_SIZE;
    rect1.h = CELL_SIZE;
    SDL_RenderCopy(gRenderer, gTexture, nullptr, &rect1);

    SDL_DestroyTexture(gTexture);
}

void Block::drawTail(){
    SDL_Texture* gTexture;

    int dir = tail.dir;
    if (dir == 1) gTexture = SDL_CreateTextureFromSurface(gRenderer, tail_up);
    else if (dir == 0) gTexture = SDL_CreateTextureFromSurface(gRenderer, tail_down);
    else if (dir == 3) gTexture = SDL_CreateTextureFromSurface(gRenderer, tail_left);
    else if (dir == 2) gTexture = SDL_CreateTextureFromSurface(gRenderer, tail_right);
    else {
        cout << "Can not regconize the direction of Tail\n";
        exit(0);
    }
    SDL_Rect rect1;
    rect1.x = rect.x * CELL_SIZE;
    rect1.y = rect.y * CELL_SIZE;
    rect1.w = CELL_SIZE;
    rect1.h = CELL_SIZE;
    SDL_RenderCopy(gRenderer, gTexture, nullptr, &rect1);

    SDL_DestroyTexture(gTexture);
}

void Block::drawFood(){
    SDL_Texture* gTexture;

    gTexture = SDL_CreateTextureFromSurface(gRenderer, apple);
    SDL_Rect rect1;
    int d = 1;
    // if (food.type == 1) d = 2;
    rect1.x = rect.x * CELL_SIZE;
    rect1.y = rect.y * CELL_SIZE;
    rect1.w = CELL_SIZE * d;
    rect1.h = CELL_SIZE * d;
    static int count = 0;
    count ++;
    switch (count%5){
        case 0:
            rect1.x -= 1;
            rect1.y -= 1;
            rect1.w += 1;
            rect1.h += 1;
            break;
        case 1:
            rect1.x -= 2;
            rect1.y -= 2;
            rect1.w += 2;
            rect1.h += 2;
            break;
        case 2:
            rect1.x -= 3;
            rect1.y -= 3;
            rect1.w += 3;
            rect1.h += 3;
            break;
        case 3:
            rect1.x -= 4;
            rect1.y -= 4;
            rect1.w += 4;
            rect1.h += 4;
            break;
        case 4:
            rect1.x -= 5;
            rect1.y -= 5;
            rect1.h += 5;
            rect1.w += 5;
            break;
        default:
            break;
    }
    SDL_RenderCopy(gRenderer, gTexture, nullptr, &rect1);

    switch (count%5){
        case 0:
            rect1.x += 1;
            rect1.y -= 1;
            rect1.w -= 1;
            rect1.h -= 1;
            break;
        case 1:
            rect1.x += 2;
            rect1.y += 2;
            rect1.w -= 2;
            rect1.h -= 2;
            break;
        case 2:
            rect1.x += 3;
            rect1.y += 3;
            rect1.w -= 3;
            rect1.h -= 3;
            break;
        case 3:
            rect1.x += 4;
            rect1.y += 4;
            rect1.w -= 4;
            rect1.h -= 4;
            break;
        case 4:
            rect1.x += 5;
            rect1.y += 5;
            rect1.h -= 5;
            rect1.w -= 5;
            break;
        default:
            break;
    }

    SDL_DestroyTexture(gTexture);
}
