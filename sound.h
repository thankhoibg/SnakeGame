#ifndef _SOUND__H
#define _SOUND__H

#include <iostream>
#include <vector>
#include <string>
#include <SDL_mixer.h>

using namespace std;

struct Sound{
    vector<string> music_list = {"BDSM.mp3", "Minecraft.mp3", "NOY.mp3", "TLO.mp3" };
    int cnt = 0;
};

#endif // _SOUND__H
