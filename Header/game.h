#ifndef GAME_H
#define GAME_H


#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <Snake.h>
#include <Food.h>

class Game{
    private:
    enum class  Direction{UP,DOWN,RIGHT,LEFT};
    const int WINDOW_HEIGHT = 700;
    const int WINDOW_WIDTH = 800;

    SDL_Window *window;  
    SDL_Renderer* renderer;                 

    Snake* snake;
    Food* food;
    int points;
    public:
    Direction currentDirection=Direction::DOWN;

    void close();
    void init();
    void update();
    void restart();
    void draw();
    void start();


};


#endif


