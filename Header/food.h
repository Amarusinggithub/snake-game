#ifndef FOOD_H
#define FOOD_H

class Food{
    private:
    int Height=20;
    int Width=30;
    public:
    int y;
    int x;
    SDL_FRect food;

     void  render(SDL_Renderer *renderer);

};

#endif