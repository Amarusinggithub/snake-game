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

    Snake snake;
    Food food;
    int points;
    public:
    Direction currentDirection=Direction::DOWN;



    void update();
    void draw();
    void collisionLogic();
    void start();
    void restart();
    void spawnFood();


};


#endif


