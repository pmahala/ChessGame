#include "Queen.h"

Queen::Queen(int rowPos,int colPos,bool isWhite,std::string symbol):Rook(rowPos,colPos,isWhite,symbol),Bishop(rowPos,colPos,isWhite,symbol),GamePiece(rowPos,colPos,isWhite,symbol){}

bool Queen::MovePiece(int rowPos, int colPos)
{
    bool rookPlay = Rook::MovePiece(rowPos,colPos);
    if(!rookPlay)
    {
        return Bishop::MovePiece(rowPos,colPos);
    }
    return rookPlay;

}


