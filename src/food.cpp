#include "game.h"

 void Food:: render(SDL_Renderer *renderer){
    SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
    SDL_RenderFillRect(renderer, food);
}

void Food::spawnFood(Snake *snake,int WINDOW_WIDTH,int WINDOW_HEIGHT){
    food=new SDL_FRect();
    food->h = Height;
    food->w = Width;
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
