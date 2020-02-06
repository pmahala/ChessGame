#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include<vector>
#include"GamePiece.h"
#include<iostream>
#include<string>


class GameBoard
{
    friend std::ostream& operator<<(std::ostream& os,const GamePiece& g);


    public:
        static void initBoard();
        static void dispBoard();


        static bool isPlayerWhiteTurn();
        static std::vector<GamePiece*>& getWhitePieces();
        static std::vector<GamePiece*>& getBlackPieces();

        static bool runGame();


    protected:

    private:
        static std::vector <std::vector<std::string>> chessBoard;
        static std::vector<GamePiece*> onBoardWhites;
        static std::vector<GamePiece*> onBoardBlacks;
        static bool playerWhiteTurn;

        static void updateGameBoard(GamePiece* piece,int oldRow, int oldCol);

        //static bool checkWin();

};

#endif // GAMEBOARD_H
