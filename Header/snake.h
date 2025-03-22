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
    SDL_FRect head;
    SDL_FRect bodyPart;
    vector <SDL_FRect>body={head};

    void render(SDL_Renderer* renderer);
    void grow();
    void move();
    



    private:

};


#endif