#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdint.h>
#include <inttypes.h>

#define WIDTH 900
#define HEIGHT 600
#define COLOR_WHITE 0xffffffff

typedef struct {
    double x;
    double y;
    double r;
} Circle;

int main (void) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Raytracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    // SDL_Rect rect = (SDL_Rect) {0, 0, 200, 200};
    // SDL_FillRect(surface, &rect, COLOR_WHITE);
    int quit = 0;


    Circle light_source;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            SDL_Rect little_rect = (SDL_Rect) {i, j, 1, 1};
            SDL_FillRect(surface, &little_rect, COLOR_WHITE);
        }
    }

    SDL_UpdateWindowSurface(window);

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
