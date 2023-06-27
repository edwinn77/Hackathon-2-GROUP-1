#include "connect4.h"
#include "game.h"
#include "clearconsole.h"

#include <iostream>
#include <climits>
#include <chrono>
#include <thread>

// Color constants
const string RESET_COLOR = "\033[0m";
const string RED_COLOR = "\033[31m";
const string BLUE_COLOR = "\033[1;34m";

using namespace std;

Connect4::Connect4() {
    resetBoard();
}

void Connect4::resetBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    movesLeft = ROWS * COLS;
}

void Connect4::printBoard() const {
    cout << "-----------------------------\n";
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            char symbol = board[i][j];
            if (symbol == getPlayerSymbol(Player::BLUE)) {
                cout << "| " << BLUE_COLOR << symbol << RESET_COLOR << " ";
            } else if (symbol == getPlayerSymbol(Player::RED)) {
                cout << "| " << RED_COLOR << symbol << RESET_COLOR << " ";
            } else {
                cout << "| " << symbol << " ";
            }
        }
        cout << "|\n-----------------------------\n";
    }
    cout << "| 1   2   3   4   5   6   7 |\n";
}

bool Connect4::isValidMove(int column) const {
    return column >= 1 && column <= COLS && board[0][column - 1] == ' ';
}

void Connect4::makeMove(int column, Player player) {
    if (isValidMove(column)) {
        for (int row = ROWS - 1; row >= 0; row--) {
            if (board[row][column - 1] == ' ') {
                board[row][column - 1] = getPlayerSymbol(player);
                break;
            }
        }
    }

    movesLeft--;
}

bool Connect4::checkWin(Player player) const {
    char symbol = getPlayerSymbol(player);

    // Check horizontal
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            if (board[row][col] == symbol &&
                board[row][col + 1] == symbol &&
                board[row][col + 2] == symbol &&
                board[row][col + 3] == symbol) {
                return true;
            }
        }
    }

    // Check vertical
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == symbol &&
                board[row + 1][col] == symbol &&
                board[row + 2][col] == symbol &&
                board[row + 3][col] == symbol) {
                return true;
            }
        }
    }

    // Check diagonally (bottom left to top right)
    for (int row = 3; row < ROWS; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            if (board[row][col] == symbol &&
                board[row - 1][col + 1] == symbol &&
                board[row - 2][col + 2] == symbol &&
                board[row - 3][col + 3] == symbol) {
                return true;
            }
        }
    }

    // Check diagonally (top left to bottom right)
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            if (board[row][col] == symbol &&
                board[row + 1][col + 1] == symbol &&
                board[row + 2][col + 2] == symbol &&
                board[row + 3][col + 3] == symbol) {
                return true;
            }
        }
    }

    return false;
}

bool Connect4::isBoardFull() const {
    return movesLeft == 0;
}

int Connect4::evaluateBoard() const {
    int score = 0;

    // Evaluate rows
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            score += evaluateLine(row, col, 0, 1);
        }
    }

    // Evaluate columns
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 0; col < COLS; col++) {
            score += evaluateLine(row, col, 1, 0);
        }
    }

    // Evaluate diagonals (bottom left to top right)
    for (int row = 3; row < ROWS; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            score += evaluateLine(row, col, -1, 1);
        }
    }

    // Evaluate diagonals (top left to bottom right)
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            score += evaluateLine(row, col, 1, 1);
        }
    }

    return score;
}

int Connect4::evaluateLine(int startRow, int startCol, int rowDelta, int colDelta) const {
    int score = 0;
    int computerCount = 0;
    int playerCount = 0;

    for (int i = 0; i < 4; i++) {
        if (board[startRow + i * rowDelta][startCol + i * colDelta] == getPlayerSymbol(Player::BLUE)) {
            playerCount++;
        }
        else if (board[startRow + i * rowDelta][startCol + i * colDelta] == getPlayerSymbol(Player::RED)) {
            computerCount++;
        }
    }

    if (playerCount == 0 && computerCount > 0) {
        score += computerCount * computerCount * computerCount;
    }
    else if (playerCount > 0 && computerCount == 0) {
        score -= playerCount * playerCount * playerCount;
    }

    return score;
}

int Connect4::minimax(int depth, int alpha, int beta, bool maximizingPlayer) {
    Player currentPlayer = (maximizingPlayer) ? Player::RED : Player::BLUE;

    if (depth == 0 || checkWin(Player::RED) || checkWin(Player::BLUE) || isBoardFull()) {
        if (checkWin(Player::RED)) {
            return WINNING_SCORE;
        }
        else if (checkWin(Player::BLUE)) {
            return -WINNING_SCORE;
        }
        else {
            return evaluateBoard();
        }
    }

    if (maximizingPlayer) {
        int maxScore = INT_MIN;

        for (int col = 1; col <= COLS; col++) {
            if (isValidMove(col)) {
                makeMove(col, currentPlayer);
                int score = minimax(depth - 1, alpha, beta, false);
                undoMove(col);
                maxScore = max(maxScore, score);
                alpha = max(alpha, score);
                if (beta <= alpha) {
                    break;
                }
            }
        }

        return maxScore;
    }
    else {
        int minScore = INT_MAX;

        for (int col = 1; col <= COLS; col++) {
            if (isValidMove(col)) {
                makeMove(col, currentPlayer);
                int score = minimax(depth - 1, alpha, beta, true);
                undoMove(col);
                minScore = min(minScore, score);
                beta = min(beta, score);
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return minScore;
    }
}

int Connect4::getComputerMove() {
    int bestScore = INT_MIN;
    int bestMove = -1;

    for (int col = 1; col <= COLS; col++) {
        if (isValidMove(col)) {
            makeMove(col, Player::RED);
            int score = minimax(5, INT_MIN, INT_MAX, false);
            undoMove(col);

            if (score > bestScore) {
                bestScore = score;
                bestMove = col;
            }
        }
    }

    return bestMove;
}

void Connect4::undoMove(int column) {
    for (int row = 0; row < ROWS; row++) {
        if (board[row][column - 1] != ' ') {
            board[row][column - 1] = ' ';
            break;
        }
    }

    movesLeft++;
}

char Connect4::getPlayerSymbol(Player player) const {
    return (player == Player::BLUE) ? 'B' : 'R';
}

void playConnect4(int& credit, double& gpa) {
    cout << "You stumble upon a Connect 4 competition organized by the Chess and Board Club." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
	cout << "The winner will receive 4 unit credits of co-curricular!" << endl;
	this_thread::sleep_for(chrono::milliseconds(800));
    cout << "---------------------------------------------------------" << endl<< endl;

    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Rules and Regulations of Connect 4:\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "----------------------------------\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "1. Connect 4 is a two-player game played on a vertical board with 6 rows and 7 columns.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "2. The players take turns dropping their colored discs (BLUE and RED) into the columns.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "3. The objective is to be the first to form a horizontal, vertical, or diagonal line of four discs of your color.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "4. The game ends in a tie if the entire board is filled with discs and no player has formed a line of four.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "5. Players can only drop their discs into the columns that are not fully occupied by other discs.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "6. The game continues until a player wins or it ends in a tie.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "7. In this version, you (BLUE) will play against the computer (RED).\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "8. To make a move, enter the column number (1-7) where you want to drop your disc.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "9. Press 0 to quit the game. Once quit, the progress will be deleted.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "10. The winner of the game will earn 4 unit credits of co-curricular.\n";
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "----------------------------------\n\n";


    Connect4 game;
    Player currentPlayer = Player::BLUE;

    while (true) {
        game.printBoard();

		int columnP;
        if (currentPlayer == Player::BLUE) {
            cout<< "Press 0 to quit the game. Once quit, the progress will be deleted\n";
            cout << "Player's turn (BLUE). Enter column (1-7): ";
            columnP= getInput(0, 7);
                if(columnP == 0){
                	return;
				}

            if (game.isValidMove(columnP)) {
                game.makeMove(columnP, currentPlayer);
                if (game.checkWin(currentPlayer)) {
                    game.printBoard();
                    cout << "Player (BLUE) wins!\n";
                    cout << "============================================" << endl;
        			cout << "============================================" << endl;

        			cout << "4 credits gained by you." << endl;
        			this_thread::sleep_for(chrono::milliseconds(800));
        			cout << "Pointer of 4.0 is gained by you." << endl;
        			this_thread::sleep_for(chrono::milliseconds(800));
        			cout << "Continue your journey to the next stage!!\n" << endl;
              this_thread::sleep_for(chrono::milliseconds(800));

              credit= 4;
        			gpa= 4.0;
                    break;
                }
                currentPlayer = Player::RED;
            }
            else {
                cout << "Invalid move. Try again.\n";
            }
        }
        else {
            clearConsole();
            int column = game.getComputerMove();

            if (column != -1) {
                game.makeMove(column, currentPlayer);
                if (game.checkWin(currentPlayer)) {
                    game.printBoard();
                    cout << "Computer (RED) wins!\n";
                    cout << "============================================" << endl;
        			cout << "============================================" << endl;

        			cout << "4 credits gained by you." << endl;
        			this_thread::sleep_for(chrono::milliseconds(800));
        			cout << "Pointer of 1.0 is gained by you." << endl;
        			this_thread::sleep_for(chrono::milliseconds(800));
        			cout << "Continue your journey to the next stage!!\n" << endl;
        			this_thread::sleep_for(chrono::milliseconds(800));
                    credit= 4;
        			gpa= 1.0;
                    break;
                }
                cout<< endl<< endl<< endl;
                cout<< "Your last chosen column is "<< columnP<< endl;
                cout<< "Computer's last chosen column "<< column<< endl;
                currentPlayer = Player::BLUE;
            }
        }

        if (game.isBoardFull()) {
            game.printBoard();
            cout << "It's a tie!\n";
            break;
        }
    }
}
