#include "GameBoard.h"
#include<iostream>


std::vector<std::vector<char>> GameBoard::chessBoard {{},{},{},{},{},{},{},{}};

void GameBoard::initBoard()
{
    std::vector<char> blankPos {'.','.','.','.','.','.','.','.'};
    for(int i{0}; i < 8; i++)
    {
        chessBoard.push_back(blankPos);
    }

}



void GameBoard::dispBoard()
{
    std::cout << "\t" << "0";
    std::cout << "\t" << "1";
    std::cout << "\t" << "2";
    std::cout << "\t" << "3";
    std::cout << "\t" << "4";
    std::cout << "\t" << "5";
    std::cout << "\t" << "6";
    std::cout << "\t" << "7\n";
    for(int i{0}; i < 8; i++)
    {
        std::cout << i << "\t";
        for(int j{0}; j < 8; j++)
        {
            std::cout << chessBoard.at(i).at(j) << "\t";
        }
        std::cout << std::endl << std::endl << std::endl;
    }
}
