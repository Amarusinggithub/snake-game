#ifndef SNAKE_H
#define SNAKE_H

#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;

class Snake{
    public: 
    SDL_FRect* head;
    SDL_FRect* bodyPart;
    int HEIGHT,WIDTH;
    vector <SDL_FRect*>body={head};

    void render(SDL_Renderer *renderer,int WINDOW_WIDTH,int WINDOW_HEiGHT);
    void grow();
    void move();
    bool didEatFood();
    bool selfCollisionCheck();
    void outOfBoundCheck(int WINDOW_WIDTH,int WINDOW_HEiGHT);
    



    private:
    bool check_collision( SDL_FRect A, SDL_FRect B );


};


#endif