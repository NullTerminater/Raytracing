#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>

#define WIDTH 900
#define HEIGHT 600
#define COLOR_WHITE 0xffffffff

int main (void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Raytracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    SDL_Rect rect = (SDL_Rect) {200, 200, 200, 200};
    SDL_FillRect(surface, &rect, COLOR_WHITE);
    SDL_UpdateWindowSurface(window);
    int quit = 0;
    SDL_Event e;
    while (!quit) {
        while(SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }
    }
    SDL_DestroyWindow(window);



    return 0;
}
