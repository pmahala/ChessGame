#include <iostream>
#include "GameBoard.h"

using namespace std;

int main()
{

    GameBoard::initBoard();
    //GameBoard::dispBoard();

    while(GameBoard::runGame())
    {

    }


    return 0;
}
