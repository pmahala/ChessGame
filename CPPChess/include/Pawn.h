#ifndef PAWN_H
#define PAWN_H
#include"GamePiece.h"


class Pawn:public GamePiece
{
    public:
        Pawn(int rowPos,int colPos,bool isWhite,std::string symbol);
        virtual ~Pawn() = default;

        virtual bool MovePiece(int rowPos,int colPos) override;

    protected:

    private:
};

#endif // PAWN_H
