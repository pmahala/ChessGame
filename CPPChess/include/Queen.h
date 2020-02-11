#ifndef QUEEN_H
#define QUEEN_H
#include "Rook.h"
#include "Bishop.h"


class Queen: virtual public Rook, virtual public Bishop
{
    public:
        Queen(int rowPos,int colPos,bool isWhite,std::string symbol);
        virtual ~Queen() = default;

        virtual bool MovePiece(int rowPos,int colPos) override;

    protected:

    private:
};

#endif // QUEEN_H
