#ifndef GAMEBOARD_H
#define GAMEBOARD_H
#include<vector>


class GameBoard
{
    public:
        static void initBoard();
        static void dispBoard();

    protected:

    private:
        static std::vector <std::vector<char>> chessBoard;
};

#endif // GAMEBOARD_H
