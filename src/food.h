#ifndef FOOD_H
#define FOOD_H



class Snake;

class Food{
    private:
    int Height=30;
    int Width=30;
    public:

    Food(){

    }
    int y;
    int x;
    SDL_FRect* food;
    

    void  render(SDL_Renderer *renderer);
    void spawnFood(Snake *snake,int WINDOW_WIDTH,int WINDOW_HEIGHT);


};

#endif