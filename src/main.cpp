#include "game.h"

using namespace std;

void runGame ();
SDL_Event event;
bool done = false;
Game game=  Game();


void runGame (){
while (!done) {
        while (SDL_PollEvent(&event) !=0) {
            if (event.type == SDL_EVENT_QUIT){
                done = true;
                }
            if(event.type== SDL_EVENT_KEY_DOWN ){
                game.changeDirectionOfSnake(event);
            } 
        }
    game.moveSnake();
    }
}

int main(int argc, char* argv[]) {
    runGame();
    game.close();   
    return 0;
}






