#include <SDL.h>
#include "Vector.hpp"
#include "Solids.hpp"

#include <iostream>

const int W = 600;
const int H = 600;
const int MAX_DIST = 20000;


int main() {
    Color white(255,255,255);
    Sphere ball(Vec3(W/2, H/2, 200), 50, white);
    Plane floor(Vec3(W/2, H, 200), Vec3(0,0.0001,1), white);


    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(W, H, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {

            //Ray ray = cam.getRay(x, y);
            Ray ray(Vec3(x,y,0), Vec3(0,0,1));
            double t = 20000;
            /*
            std::cout << ray.direction.x << ", "
                      << ray.direction.y << ", "
                      << ray.direction.z << "\n";
            */

            bool hit = ball.hit(ray, &t);
            if (hit && t < MAX_DIST) {
                SDL_SetRenderDrawColor(renderer, ball.color.r, ball.color.g, ball.color.b, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
        }
    }


    SDL_RenderPresent(renderer);
    while (1) {
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT)
            break;
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return EXIT_SUCCESS;
}
