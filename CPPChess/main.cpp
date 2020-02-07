#include <iostream>
#include "GameBoard.h"

using namespace std;

int main()
{

    GameBoard::initBoard();
    while(GameBoard::runGame());  //Game Loop
    return 0;
}
