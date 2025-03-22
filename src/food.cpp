
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <Snake.h>
#include <Food.h>

 void Food:: render(SDL_Renderer *renderer){
   food.h = Height;
   food.w = Width;
   food.x =x;
   food.y =y;

   SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
   SDL_RenderFillRect(renderer, &food);
   
   }

   
