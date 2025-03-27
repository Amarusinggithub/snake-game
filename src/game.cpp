
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <Snake.h>
#include <Game.h>
#include <Food.h>
#include <globals.h>
#include <SDL3/SDL.h>



void Game::init(){
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

    
    int headRandomX= rand() % WINDOW_WIDTH;
    int headRandomY = rand() % WINDOW_HEIGHT;

snake->grow();
snake->grow();
food->spawnFood(snake, WINDOW_WIDTH, WINDOW_HEIGHT);

}


void Game::draw(){
snake->render(renderer,WINDOW_WIDTH,WINDOW_HEIGHT); 
food->render(renderer);
SDL_RenderPresent(renderer);
}




void Game:: restart(){
for (int i=snake->body.size()-1;i>0;i--){
    snake->body.erase(snake->body.begin() + i);
}
snake->grow();
snake->grow();
}


void Game:: start (){
    Uint32 lastTime=SDL_GetTicks();
    Uint32 moveInterval=150;
while (!done) {
    while (SDL_PollEvent(&event) !=0) {
        if (event.type == SDL_EVENT_QUIT){
            done = true;
            }
            if(event.type== SDL_EVENT_KEY_DOWN ){
                switch (event.key.key){
                    case SDLK_UP:
                    if(currentDirection!=Direction::DOWN)currentDirection=Direction::UP;
                    break;
                    case SDLK_DOWN:
                    if(currentDirection!=Direction::UP)currentDirection=Direction::DOWN;

                    break;
                    case SDLK_RIGHT:
                    if(currentDirection!=Direction::LEFT)currentDirection=Direction::RIGHT;

                    break;
                    case SDLK_LEFT:
                    if(currentDirection!=Direction::RIGHT)currentDirection=Direction::LEFT;
                    break;
                }
            }  
        }
    Uint32 currentIme=SDL_GetTicks();
    if(currentIme-lastTime>=moveInterval){
        lastTime=currentIme;

        switch (currentDirection)
        {
        case Direction::UP:
        snake->body[0]->y -= 20;
        break;
        case Direction::DOWN:
        snake->body[0]->y += 20;
        break;
        case Direction::RIGHT:
        snake->body[0]->x += 20;
        break;
        case Direction::LEFT:
        snake->body[0]->x-=20;
        break;
        
        default:
            break;
        }
        snake->didEatFood();
    }
    draw();
    SDL_Delay(16);
    }
}

void Game:: close(){
SDL_DestroyRenderer(renderer);
// Close and destroy the window
SDL_DestroyWindow(window);
// Clean up
SDL_Quit(); 
}



