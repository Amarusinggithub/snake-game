#include "game.h"

using namespace std;

void runGame ();
SDL_Event e;
bool quit = false;
auto game=  Game();


void runGame (){
while (!quit) {
        while (SDL_PollEvent(&e) !=0) {
            if (e.type == SDL_QUIT)quit = true;
            if(e.type== SDL_KEYDOWN ){
                game.changeDirectionOfSnake(e);
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






