//#include <iostream>
//#include <SDL.h>
////#include <SDL_image.h>
//
////#include "map.h"
////#include "snake.h"
//#include "constant.h"
//
//using namespace std;
//
////void waitUntilKeyPressed()
////{
////    SDL_Event e;
////    while (true) {
////        if ( SDL_PollEvent(&e) != 0 &&
////             (e.type == SDL_KEYDOWN || e.type == SDL_QUIT) )
////            return;
////        SDL_Delay(100);
////    }
////}
//
////Map my_map;
////Snake snake;
//
//int main(int argc, char* argv[])
//{
//    cout << "True";
////    my_map.initSDL();
////    snake.init();
////
////    SDL_Rect headRect = { 100, 100, 32, 32 };
////
////    // Example call to drawSnakeHead (draw the head facing up, with type=true)
////    snake.drawSnakeHead(gRenderer, 0, headRect, true); // 0 = up, true = type 1
////
////    // Update the screen
////    SDL_RenderPresent(gRenderer);
////
////    waitUntilKeyPressed();
////
//////    my_map.createMap();
//////    snake.init();
//////    while(true){
//////        static int cnt = 0;
//////        cnt ++;
//////        cout << cnt << '\n';
//////        my_map.showMap();
//////
//////        SDL_Rect headRect = { 100, 100, 32, 32 };
//////
//////        // Example call to drawSnakeHead (draw the head facing up, with type=true)
//////        snake.drawSnakeHead(gRenderer, 0, headRect, true); // 0 = up, true = type 1
//////
//////        // Update the screen
//////        SDL_RenderPresent(gRenderer);
//////        waitUntilKeyPressed();
//////    }
//    return 0;
//}
//
