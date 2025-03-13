
#include <iostream>
#include <SDL3/SDL.h>

int main(int argc, char* argv[]) {

    SDL_Window *window;                    // Declare a pointer
    SDL_Renderer* renderer;
    bool done = false;

    SDL_Init(SDL_INIT_VIDEO);              // Initialize SDL3

    // Create an application window with the following settings:
    window = SDL_CreateWindow(
        "Snake Game",                  // window title
        500,                               // width, in pixels
        500,                               // height, in pixels
        SDL_WINDOW_OPENGL                  // flags - see below
    );

        renderer = SDL_CreateRenderer(window,NULL);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);


    SDL_FRect fillRect = { 500 / 4, 500 / 4, 500 / 2, 500 / 2 };

  //   float x;
   // float y;
   // float w;
   // float h;
    SDL_SetRenderDrawColor( renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect( renderer, &fillRect );

    
    





    SDL_RenderPresent(renderer);

    // Check that the window was successfully created
    if (window == NULL) {
        // In the case that the window could not be made...
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
        return 1;
    }

    while (!done) {
        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) {
                done = true;
            }
        }

        // Do game logic, present a frame, etc.
    }
      
    
    
    SDL_DestroyRenderer(renderer);


    // Close and destroy the window
    SDL_DestroyWindow(window);

    SDL_Delay(5000);

    // Clean up
    SDL_Quit();
    return 0;
}