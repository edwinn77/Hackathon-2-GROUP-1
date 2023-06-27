#ifndef SUDOKUGAME_H
#define SUDOKUGAME_H

class SudokuGame {
private:
    int board[5][5];
    int solution[5][5];
    int penalty;
    int totalPenalty;

public:
    bool isValidMove(int row, int col, int value);
    bool isGameOver();
    void displayBoard();
    int calculateScore();
    SudokuGame();
    void initialize(const int initialBoard[5][5], const int solutionBoard[5][5]);
    void instruction();

    friend void playSudokuGame(int&, double&);
};

void playSudokuGame(int& credit, double& gpa);

#endif  // SUDOKUGAME_H
