//#include "Block.h"
//
//void Block::setCurAndType(const Block& other){
//    // check if this block and other block is Head or Body or not
//    // if one of two block is not Head or Body, annouce and exit
//    if ((blockType != Type::Head && blockType != Type::Body) || (other.blockType != BlockType::Head && other.blockType != BlockType::Body)) {
//        cout << "This block or other block is not Head or Body\n";
//        exit(0);
//    }
//    /*
//    0 : Top
//    1 : Bottom
//    2 : Left
//    3 : Right
//    */
//    // Top to Left or Right to Bottom
//    // Type = 0
//    if ((getCur() == 0 && other.getCur() == 2) || (getCur() == 3 && other.getCur() == 1)){
//        setCur(other.getCur());
//        setType(0);
//    }
//    // Top to Right or Left to Bottom
//    // Type = 1
//    if ((getCur() == 0 && other.getCur() == 3) || (getCur() == 2 && other.getCur() == 1)){
//        setCur(other.getCur());
//        setType(1);
//    }
//    // Bottom to Left or Right to Top
//    // Type = 2
//    if ((getCur() == 1 && other.getCur() == 2) || (getCur() == 3 && other.getCur() == 0)){
//        setCur(other.getCur());
//        setType(2);
//    }
//    // Bottom to Right or Left to Top
//    // Type = 3
//    if ((getCur() == 1 && other.getCur() == 3) || (getCur() == 2 && other.getCur() == 0)){
//        setCur(other.getCur());
//        setType(3);
//    }
//}
//
//void Block::setCur(const Block& other){
//
//}
//
//int Block::getCur(){
//    if (blockType == Type::Head) {
//        Head* head = (Head*)this; // Cast 'this' to a Head pointer
//
//        //Safe cast for safety
//        if (head == nullptr) {
//            cout << "Have not init the cur of Head\n";
//            exit(0);
//            return -1; // Invalid
//        }
//        return head->cur;
//    } else if (blockType == Type::Body) {
//        Body* body = (Body*)this; // Cast 'this' to a Body pointer
//
//        //Safe cast for safety
//        if (body == nullptr) {
//            cout << "Have not init the cur of Body\n";
//            exit(0);
//            return -1; // Invalid
//        }
//        return body->cur;
//    } else {
//        cout << "This Block is not Body or Head\n";
//        exit(0);
//        return -1;
//    }
//}
//
//int Block::getType(){
//    if (blockType == Type::Head) {
//        Head* head = (Head*)this; // Cast 'this' to a Head pointer
//
//        //Safe cast for safety
//        if (head == nullptr) {
//            cout << "Have not init the type of Head\n";
//            exit(0);
//            return -1; // Invalid
//        }
//        return head->type;
//    } else if (blockType == Type::Body) {
//        Body* body = (Body*)this; // Cast 'this' to a Body pointer
//
//        //Safe cast for safety
//        if (body == nullptr) {
//            cout << "Have not init the type of Body\n";
//            exit(0);
//            return -1; // Invalid
//        }
//        return body->type;
//    } else {
//        cout << "This Block is not Body or Head\n";
//        exit(0);
//        return -1;
//    }
//}
