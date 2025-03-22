
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <Snake.h>
#include <Game.h>
#include <Food.h>
#include <globals.h>


inline void initializeSdl(){
    
    SDL_Init(SDL_INIT_EVENTS); 

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

};
