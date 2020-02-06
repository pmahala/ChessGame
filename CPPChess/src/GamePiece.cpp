#include "GamePiece.h"

GamePiece::GamePiece(int rowPos,int colPos,bool isWhite, std::string symbol):
    rowPos{rowPos}, colPos{colPos}, isWhite{isWhite},symbol{symbol}
{
    //ctor
}

bool GamePiece::MovePiece(int rowPos,int colPos)
{
    if(rowPos >= 0 && rowPos <= 7 && colPos >= 0 && colPos <= 7)
    {
        this->rowPos = rowPos;
        this->colPos = colPos;
        return true;

    }
    return false;
}
int GamePiece::getRowPos()
{
    return rowPos;
}
int GamePiece::getColPos()
{
    return colPos;
}
std::string GamePiece::getSymbol() const
{
    return symbol;

}

bool GamePiece::ofWhitePlayer() const
{
    return isWhite;
}
