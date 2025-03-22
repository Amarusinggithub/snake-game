
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <Snake.h>
#include <Game.h>
#include <Food.h>
#include <globals.h>




void Game::draw(){

}


void Game:: collisionLogic( ){
    if((food.y>=snake.body[0].y&&(food.y+food.food.h)<snake.body[0].y+snake.body[0].h)||((food.x>=snake.body[0].x&&food.food.x<snake.body[0].x+snake.body[0].w))){

    }
}



void Game:: start (){
    Uint32 lastTime=SDL_GetTicks();
    Uint32 moveInterval=150;
    while (!done) 
    {
        while (SDL_PollEvent(&event) !=0) {
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
            } else if (event.type == SDL_EVENT_QUIT)
                    {
                    done = true;
                    }
        }
    Uint32 currentIme=SDL_GetTicks();
    if(currentIme-lastTime>=moveInterval){
        lastTime=currentIme;

        switch (currentDirection)
        {
        case Direction::UP:
        snake.y -= 20;
        break;
        case Direction::DOWN:
        snake.y += 20;
        break;
        case Direction::RIGHT:
        snake.x += 20;
        break;
        case Direction::LEFT:
        snake.x-=20;
        break;
        
        default:
            break;
        }
        didSnakeEatFood();
    }
    draw();
    SDL_Delay(16);
    }
}



