
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <Snake.h>
#include <Food.h>

 void Food:: render(SDL_Renderer *renderer){
   food->h = Height;
   food->w = Width;
   food->x =x;
   food->y =y;

   SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
   SDL_RenderFillRect(renderer, food);
   
   }

void Food::spawnFood(Snake *snake,int WINDOW_WIDTH,int WINDOW_HEIGHT){
        int randomX= rand() % WINDOW_WIDTH;
        int randomY = rand() % WINDOW_HEIGHT;

        if(food->x!=randomX&&food->y!=randomY){
            for(int i=0;i<snake->body.size();i++){
                if(snake->body[i]->x!=randomX&& snake->body[i]->y!=randomY){
                    food->x=randomX;
                    food->y=randomY;
                }else{
                    spawnFood(snake,WINDOW_WIDTH,WINDOW_HEIGHT);
                }
            }
        }
    }



   
