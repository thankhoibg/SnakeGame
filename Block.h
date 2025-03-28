#ifndef _BLOCK__H
#define _BLOCK__H

#include <iostream>
#include <SDL.h>

#include "constant.h"

using namespace std;

struct Head{
    // if type is Head
    // when we move, Head becomes Body and there are 4 cases:
    /* (direction) -> (direction)
    - Left -> Top ( = Top -> Left) :    0
    - Left -> Down ( = Down -> Left):   1
    - Right -> Top ( = Top -> Right):   2
    - Right -> Down ( = Down -> Right): 3
    */
    int cur = 0; // current direction
    int type = 0; // type of Head when it move to nexts Block
};
struct Body{
    int cur = 0; // current direction
    int type = 0; // type of Body when it moves to next Block
};
struct Food{
};
struct Empty{
};
class Block{
    public:
        enum class Type {
            Head,
            Body,
            Food,
            Empty
        };
        Type blockType;
        Block(Type type) : blockType(type) {}
        Type getType() const {
            return blockType;
        }
        bool isSameType(const Block& other) const {
            return (this->blockType == other.blockType);
        }
        bool isType(Type type) const {
            return (this->blockType == type);
        }
        void setType(Type newType) {
            blockType = newType;
        }
        void setCur(const Block& other);
        int getCur();
        int getType();

        SDL_Rect pos = {0, 0, CELL_SIZE, CELL_SIZE};
};

Block headBlock(Block::Type::Head);
Block bodyBlock(Block::Type::Body);


#endif // _BLOCK__H
