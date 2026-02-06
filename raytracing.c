#include <stdio.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <stdint.h>
#include <inttypes.h>

#define WIDTH 900
#define HEIGHT 600
#define MAX_FPS 60
#define SCREEN_TICKS_PER_FRAME 1000
#define COLOR_WHITE 0xffffffff
#define COLOR_BLACK 0x00000000
#define NUM_RAYS 100
#define RADIANS 180 / M_PI


typedef struct
{
    double x;
    double y;
    double r;
} Circle;

void draw_circle(Circle light_source, SDL_Surface *surface, int OFFSET_X, int OFFSET_Y)
{
    double dist_squared;
    for (int i = 0; i < light_source.r * 2; i++)
    {
        for (int j = 0; j < light_source.r * 2; j++)
        {
            dist_squared = pow(i - light_source.r, 2) + pow(j - light_source.r, 2);
            if (dist_squared <= pow(light_source.r, 2))
            {
                SDL_Rect little_rect = (SDL_Rect){i + OFFSET_X, j + OFFSET_Y, 1, 1};
                SDL_FillRect(surface, &little_rect, COLOR_WHITE);
            }
        }
    }
}

void draw_ray(SDL_Surface *surface, int x, int y, int pixel_width){
    // while not out of bounds 
    while((x > 0 && x < WIDTH) || (y > 0 && y < HEIGHT)) {
        SDL_Rect wave_rect = (SDL_Rect){pow(cos(x), 2)*x, pow(sin(x), 2)*x, pixel_width, pixel_width};
        printf("cos(%d): %f\tsin(%d): %f\n", x, pow(cos(x),2), y, pow(sin(y),2));
        SDL_FillRect(surface, &wave_rect, COLOR_WHITE ); 
        x++;
        y++; 
    }

}
int main(void)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Raytracing", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Surface *surface = SDL_GetWindowSurface(window);
    // SDL_Rect rect = (SDL_Rect) {0, 0, 200, 200};
    // SDL_FillRect(surface, &rect, COLOR_WHITE);
    
    // draws circle
    Circle light_source;
    light_source.r = 50;
    draw_circle(light_source, surface, 200, 200);

    SDL_UpdateWindowSurface(window);

    SDL_Rect full_rect = (SDL_Rect){0, 0, WIDTH, HEIGHT};
    SDL_Rect wave_rect = (SDL_Rect){10, 10, 1, 1};
    SDL_Event e;
    int is_running = 1;
    while (is_running)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            int x, y = 0;
            SDL_GetMouseState(&x, &y);
            if (e.type == SDL_MOUSEMOTION )
            {
                SDL_FillRect(surface, &full_rect, COLOR_BLACK);
                draw_circle(light_source, surface, x, y);
                SDL_FillRect(surface, &wave_rect, COLOR_WHITE);
                draw_ray(surface, 100, 100, 1);
                // draw_circle(light_source, surface, x - light_source.r, y - light_source.r);
                SDL_UpdateWindowSurface(window);
            }
            else if (e.type == SDL_QUIT)
            {
                is_running = 0;
            }
        }
    }
    SDL_DestroyWindow(window);

    return 0;
}

