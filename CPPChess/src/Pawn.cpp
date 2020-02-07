#include "Pawn.h"
#include "GameBoard.h"



Pawn::Pawn(int rowPos,int colPos,bool isWhite,std::string symbol):GamePiece(rowPos,colPos,isWhite,symbol){}

bool Pawn::MovePiece(int rowPos,int colPos)
{
    if(isWhite)
    {
        if(this->colPos == colPos && this->rowPos == rowPos + 1)  //normal straight movement
        {
            for(size_t i{0}; i < GameBoard::getBlackPieces().size();i++)
            {
                if(GameBoard::getBlackPieces().at(i) -> getRowPos() == rowPos && GameBoard::getBlackPieces().at(i) -> getColPos() == colPos)
                {

                    return false;
                }

            }
            for(size_t i{0}; i < GameBoard::getWhitePieces().size();i++)
            {
                if(GameBoard::getWhitePieces().at(i) -> getRowPos() == rowPos && GameBoard::getWhitePieces().at(i) -> getColPos() == colPos)
                {

                    return false;
                }

            }
            return GamePiece::MovePiece(rowPos,colPos);
        }

        else if((this->colPos == colPos + 1 || this->colPos == colPos - 1) && this->rowPos == rowPos + 1) //capture move
        {
            for(size_t i{0}; i < GameBoard::getBlackPieces().size();i++)
            {
                if(GameBoard::getBlackPieces().at(i) -> getRowPos() == rowPos && GameBoard::getBlackPieces().at(i) -> getColPos() == colPos)
                {
                    GameBoard::getBlackPieces().erase(GameBoard::getBlackPieces().begin() + i); //removing the desired black piece
                    return GamePiece::MovePiece(rowPos,colPos);
                }

            }
        }
    }
    else
    {
        if(this->colPos == colPos && this->rowPos == rowPos - 1)  //normal straight movement
        {
            for(size_t i{0}; i < GameBoard::getWhitePieces().size();i++)
            {
                if(GameBoard::getWhitePieces().at(i) -> getRowPos() == rowPos && GameBoard::getWhitePieces().at(i) -> getColPos() == colPos)
                {

                    return false;
                }

            }
            for(size_t i{0}; i < GameBoard::getBlackPieces().size();i++)
            {
                if(GameBoard::getBlackPieces().at(i) -> getRowPos() == rowPos && GameBoard::getBlackPieces().at(i) -> getColPos() == colPos)
                {

                    return false;
                }

            }
            return GamePiece::MovePiece(rowPos,colPos);
        }

        else if((this->colPos == colPos + 1 || this->colPos == colPos - 1) && this->rowPos == rowPos - 1) //diagonal capture move
        {
            for(size_t i{0}; i < GameBoard::getWhitePieces().size();i++)
            {
                if(GameBoard::getWhitePieces().at(i) -> getRowPos() == rowPos && GameBoard::getWhitePieces().at(i) -> getColPos() == colPos)
                {
                    GameBoard::getWhitePieces().erase(GameBoard::getWhitePieces().begin() + i); //removing the desired black piece
                    return GamePiece::MovePiece(rowPos,colPos);
                }

            }
        }
    }
    return false;
}


