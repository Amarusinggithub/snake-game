#include "game.h"

using namespace std;

void Snake:: render(SDL_Renderer *renderer,int WINDOW_WIDTH,int WINDOW_HEiGHT){
    for(int i=0;i<body.size();i++){
    SDL_SetRenderDrawColor(renderer,0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, body[i]);
        }
    }

void Snake:: grow(){
SDL_FRect* part= new SDL_FRect();
    part->h = 30;
    part->w = 30;

if(body.size()>=2){
    SDL_FRect* tail=body.back();
    SDL_FRect* prev=body[body.size()-2];

    float dx=tail->x-prev->x;
    float dy=tail->y-prev->y;

        part->x=tail->x+dx;
        part->y=tail->y+dy;
}
else if (!body.empty()) {
        // If there's only one segment, choose a default direction (e.g., to the left)
        SDL_FRect* tail = body.back();
        part->x = tail->x - 30;
        part->y = tail->y;
    } else {

    part->x=30;
    part->y=30;
}
    body.push_back(part);
}

void Snake::move(){
        for(int i=body.size()-1;i>0;i--){
            body[i]->x=body[i-1]->x;
            body[i]->y=body[i-1]->y;
            body[i]->w=body[i-1]->w;
            body[i]->h=body[i-1]->h;
        }
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


bool Snake::selfCollisionCheck(){
    if (body.size()<=3)return false;

    for(int i=2;i<body.size();i++){
    if(check_collision(body[i],body[0])){
    return true;   
    }
}
return false;
}

bool Snake::didEatFood(Food food,Snake snake){
if (check_collision(snake.head,food.food)){
    grow();
    return true;

}
    return false;
    }


bool Snake::check_collision( SDL_FRect * A, SDL_FRect* B ){
    //The sides of the rectangles
    float leftA, leftB;
    float rightA, rightB;
    float topA, topB;
    float bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A->x;
    rightA = A->x + A->w;
    topA = A->y;
    bottomA = A->y + A->h;

    //Calculate the sides of rect B
    leftB = B->x;
    rightB = B->x + B->w;
    topB = B->y;
    bottomB = B->y + B->h;

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
