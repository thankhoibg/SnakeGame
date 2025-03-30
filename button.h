#ifndef _BUTTON__H
#define _BUTTON__H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <cstring>
#include <iostream>

#include "constant.h"

using namespace std;

struct Button{
    SDL_Rect rect;
    TTF_Font* font;
    SDL_Color color;
    string value = "";
    bool is_clicked = false;
    bool isFocused(int mouse_x, int mouse_y){
        int x = rect.x, y = rect.y, u = rect.x + rect.w - 1, v = rect.y + rect.h - 1;
        if (x <= mouse_x && u >= mouse_x && y <= mouse_y && v >= mouse_y) return true;
        return false;
    }
    void setValue(string value_){
        value = value_;
    }
    void setFont(string font_path, int size){
        font = TTF_OpenFont(font_path.c_str(), size);
    }
    void setRect(int x, int y, int w, int h){
        rect.x = x;
        rect.y = y;
        rect.w = w;
        rect.h = h;
    }
    void freeFont(){
        TTF_CloseFont(font);
    }
    SDL_Texture* loadTextureFromPath(string file_path);
    SDL_Texture* loadTextureFromPath(string file_path, SDL_Rect rect);
    void draw(){
      SDL_Surface* textSurface = TTF_RenderText_Solid(font, value.c_str(), color);
      SDL_Texture* gTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
      SDL_RenderCopy(gRenderer, gTexture, NULL, &rect);

      SDL_FreeSurface(textSurface);
      SDL_DestroyTexture(gTexture);
    }
    void draw(SDL_Color inline_color, SDL_Color outline_color){
        SDL_Surface* textSurface;
        SDL_Texture* textTexture;
        SDL_Rect textRect;

        // --- Render the outline (black) ---

        // Render text to surface (using outline color)
        textSurface = TTF_RenderText_Solid(font, value.c_str(), outline_color);
        if (!textSurface) {
            std::cerr << "TTF_RenderText_Solid (outline) failed: " << TTF_GetError() << std::endl;
            return; // Handle error appropriately
        }

        // Create texture from surface
        textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (!textTexture) {
            std::cerr << "SDL_CreateTextureFromSurface (outline) failed: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(textSurface);
            return;
        }

        SDL_RenderCopy(gRenderer, textTexture, NULL, &rect);
        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);

       // slight offset for the other directions
        textSurface = TTF_RenderText_Solid(font, value.c_str(), outline_color);
        if (!textSurface) {
            std::cerr << "TTF_RenderText_Solid (outline) failed: " << TTF_GetError() << std::endl;
            return; // Handle error appropriately
        }

        // Create texture from surface
        textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (!textTexture) {
            std::cerr << "SDL_CreateTextureFromSurface (outline) failed: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(textSurface);
            return;
        }

        // Get the size of the text texture
        textRect = {rect.x+ 1, rect.y+ 1, rect.w, rect.h}; // slight offset
        SDL_RenderCopy(gRenderer, textTexture, NULL, &textRect);
        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);

         // slight offset for the other directions
        textSurface = TTF_RenderText_Solid(font, value.c_str(), outline_color);
        if (!textSurface) {
            std::cerr << "TTF_RenderText_Solid (outline) failed: " << TTF_GetError() << std::endl;
            return; // Handle error appropriately
        }

        // Create texture from surface
        textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (!textTexture) {
            std::cerr << "SDL_CreateTextureFromSurface (outline) failed: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(textSurface);
            return;
        }

        // Get the size of the text texture
        textRect = {rect.x+ 1, rect.y- 1, rect.w, rect.h}; // slight offset
        SDL_RenderCopy(gRenderer, textTexture, NULL, &textRect);
        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);

             // slight offset for the other directions
        textSurface = TTF_RenderText_Solid(font, value.c_str(), outline_color);
        if (!textSurface) {
            std::cerr << "TTF_RenderText_Solid (outline) failed: " << TTF_GetError() << std::endl;
            return; // Handle error appropriately
        }

        // Create texture from surface
        textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (!textTexture) {
            std::cerr << "SDL_CreateTextureFromSurface (outline) failed: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(textSurface);
            return;
        }

        // Get the size of the text texture
        textRect = {rect.x- 1, rect.y+ 1, rect.w, rect.h}; // slight offset
        SDL_RenderCopy(gRenderer, textTexture, NULL, &textRect);
        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);


        // --- Render the fill (white) ---
        textSurface = TTF_RenderText_Solid(font, value.c_str(), inline_color);
        if (!textSurface) {
            std::cerr << "TTF_RenderText_Solid (fill) failed: " << TTF_GetError() << std::endl;
            return; // Handle error appropriately
        }

        textTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
        if (!textTexture) {
            std::cerr << "SDL_CreateTextureFromSurface (fill) failed: " << SDL_GetError() << std::endl;
            SDL_FreeSurface(textSurface);
            return;
        }

        textRect = {rect.x, rect.y, rect.w, rect.h};
        SDL_RenderCopy(gRenderer, textTexture, NULL, &textRect);

        SDL_DestroyTexture(textTexture);
        SDL_FreeSurface(textSurface);
    }
};

#endif // _BUTTON__H
