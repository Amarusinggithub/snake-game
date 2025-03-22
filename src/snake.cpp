
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "snake.h"

using namespace std;



void Snake:: render(SDL_Renderer *renderer){
    for(int i=0;i<body.size();i++){
    body[i].w=30;
    body[i].h=250;

    SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &body[i]);
        }

    }




void Snake:: grow(){
    SDL_FRect bodyPart;
    body.push_back(bodyPart);
    }


  


