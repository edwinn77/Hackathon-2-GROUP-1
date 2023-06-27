#ifndef CONNECT4_H
#define CONNECT4_H

const int ROWS = 6;
const int COLS = 7;
const int WINNING_SCORE = 1000000;

enum class Player { BLUE, RED };

class Connect4 {
private:
    char board[ROWS][COLS];
    int movesLeft;

public:
    Connect4();
    void resetBoard();
    void printBoard() const;
    bool isValidMove(int column) const;
    void makeMove(int column, Player player);
    bool checkWin(Player player) const;
    bool isBoardFull() const;
    int evaluateBoard() const;
    int evaluateLine(int startRow, int startCol, int rowDelta, int colDelta) const;
    int minimax(int depth, int alpha, int beta, bool maximizingPlayer);
    int getComputerMove();
    void undoMove(int column);
    char getPlayerSymbol(Player player) const;
};
void playConnect4(int&, double&);
#endif  // CONNECT4_H

