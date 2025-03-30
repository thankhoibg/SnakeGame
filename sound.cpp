#include "sound.h"

void Sound::init(){
    eat_apple = loadSound("sound\crunch.wav");
    back_ground_music = loadMusic(cnt);
}

void Sound::free(){
    Mix_FreeChunk(eat_apple);
    Mix_FreeMusic(back_ground_music);
}

void Sound::playBackGroundMusic(){
    play(back_ground_music);
}

void Sound::playEatAppleSound(){
    play(eat_apple);
}
