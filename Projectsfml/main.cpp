#include "Game.h"
#include <iostream>
#include <time.h>


int main()
{
    //init random
    srand(static_cast<unsigned>(time(NULL)));

    //init game engine
    Game game;

    game.run();
    

    return 0;
}
