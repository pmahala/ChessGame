#ifndef GAMEPIECE_H
#define GAMEPIECE_H

#include<string>


class GamePiece
{
    public:
        GamePiece(int rowPos,int colPos,bool isWhite, std::string symbol);
        virtual ~GamePiece() = default;

        virtual bool MovePiece(int rowPos,int colPos) = 0;
        int getRowPos();
        int getColPos();
        std::string getSymbol() const;
        bool ofWhitePlayer() const;

    protected:
        int rowPos;
        int colPos;
        bool isWhite;
        std::string symbol;

    private:
};

#endif // GAMEPIECE_H
