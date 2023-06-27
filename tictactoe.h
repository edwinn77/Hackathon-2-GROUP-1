#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <iostream>

using namespace std;

class TicTacToe {
public:
    TicTacToe(bool isHardMode);

    void printBoard();
    bool checkWin();
    bool checkDraw();
    void makeMove(int move, char player);
    int getComputerMove();
    void playGame(int& credit, double& gpa);

private:
    bool hardMode;
    char board[9];

    int getEasyModeMove();
    int getHardModeMove();
    int minimax(char board[9], int depth, bool isMaximizingPlayer);
};

void playTicTacToe(int& credit, double& gpa);

#endif

