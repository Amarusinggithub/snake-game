
#include <iostream>
#include <SDL3/SDL.h>
#include <fstream>
#include <cstdlib>
#include <vector>

using namespace std;


int time();
void close();
void moveSnakeBody();
bool check_collision( SDL_FRect A, SDL_FRect B );

Uint32 lastTime;


SDL_Window *window;                   
SDL_Renderer* renderer;
const int WINDOW_HEIGHT = 700;
const int WINDOW_WIDTH = 800;
SDL_FRect  head;
SDL_FRect food;
SDL_FRect bodyPart;
SDL_FRect anotherBodyPart;


SDL_Event event;
const char * SDL_GetRenderDriver(int index);
    bool done = false;
enum class Direction{UP,DOWN,RIGHT,LEFT};
Direction currentDirection=Direction::DOWN;
vector <SDL_FRect*> body={&head,&bodyPart,&anotherBodyPart};



void init(){
    
    SDL_Init(SDL_INIT_EVENTS); 

    window = SDL_CreateWindow(
        "Snake Game",                 
        WINDOW_WIDTH,                              
        WINDOW_HEIGHT,                           
        SDL_WINDOW_OPENGL               
    );
    renderer = SDL_CreateRenderer(window,NULL);  
    // Check that the window was successfully created
    if (window == NULL) {
        SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
    }


    body[0]->x=125;
    body[0]->y=125;
    body[0]->w=30;
    body[0]->h=30;

    body[1]->w=30;
    body[1]->h=30;

    body[2]->w=30;
    body[2]->h=30;

    food.h = 20;
    food.w = 30;
    food.x = 450;
    food.y = 500;

    lastTime=SDL_GetTicks();
};


void draw(){

SDL_SetRenderDrawColor(renderer,0, 0, 0, 255);
SDL_RenderClear(renderer);

//for(int i =0;i<body.size();i++){
//SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
//SDL_RenderFillRect( renderer, &body[i] );
//}

SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
SDL_RenderFillRect( renderer, &head );

SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
SDL_RenderFillRect( renderer, &bodyPart );

SDL_SetRenderDrawColor( renderer, 255, 255, 255, 255);
SDL_RenderFillRect( renderer, &anotherBodyPart );



SDL_SetRenderDrawColor(renderer,255, 0, 0, 255);
SDL_RenderFillRect(renderer, &food);

SDL_RenderPresent(renderer);
};


void didSnakeEatFood(){
    if(check_collision(head,food)){

        cout<< "snake ate food";
        SDL_FRect part;
        part.h=30;
        part.w=30;
        body.push_back(&part);
        int randomX= rand() % WINDOW_WIDTH;
        int randomY = rand() % WINDOW_HEIGHT;

        if(food.x!=randomX&&food.y!=randomY){
            food.x=randomX;
            food.y=randomY;
        }

    }
}

void runGame (){
    Uint32 moveInterval=150;
    while (!done) 
    {
        while (SDL_PollEvent(&event) !=0) {
            if(event.type== SDL_EVENT_KEY_DOWN ){
                switch (event.key.key){
                    case SDLK_UP:
                    if(currentDirection!=Direction::DOWN)currentDirection=Direction::UP;
                    break;
                    case SDLK_DOWN:
                    if(currentDirection!=Direction::UP)currentDirection=Direction::DOWN;

                    break;
                    case SDLK_RIGHT:
                    if(currentDirection!=Direction::LEFT)currentDirection=Direction::RIGHT;

                    break;
                    case SDLK_LEFT:
                    if(currentDirection!=Direction::RIGHT)currentDirection=Direction::LEFT;

                    break;
                }
            } else if (event.type == SDL_EVENT_QUIT)
                    {
                    done = true;
                    }
        }
    Uint32 currentIme=SDL_GetTicks();
    if(currentIme-lastTime>=moveInterval){
        lastTime=currentIme;

        switch (currentDirection)
        {
        case Direction::UP:
        body[0]->y -= 20;
        moveSnakeBody();
        break;
        case Direction::DOWN:
        body[0]->y +=20;
        moveSnakeBody();

        break;
        case Direction::RIGHT:
        body[0]->x += 20;
                moveSnakeBody();

        break;
        case Direction::LEFT:
        body[0]->x-=20;
                moveSnakeBody();

        break;
        
        default:
            break;
        }
        didSnakeEatFood();
    }
    draw();
    SDL_Delay(16);
    }
}

int main(int argc, char* argv[]) {


    init();
    runGame();
    close();   
    
    
    return 0;
}



void close(){
   SDL_DestroyRenderer(renderer);
// Close and destroy the window
SDL_DestroyWindow(window);

// Clean up
SDL_Quit(); 
}

void moveSnakeBody(){
    for (int i=body.size()-1;i>0;i--){
            body[i]->x=body[i-1]->x;
body[i]->y=body[i-1]->y;
body[i]->w=body[i-1]->w;
body[i]->h=body[i-1]->h;
        


    }
}

bool check_collision( SDL_FRect A, SDL_FRect B )
{
    //The sides of the rectangles
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    //Calculate the sides of rect A
    leftA = A.x;
    rightA = A.x + A.w;
    topA = A.y;
    bottomA = A.y + A.h;

    //Calculate the sides of rect B
    leftB = B.x;
    rightB = B.x + B.w;
    topB = B.y;
    bottomB = B.y + B.h;

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