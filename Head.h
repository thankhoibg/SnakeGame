#ifndef _HEAD__H
#define _HEAD__H

#include <SDL.h>
#include "constant.h"
#include <iostream>
#include <random>
#include <deque>

using namespace std;

//SDL_Surface* head_up;
//SDL_Surface* head_down;
//SDL_Surface* head_left;
//SDL_Surface* head_right;
//
//SDL_Surface* tail_up;
//SDL_Surface* tail_down;
//SDL_Surface* tail_left;
//SDL_Surface* tail_right;
//
//SDL_Surface* body_vertical;
//SDL_Surface* body_horizontal;
//SDL_Surface* body_topleft;
//SDL_Surface* body_bottomleft;
//SDL_Surface* body_topright;
//SDL_Surface* body_bottomright;

void initIMG();
void freeIMG();

struct Head{
    int dir;
    /*
    0 : top
    1 : bottom
    2 : left
    3 : right
    */
    void getNextDir(int dir_){
        dir = dir_;
    }
};

struct Body{
    int dir, dir1;
    /*
    if is_straight = true
    0 : top
    1 : bottom
    2 : left
    3 : right

    if is_straight = false
    0: left->bottom, top->left
    1: top->right, left->bottom
    2: bottom->right, left->top
    3: bottom->left, right->top
    dir1:
    0: left->bottom
    1: top->left
    2: top->right
    3: left->bottom
    4: bottom->righ
    5: left->top
    6: bottom->left
    7: right->top
    */
    bool is_straight = true;
    int dir_tail = 0;
    void getNextDir(const Body& other){
        dir = dir_tail = other.dir;
        is_straight = other.is_straight;
    }
    void getNextDir(const Head& other){
        // in case body is not straight
        if (is_straight == false){
            // the dir of head make the body straight
            // this case is:
            // dir = 0 and head.dir = 1
            // dir = 0 and head.dir = 3

            // dir = 1 and head.dir = 3
            // dir = 1 and head.dir = 1

            // dir = 2 and head.dir = 3
            // dir = 2 and head.dir = 0

            // dir = 3 and head.dir = 2
            // dir = 3 and head.dir = 0

            if (0 && ((dir == 0 && other.dir == 1) || (dir == 0 && other.dir == 3)
              ||(dir == 1 && other.dir == 3) || (dir == 1 && other.dir == 1)
              ||(dir == 2 && other.dir == 3) || (dir == 2 && other.dir == 0)
              ||(dir == 3 && other.dir == 2) || (dir == 3 && other.dir == 0))){
                is_straight = true;
                dir = other.dir;
                dir_tail = other.dir;
            }
            else {
                // the dir of head doesn't make the body straight
                // dir_tail = other.dir;
                is_straight = false;
                switch (dir1){
                    case 0:
                        switch(other.dir){
                            case 0:
                                // cout << "Opposite dir\n";
                                // cout << dir1 << ' ' << other.dir << '\n';
                                // exit(0);
                                break;
                            case 1:
                                // cout << "Make the body straight\n";
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 2:
                                dir1 = 6;
                                dir = 3;
                                break;
                            case 3:
                                dir1 = 4;
                                dir = 2;
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 1:
                        switch(other.dir){
                            case 0:
                                dir1 = 5;
                                dir = 2;
                                break;
                            case 1:
                                dir1 = 3;
                                dir = 1;
                                break;
                            case 2:
                                // cout << "Make the body straight\n";
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 3:
                                // cout << "Opposite dir\n";
                                // cout << dir1 << ' ' << other.dir << '\n';
                                // exit(0);
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 2:
                        switch(other.dir){
                            case 0:
                                dir1 = 7;
                                dir = 3;
                                break;
                            case 1:
                                dir1 = 0;
                                dir = 0;
                                break;
                            case 2:
                                // cout << "Make the body straight\n";
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 3:
                                // cout << "Opposite dir\n";
                                // cout << dir1 << ' ' << other.dir << '\n';
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 3:
                        switch(other.dir){
                            case 0:
                                // cout << "Opposite dir\n";
                                // cout << dir1 << ' ' << other.dir << '\n';
                                // exit(0);
                                break;
                            case 1:
                                // cout << "Make the body straight\n";
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 2:
                                dir1 = 6;
                                dir = 3;
                                break;
                            case 3:
                                dir1 = 4;
                                dir = 2;
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 4:
                        switch(other.dir){
                            case 0:
                                dir1 = 7;
                                dir = 3;
                                break;
                            case 1:
                                dir1 = 0;
                                dir = 0;
                                break;
                            case 2:
                                // cout << "Opposite dir\n";
                                // cout << dir1 << ' ' << other.dir << '\n';
                                // exit(0);
                                break;
                            case 3:
                                // cout << "Make the body straight\n";
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 5:
                        switch(other.dir){
                            case 0:
                                // cout << "Make the body straight\n";
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 1:
                                // cout << "Opposite dir\n";
                                // cout << dir1 << ' ' << other.dir << '\n';
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 2:
                                dir1 = 1;
                                dir = 0;
                                break;
                            case 3:
                                dir1 = 2;
                                dir = 1;
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 6:
                        switch(other.dir){
                            case 0:
                                dir1 = 5;
                                dir = 2;
                                break;
                            case 1:
                                dir1 = 3;
                                dir = 1;
                                break;
                            case 2:
                                // cout << "Make the body straight\n";
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 3:
                                // cout << "Opposite dir\n";
                                // cout << dir1 << ' ' << other.dir << '\n';
                                // exit(0);
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 7:
                        switch(other.dir){
                            case 0:
                                // cout << "Make the body straight\n";
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 1:
                                // cout << "Opposite dir\n";
                                // cout << dir1 << ' ' << other.dir << '\n';
                                // exit(0);
                                is_straight = true;
                                dir = dir_tail = other.dir;
                                break;
                            case 2:
                                dir1 = 1;
                                dir = 0;
                                break;
                            case 3:
                                dir1 = 2;
                                dir = 1;
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    default:
                        cout << "Error dir\n";
                        exit(0);
                        break;
                }
            }
        }
        else {
            // the body is straight
            // if the dir of head make the body still straight
            if (dir == other.dir){
                is_straight = true;
                dir_tail = other.dir;
            }
            else {
                // if the dir of head make the body is not straight
                is_straight = false;
                dir_tail = other.dir;
                switch (dir){
                    case 0:
                        switch(other.dir){
                            case 0:
                                cout << "Body straight\n";
                                exit(0);
                                break;
                            case 1:
                                cout << "Opposite dir1\n";
                                cout << dir << ' ' << other.dir << '\n';
                                exit(0);
                                break;
                            case 2:
                                dir1 = 1;
                                dir = 0;
                                break;
                            case 3:
                                dir1 = 2;
                                dir = 1;
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 1:
                        switch(other.dir){
                            case 0:
                                cout << "Opposite dir1\n";
                                cout << dir << ' ' << other.dir << '\n';
                                exit(0);
                                break;
                            case 1:
                                cout << "Body straight\n";
                                exit(0);
                                break;
                            case 2:
                                dir1 = 6;
                                dir = 3;
                                break;
                            case 3:
                                dir1 = 4;
                                dir = 2;
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 2:
                        switch(other.dir){
                            case 0:
                                dir1 = 5;
                                dir = 2;
                                break;
                            case 1:
                                dir1 = 3;
                                dir = 1;
                                break;
                            case 2:
                                cout << "Body straight\n";
                                exit(0);
                                break;
                            case 3:
                                cout << "Opposite dir1\n";
                                cout << dir << ' ' << other.dir << '\n';
                                exit(0);
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    case 3:
                        switch(other.dir){
                            case 0:
                                dir1 = 7;
                                dir = 3;
                                break;
                            case 1:
                                dir1 = 0;
                                dir = 0;
                                break;
                            case 2:
                                cout << "Opposite dir1\n";
                                cout << dir << ' ' << other.dir << '\n';
                                exit(0);
                                break;
                            case 3:
                                cout << "Body straight\n";
                                exit(0);
                                break;
                            default:
                                cout << "Error dir\n";
                                exit(0);
                                break;
                        }
                        break;
                    default:
                        cout << "Error dir\n";
                        exit(0);
                        break;
                }
            }
        }
        if (is_straight) dir_tail = dir;
        else {
            if (dir1 == 0 || dir1 == 7) dir_tail = 3;
            else if (dir1 == 3 || dir1 == 5) dir_tail = 2;
            else if (dir1 == 1 || dir1 == 2) dir_tail = 0;
            else if (dir1 == 4 || dir1 == 6) dir_tail = 1;
            else {
                cout << "Error dir1\n";
                exit(0);
            }
        }
    }
};

struct Tail{
    int dir;
    /*
    0 : top
    1 : bottom
    2 : left
    3 : right
    */
    void getNextDir(const Body& other){
        dir = other.dir_tail;
    }
};

struct Food{
    int count = 0, type = 0;
};

// struct BigFood{
//     bool is_appear = false;
// };

struct Wall{
    bool is_odd = 0;
};

class Block {
public:
    enum class Type { Head, Body, Tail, Wall, Food, Empty };
    SDL_Rect rect = {0, 0, CELL_SIZE, CELL_SIZE};
    void getPos(int x, int y){
        rect.x = x;
        rect.y = y;
    }

private:
    Type type = Type::Empty;
    union {
        Head head;
        Body body;
        Tail tail;
        Food food;
        // BigFood big_food;
    };

public:
    Block() {} // Default constructor

    // Constructor that initializes head. Crucial to prevent garbage data.
    Block(const Head& initialHead) : type(Type::Head) {
        head = initialHead;
    }

    // Constructor that initializes Body.
    Block(const Body& initialBody) : type(Type::Body) {
        body = initialBody;
    }

    // Constructor that initializes Tail
    Block(const Tail& initialTail) : type(Type::Tail) {
        tail = initialTail;
    }

    // Constructor that initializes Food
    Block(const Food& initialFood) : type(Type::Food) {
        food = initialFood;
    }

    // Constructor that initializes Food
    // Block(const BigFood& initialBigFood) : type(Type::BigFood) {
    //     big_food = initialBigFood;
    // }


    Type getType() const { return type; }

    void setHead() {
        type = Type::Head; // Set the type of the block
    }
    void setBody() {
        type = Type::Body; // Set the type of the block
    }
    void setTail() {
        type = Type::Tail; // Set the type of the block
    }
    void setFood(){
        type = Type::Food; // Set the type of the block
    }
    // void setBigFood(){
    //     type = Type::BigFood; // Set the type of the block
    // }

    Head& getHead() {
        if (type != Type::Head) {
            std::cerr << "Error: Block is not a Head!\n";
            exit(1); // Or throw an exception
        }
        return head;
    }

    const Head& getHead() const {
        if (type != Type::Head) {
            std::cerr << "Error: Block is not a Head!\n";
            exit(1); // Or throw an exception
        }
        return head;
    }

    Body& getBody() {
        if (type != Type::Body) {
            std::cerr << "Error: Block is not a Body!\n";
            exit(1); // Or throw an exception
        }
        return body;
    }

    const Body& getBody() const {
        if (type != Type::Body) {
            std::cerr << "Error: Block is not a Body!\n";
            exit(1); // Or throw an exception
        }
        return body;
    }

    Tail& getTail() {
        if (type != Type::Tail) {
            std::cerr << "Error: Block is not a Tail!\n";
            exit(1); // Or throw an exception
        }
        return tail;
    }

    const Tail& getTail() const {
        if (type != Type::Tail) {
            std::cerr << "Error: Block is not a Tail!\n";
            exit(1); // Or throw an exception
        }
        return tail;
    }

    Food& getFood() {
        if (type != Type::Food) {
            std::cerr << "Error: Block is not a Tail!\n";
            exit(1); // Or throw an exception
        }
        return food;
    }

    const Food& getFood() const {
        if (type != Type::Food) {
            std::cerr << "Error: Block is not a Tail!\n";
            exit(1); // Or throw an exception
        }
        return food;
    }

    // BigFood& getBigFood() {
    //     if (type != Type::BigFood) {
    //         std::cerr << "Error: Block is not a Tail!\n";
    //         exit(1); // Or throw an exception
    //     }
    //     return big_food;
    // }
    // const BigFood& getBigFood() const {
    //     if (type != Type::BigFood) {
    //         std::cerr << "Error: Block is not a Tail!\n";
    //         exit(1); // Or throw an exception
    //     }
    //     return big_food;
    // }


    void modify(){
        if (rect.x < 0) rect.x = BOARD_SIZE-1;
        if (rect.x == BOARD_SIZE) rect.x = 0;
        if (rect.y < 0) rect.y = BOARD_SIZE-1;
        if (rect.y == BOARD_SIZE) rect.y = 0;
    }

    void genFood(deque<Block> snake, int typee = 0){
        // if (type != Type::Food || type != Type::BigFood){ {
        //     cout << "It's not a food\n";
        //     return;
        // }
        if (type != Type::Food){
            cout << "It's not a food\n";
            return;
        }
        int M = 5;
        if (typee == 0) {food.count ++; food.count %= M;}
        // if (food.count == M-1) big_food.is_appear = true;
        // else big_food.is_appear = false;
        int x, y;
        if (typee == 0){
            x = rand() % BOARD_SIZE;
            y = rand() % BOARD_SIZE;
            while(true){
                bool ok = true;
                for(Block block : snake){
                    if (food.type == 0 && x == block.rect.x && y == block.rect.y) ok = false;
                }
                if (ok) break;
                x = rand() % BOARD_SIZE;
                y = rand() % BOARD_SIZE;
            }
            rect.x = x;
            rect.y = y;
        }
        else {
            // x = rand() % (BOARD_SIZE - 1);
            // y = rand() % (BOARD_SIZE - 1);
            // while(true){
            //     bool ok = true;
            //     for(Block block : snake){
            //         if (x <= block.rect.x && x + 1 >= block.rect.x && y <= block.rect.y && y + 1 >= block.rect.y) ok = false;
            //     }
            //     if (ok) break;
            //     x = rand() % (BOARD_SIZE - 1);
            //     y = rand() % (BOARD_SIZE - 1);
            // }
            // rect.x = x;
            // rect.y = y;
        }
        rect.x = x;
        rect.y = y;
    }
    void draw();
    void drawHead();
    void drawBody();
    void drawTail();
    void drawWall(){
        cout << "Chua tao\n";
    }
    void drawFood();
};

#endif // _HEAD__H
