
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <vector>
#include "snake.h"

using namespace std;



void Snake:: render(SDL_Renderer *renderer,int WINDOW_WIDTH,int WINDOW_HEiGHT){
    int headRandomX= rand() % WINDOW_WIDTH;
    int headRandomY = rand() % WINDOW_HEiGHT;

    body[0]->x=30;
    body[0]->y=30;

    for(int i=0;i<body.size();i++){
    body[i]->w=WIDTH;
    body[i]->h=HEIGHT;

    SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
    SDL_RenderFillRect(renderer, body[i]);
        }
    }

void Snake:: grow(){
SDL_FRect* part= new SDL_FRect();
        part->h=30;
        part->w=30;
        body.push_back(part);

    }


void Snake::move(){
        for(int i=body.size();i>0;i--){
            body[i]->x=body[i-1]->x;
            body[i]->y=body[i-1]->y;
            body[i]->w=body[i-1]->w;
            body[i]->h=body[i-1]->h;
        }
    }


bool Snake::selfCollisionCheck(){
    for(int i=body.size()-1;i>=4;i--){
    if(check_collision(*body[i],*body[0])){
    return true;   
    }
}
return false;
}


void Snake::outOfBoundCheck(int WINDOW_WIDTH,int WINDOW_HEiGHT){
        for (int i=0; i<body.size();i++){
        if(body[i]->x>WINDOW_WIDTH){
            body[i]->x=0;
        }

            if(body[i]->x<0){
            body[i]->x=WINDOW_WIDTH;
        }

            if(body[i]->y>WINDOW_HEiGHT){
            body[i]->y=0;
        }

            if(body[i]->y<0){
            body[i]->y=WINDOW_HEiGHT;
        }
    }
    }


bool Snake::check_collision( SDL_FRect A, SDL_FRect B ){
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

     //If any of the sides from A are outside of B
    if( bottomA <= topB )
    {
        return false;
    }

    if( topA >= bottomB )
    {
        return false;
    }

    if( rightA <= leftB )
    {
        return false;
    }

    if( leftA >= rightB )
    {
        return false;
    }

    //If none of the sides from A are outside B
    return true;
}
