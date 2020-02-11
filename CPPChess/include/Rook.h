#ifndef ROOK_H
#define ROOK_H
#include"GamePiece.h"


class Rook: virtual public GamePiece
{
    public:
        Rook(int rowPos,int colPos,bool isWhite,std::string symbol);
        virtual ~Rook() = default;

        virtual bool MovePiece(int rowPos,int colPos) override;

    protected:

    private:
};

#endif // ROOK_H
