#ifndef BISHOP_H
#define BISHOP_H
#include"GamePiece.h"

class Bishop: public GamePiece
{
    public:
        Bishop(int rowPos,int colPos,bool isWhite,std::string symbol);
        virtual ~Bishop() = default;

        virtual bool MovePiece(int rowPos,int colPos) override;

    protected:

    private:
};

#endif // BISHOP_H
