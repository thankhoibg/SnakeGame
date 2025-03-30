#include <SDL.h>
#include <SDL_mixer.h>
#include <iostream>
#include <vector>
#include <string>

#ifdef _WIN32
#include <direct.h> // For _getcwd on Windows
#define getcwd _getcwd
#else
#include <unistd.h> // For getcwd on POSIX systems
#endif

using namespace std;

// Global music list (replace with your actual list)
vector<string> music_list = {"BDSM.mp3"};

Mix_Music *loadMusic(int music_index) {
    int len = music_list.size();
    music_index %= len;
    music_index += len;
    music_index %= len;
    string path = "sound\\" + music_list[music_index];
    cout << "Attempting to load: " << path << '\n';
    Mix_Music *gMusic = Mix_LoadMUS(path.c_str());
    if (gMusic == nullptr) {
        SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_ERROR,
                        "Could not load music! SDL_mixer Error: %s", Mix_GetError());
    }
    return gMusic;
}

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_AUDIO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Initialize SDL_mixer
    if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 2048) < 0) {
        std::cerr << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // Get the current working directory
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != nullptr) {
        std::cout << "Current working directory: " << cwd << std::endl;
    } else {
        std::cerr << "getcwd() failed\n";
        // Handle the error, maybe set a default path
    }

    // Load music (example)
    Mix_Music *music = loadMusic(0);
    if (music) {
        std::cout << "Music loaded successfully!" << std::endl;
        // Play the music (example)
        //Mix_PlayMusic(music, -1); // Play in a loop

        // Wait for a bit so we can actually hear the music
        SDL_Delay(5000);  // Delay for 5 seconds

        // Clean up
        Mix_FreeMusic(music);
    } else {
        std::cerr << "Failed to load music." << std::endl;
    }

    // Quit SDL_mixer
    Mix_Quit();

    // Quit SDL
    SDL_Quit();

    return 0;
}