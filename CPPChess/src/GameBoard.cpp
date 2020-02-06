#include "GameBoard.h"
#include "Pawn.h"
#include<stdlib.h>



std::vector<std::vector<std::string>> GameBoard::chessBoard;
std::vector<GamePiece*> GameBoard::onBoardWhites;
std::vector<GamePiece*> GameBoard::onBoardBlacks;
bool GameBoard::playerWhiteTurn = true;

void GameBoard::initBoard()
{
    std::vector<std::string> blankPos {".",".",".",".",".",".",".","."};
    for(int i{0}; i < 8; i++)
    {
        chessBoard.push_back(blankPos);
    }

    for(int i{0}; i < 8; i++)
    {
        GamePiece *p = new Pawn(6,i,true,"w");
        onBoardWhites.push_back(p);
        chessBoard.at(p->getRowPos()).at(p->getColPos()) = p->getSymbol();
    }

    for(int i{0}; i < 8; i++)
    {
        GamePiece *p = new Pawn(1,i,false,"b");
        onBoardBlacks.push_back(p);
        chessBoard.at(p->getRowPos()).at(p->getColPos()) = p->getSymbol();
    }
}



void GameBoard::dispBoard()
{
    std::cout << "\t" << "0";
    std::cout << "\t" << "1";
    std::cout << "\t" << "2";
    std::cout << "\t" << "3";
    std::cout << "\t" << "4";
    std::cout << "\t" << "5";
    std::cout << "\t" << "6";
    std::cout << "\t" << "7\n";
    for(int i{0}; i < 8; i++)
    {
        std::cout << i << "\t";
        for(int j{0}; j < 8; j++)
        {
            std::cout << chessBoard.at(i).at(j) << "\t";
        }
        std::cout << std::endl << std::endl << std::endl;
    }
}

void GameBoard::updateGameBoard(GamePiece* g,int oldRow, int oldCol)
{
    chessBoard.at(g->getRowPos()).at(g->getColPos()) = g->getSymbol();
    chessBoard.at(oldRow).at(oldCol) = ".";
}

bool GameBoard::runGame()
{
    system("cls");
    dispBoard();

     playerWhiteTurn?std::cout << "\nWhite Player Move\n": std::cout<<"\nBlack Player Move\n";
    std::cout << "\nFrom (row,col)(space separated):";
    int r{},c{};
    std::cin >> r >> c;

    if(playerWhiteTurn)
    {
        for(GamePiece* g: onBoardWhites)
        {
            if(r == g->getRowPos() && c == g->getColPos() && g->ofWhitePlayer())
            {
                std::cout << "\nTo (row,col) (space separated):";
                int destR{},destC{};
                std::cin >> destR >> destC;
                if(g->MovePiece(destR,destC))
                {
                    updateGameBoard(g,r,c);

                    std::cout << "\nMove Made Successfully\n";
                    playerWhiteTurn = false;
                    break;

                }
                else
                {

                    std::cout << "\nINVALID MOVE.. TRY AGAIN!!\n";
                }

            }
        }


    }
    else
    {
        for(GamePiece* g: onBoardBlacks)
        {
            if(r == g->getRowPos() && c == g->getColPos() && !g->ofWhitePlayer())
            {
                std::cout << "\nTo (row,col) (space separated):";
                int destR{},destC{};
                std::cin >> destR >> destC;
                if(g->MovePiece(destR,destC))
                {
                    updateGameBoard(g,r,c);

                    std::cout << "\nMove Made Successfully\n";
                    playerWhiteTurn = true;
                    break;

                }
                else
                {
                    std::cout << "\nINVALID MOVE.. TRY AGAIN!!\n";
                }

            }
        }

    }
    return true;
}


std::vector<GamePiece*>& GameBoard::getWhitePieces()
{
    return onBoardWhites;
}
std::vector<GamePiece*>& GameBoard::getBlackPieces()
{
    return onBoardBlacks;
}

std::ostream& operator<<(std::ostream& os,const GamePiece& g)
{
        os << g.getSymbol();
        return os;
}
