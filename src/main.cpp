#include <SDL.h>
#include "Vector.hpp"

const int W = 500;
const int H = 500;


int main() {
    Color white(255,255,255);
    Sphere ball(Vec3(W/2, H/2, 50), 40, white);

    SDL_Event event;
    SDL_Renderer *renderer;
    SDL_Window *window;

    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(W, H, 0, &window, &renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {

            Ray ray(Vec3(x,y,0), Vec3(0,0,1));
            double t = 50000;

            if (ball.intersect(ray, t)) {
                SDL_SetRenderDrawColor(renderer, ball.color.x, ball.color.y, ball.color.z, 255);
                SDL_RenderDrawPoint(renderer, x, y);
            }
            /*
            if (x == y) {
                SDL_RenderDrawPoint(renderer, x, y);
            }
            */
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
