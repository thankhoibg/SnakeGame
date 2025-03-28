#include "map.h"

void Map::drawBoard() {
    int cnt = 0;

    SDL_RenderClear(gRenderer);

    for (int y = 0; y < BOARD_SIZE; ++y) {
        for (int x = 0; x < BOARD_SIZE; ++x) {
            SDL_Rect rect = {y * CELL_SIZE, x * CELL_SIZE, CELL_SIZE, CELL_SIZE};
            if (cnt % 2) {
                SDL_SetRenderDrawColor(gRenderer, 126, 166, 4, 255);
                SDL_RenderFillRect(gRenderer, &rect);
            } else {
                SDL_SetRenderDrawColor(gRenderer, 107,142,35, 255);
                SDL_RenderFillRect(gRenderer, &rect);
            }
            cnt++;
        }
        cnt++;
    }
}
