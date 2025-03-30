#ifndef SNAKE_H
#define SNAKE_H

using namespace std;


class Food;

class Snake{
    public: 
    Snake(){
    head= new SDL_FRect();
    head->x = 30;
    head->y = 30;
    head->w = 30;
    head->h = 30;   
    body.push_back(head);
    }

    SDL_FRect* head;
    int HEIGHT,WIDTH;
    vector <SDL_FRect*>body;

    void render(SDL_Renderer *renderer,int WINDOW_WIDTH,int WINDOW_HEiGHT);
    void grow();
    void move();
    bool didEatFood(Food food,Snake snake);
    bool selfCollisionCheck();
    void outOfBoundCheck(int WINDOW_WIDTH,int WINDOW_HEiGHT);
    
    private:
    bool check_collision( SDL_FRect* A, SDL_FRect* B );
};
#endif