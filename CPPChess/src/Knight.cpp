#include "Knight.h"
#include"GameBoard.h"
#include<math.h>

Knight::Knight(int rowPos,int colPos,bool isWhite,std::string symbol): GamePiece(rowPos,colPos,isWhite,symbol){}

bool Knight::MovePiece(int rowPos,int colPos)
{
    if (abs(this->rowPos - rowPos) == 1 && abs(this->colPos - colPos) == 2 || abs(this->rowPos - rowPos) == 2 && abs(this->colPos - colPos) == 1)
    {
        if(isWhite)
        {

            for(size_t i{0}; i < GameBoard::getBlackPieces().size();i++) //capture enemy piece at destination
            {
                if(GameBoard::getBlackPieces().at(i) -> getRowPos() == rowPos && GameBoard::getBlackPieces().at(i) -> getColPos() == colPos)
                {
                    GameBoard::getBlackPieces().erase(GameBoard::getBlackPieces().begin() + i); //removing the desired black piece
                    return GamePiece::MovePiece(rowPos,colPos);
                }

            }
            for(size_t i{0}; i < GameBoard::getWhitePieces().size();i++) //cancel move if friendly exist at destination
            {
                if(GameBoard::getWhitePieces().at(i) -> getRowPos() == rowPos && GameBoard::getWhitePieces().at(i) -> getColPos() == colPos)
                {
                    return false;
                }

            }
            return GamePiece::MovePiece(rowPos,colPos);
        }
        else
        {
            for(size_t i{0}; i < GameBoard::getWhitePieces().size();i++) //capture enemy piece at destination
            {
                if(GameBoard::getWhitePieces().at(i) -> getRowPos() == rowPos && GameBoard::getWhitePieces().at(i) -> getColPos() == colPos)
                {
                    GameBoard::getWhitePieces().erase(GameBoard::getWhitePieces().begin() + i); //removing the desired black piece
                    return GamePiece::MovePiece(rowPos,colPos);
                }

            }
            for(size_t i{0}; i < GameBoard::getBlackPieces().size();i++) //cancel move if friendly exist at destination
            {
                if(GameBoard::getBlackPieces().at(i) -> getRowPos() == rowPos && GameBoard::getBlackPieces().at(i) -> getColPos() == colPos)
                {
                    return false;
                }

            }
            return GamePiece::MovePiece(rowPos,colPos);
        }
    }
    return false;
}
