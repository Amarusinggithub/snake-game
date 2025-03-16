
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>



SDL_Window *window;                   
SDL_Renderer* renderer;
const int WINDOW_HEIGHT = 700;
const int WINDOW_WIDTH = 800;
SDL_FRect  snake;
SDL_FRect food;
SDL_Event event;
const char * SDL_GetRenderDriver(int index);



void init(){
    
    SDL_Init(SDL_INIT_VIDEO); 

    window = SDL_CreateWindow(
        "Snake Game",                 
        WINDOW_WIDTH,                              
        WINDOW_HEIGHT,                           
        SDL_WINDOW_OPENGL                 
    );
    renderer = SDL_CreateRenderer(window,NULL);  
    // Check that the window was successfully created
    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    }


    snake.x=500/4;
    snake.y=500/4;
    snake.w=60;
    snake.h=250;

    food.h = 20;
    food.w = 20;
    food.x = 450;
    food.y = 500;
};


void draw(){

SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
SDL_RenderClear(renderer);

SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
SDL_RenderFillRect(renderer, &food);

SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
SDL_RenderFillRect( renderer, &snake );

SDL_RenderPresent(renderer);


};


void gameLogic (){
        while (SDL_PollEvent(&event) !=0) {
            if(event.type== SDL_EVENT_KEY_DOWN ){
                switch (event.key.key){
                    case SDLK_UP:
                    snake.y=snake.y+20;
                    break;
                    case SDLK_DOWN:
                    snake.y = snake.y - 20;
                    break;
                }
            }
        }

    
}

int main(int argc, char* argv[]) {
    bool done = false;


    init();
    gameLogic();
    draw();
    SDL_Delay(16);

    while (!done) 
    {
        SDL_PollEvent(&event);
        if (event.type == SDL_EVENT_QUIT)
        {
            done = true;
        }
    }



SDL_DestroyRenderer(renderer);
// Close and destroy the window
SDL_DestroyWindow(window);

// Clean up
SDL_Quit();

    return 0;
}