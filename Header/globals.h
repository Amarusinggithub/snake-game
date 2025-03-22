#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <Game.h>


enum class  Direction{UP,DOWN,RIGHT,LEFT};
bool done = false;

SDL_Window *window;                   
SDL_Renderer* renderer;
const int WINDOW_HEIGHT = 700;
const int WINDOW_WIDTH = 800;

SDL_Event event;
const char * SDL_GetRenderDriver(int index);
