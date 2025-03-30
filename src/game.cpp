#include "game.h"

void Game::init(){
    const char * SDL_GetRenderDriver(int index);

SDL_Init(SDL_INIT_VIDEO); 

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

    lastTime=SDL_GetTicks();
    snake = new Snake();
    food = new Food();

snake->grow();
snake->grow();
food->spawnFood(snake, WINDOW_WIDTH, WINDOW_HEIGHT);
}

void Game::draw(){
SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
SDL_RenderClear( renderer );
snake->render(renderer,WINDOW_WIDTH,WINDOW_HEIGHT); 
food->render(renderer);
SDL_RenderPresent(renderer);
}

void Game:: restart(){
    score=0;
for (int i=snake->body.size()-1;i>0;i--){
    snake->body.erase(snake->body.begin() + i);
}
snake->grow();
snake->grow();
}

void Game:: changeDirectionOfSnake (SDL_Event event){

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
}

void Game:: moveSnake(){
Uint32 currentIme=SDL_GetTicks();
    if(currentIme-lastTime>=moveInterval){
        lastTime=currentIme;
        snake->move();
        switch (currentDirection)
        {
        case Direction::UP:
        snake->body[0]->y -= 20;
        break;
        case Direction::DOWN:
        snake->body[0]->y += 20;
        break;
        case Direction::RIGHT:
        snake->body[0]->x += 20;
        break;
        case Direction::LEFT:
        snake->body[0]->x-=20;
        break;
        
        default:
            break;
        }
        check_collision();
    }
    draw();
    SDL_Delay(16);
    
    }


void Game:: check_collision(){
    if(snake->didEatFood(*food,*snake)){
    std::cout<<"Score increment";
        score++;
        food->spawnFood(snake,WINDOW_WIDTH,WINDOW_HEIGHT);
    }

    if(snake->selfCollisionCheck()){
        std::cout<<"Game will restart";
        restart();
    }

    snake->outOfBoundCheck( WINDOW_WIDTH, WINDOW_HEIGHT);        
}

void Game:: close(){
SDL_DestroyRenderer(renderer);
// Close and destroy the window
SDL_DestroyWindow(window);
// Clean up
SDL_Quit(); 
}



