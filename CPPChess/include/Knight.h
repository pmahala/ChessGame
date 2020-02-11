#ifndef KNIGHT_H
#define KNIGHT_H
#include "GamePiece.h"


class Knight : public GamePiece
{
    public:
        Knight(int rowPos,int colPos,bool isWhite,std::string symbol);
        virtual ~Knight() = default;

        virtual bool MovePiece(int rowPos,int colPos) override;

    protected:

    private:
};

#endif // KNIGHT_H
