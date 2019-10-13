#include <iostream>

#include "Game/Game/GameManager.h"

int main()
{
    
    SnakeGame::GameManager gm;

    gm.InitGame( { 100, 50 }, 
                 { 49, 45 }, 
                 1000, 
                 100 );
    gm.StartGame();
    gm.WaitExit();

    return 0;
}