#include "Rook.h"
#include "GameBoard.h"

Rook::Rook(int rowPos,int colPos,bool isWhite,std::string symbol): GamePiece(rowPos,colPos,isWhite,symbol){}

bool Rook::MovePiece(int rowPos,int colPos)
{
    if(isWhite)
    {
        if((this->rowPos == rowPos && colPos != this->colPos) || (this->colPos == colPos && rowPos != this->colPos))
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
            return GamePiece::MovePiece(rowPos,colPos);           //make move
        }
    }
    else
    {
        if((this->rowPos == rowPos && colPos != this->colPos) || (this->colPos == colPos && rowPos != this->colPos))
        {
            for(size_t i{0}; i < GameBoard::getWhitePieces().size();i++) //capture enemy piece at destination
            {
                if(GameBoard::getWhitePieces().at(i) -> getRowPos() == rowPos && GameBoard::getWhitePieces().at(i) -> getColPos() == colPos)
                {
                    GameBoard::getWhitePieces().erase(GameBoard::getWhitePieces().begin() + i); //removing the desired white piece
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
            return GamePiece::MovePiece(rowPos,colPos);           //make move
        }
    }
    return false;
}
