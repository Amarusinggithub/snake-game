#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <SDL2/SDL.h>
#include <fstream>
#include <vector>
#include <cstdlib>
#include "snake.h"
#include "food.h"

class Game{
    private:
    enum class  Direction{UP,DOWN,RIGHT,LEFT};
    const int WINDOW_HEIGHT = 700;
    const int WINDOW_WIDTH = 800;
    Uint32 lastTime;
    const Uint32 moveInterval=150;
    int score=0;

    SDL_Window *window;  
    SDL_Renderer* renderer;                 

    public:
    Game(){
        init();
    }

    Snake* snake;
    Food* food;
    Direction currentDirection=Direction::DOWN;

    void close() const;
    void init();
    void update();
    void restart();
    void draw() const;
    void start();
    void changeDirectionOfSnake(const SDL_Event &event);
    void moveSnake();
    void check_collision();
};
#endif


