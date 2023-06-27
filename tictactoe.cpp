#include "tictactoe.h"
#include "game.h"
#include "clearconsole.h"

#include <climits>
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <chrono>
#include <thread>

// Color codes
#define BLUE "\033[1;34m"
#define RED "\033[1;31m"
#define RESET "\033[0m"

using namespace std;

TicTacToe::TicTacToe(bool isHardMode) : hardMode(isHardMode) {
    // Set seed for random number generation
    srand(time(0));

    // Initialize the board with empty spaces
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void TicTacToe::printBoard() {
    cout << (board[0] == 'X' ? BLUE : RED) << board[0] << RESET << " | ";
    cout << (board[1] == 'X' ? BLUE : RED) << board[1] << RESET << " | ";
    cout << (board[2] == 'X' ? BLUE : RED) << board[2] << RESET << endl;
    cout << "---------" << endl;
    cout << (board[3] == 'X' ? BLUE : RED) << board[3] << RESET << " | ";
    cout << (board[4] == 'X' ? BLUE : RED) << board[4] << RESET << " | ";
    cout << (board[5] == 'X' ? BLUE : RED) << board[5] << RESET << endl;
    cout << "---------" << endl;
    cout << (board[6] == 'X' ? BLUE : RED) << board[6] << RESET << " | ";
    cout << (board[7] == 'X' ? BLUE : RED) << board[7] << RESET << " | ";
    cout << (board[8] == 'X' ? BLUE : RED) << board[8] << RESET << endl;
}

bool TicTacToe::checkWin() {
    const int winConditions[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        int a = winConditions[i][0];
        int b = winConditions[i][1];
        int c = winConditions[i][2];
        if (board[a] == board[b] && board[b] == board[c] && board[a] != ' ') {
            return true;
        }
    }
    return false;
}

bool TicTacToe::checkDraw() {
    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            return false;
        }
    }
    return true;
}

void TicTacToe::makeMove(int move, char player) {
    board[move] = player;
}

int TicTacToe::getComputerMove() {
    if (hardMode) {
        return getHardModeMove();
    } else {
        return getEasyModeMove();
    }
}

void TicTacToe::playGame(int& credit, double& gpa) {
    char currentPlayer = 'X';

    while (true) {
        printBoard();

		int moveP;
        if (currentPlayer == 'X') {
            cout << "Press 0 to quit the game. Once quit, the progress will be deleted\n";
            cout << "Player " << currentPlayer << ", choose your spot: ";
            moveP = getInput(0, 9);
            clearConsole();
            if (moveP == 0) {
                return;
            }
            moveP--;

            if (board[moveP] != ' ') {
                cout << "Invalid move. Please try again." << endl;
                continue;
            }

            makeMove(moveP, currentPlayer);
        } else {
        	clearConsole();
        	cout<<"Your last chosen spot is "<< moveP+1<< endl;
            int move = getComputerMove();
            makeMove(move, currentPlayer);
            cout << "Computer's last chosen spot " << move + 1 << endl;
        }

        if (checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            if (currentPlayer == 'X') {
                cout << "\n============================================" << endl;
                cout << "============================================" << endl;
                cout << "4 credits gained by you." << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "Pointer of 4.0 is gained by you." << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "Continue your journey to the next stage!!\n" << endl;
                this_thread::sleep_for(chrono::milliseconds(800));

                credit = 4;
                gpa = 4.0;
            } else {
                cout << "\n============================================" << endl;
                cout << "============================================" << endl;

                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "4 credits gained by you." << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "Pointer of 1.0 is gained by you." << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "Continue your journey to the next stage!!\n" << endl;

                credit = 4;
                gpa = 1.0;
            }

            break;
        } else if (checkDraw()) {
            printBoard();
            cout << "It's a draw!" << endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            cout << "4 credits gained by you." << endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            cout << "Pointer of 2.5 is gained by you." << endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            cout << "Continue your journey to the next stage!!\n" << endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            credit = 4;
            gpa = 2.5;
            break;
        } else {
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }
}

int TicTacToe::getEasyModeMove() {
    // Simple random move for the computer player
    while (true) {
        int move = rand() % 9;
        if (board[move] == ' ') {
            return move;
        }
    }
}

int TicTacToe::getHardModeMove() {
    int bestScore = INT_MIN;
    int bestMove = -1;

    for (int i = 0; i < 9; i++) {
        if (board[i] == ' ') {
            board[i] = 'O';
            int score = minimax(board, 0, false);
            board[i] = ' '; // Undo the move

            if (score > bestScore) {
                bestScore = score;
                bestMove = i;
            }
        }
    }

    return bestMove;
}

int TicTacToe::minimax(char board[9], int depth, bool isMaximizingPlayer) {
    if (checkWin()) {
        return isMaximizingPlayer ? -1 : 1; // Human player wins (-1) or computer player wins (1)
    } else if (checkDraw()) {
        return 0; // It's a draw
    }

    if (isMaximizingPlayer) {
        int bestScore = INT_MIN;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'O';
                int score = minimax(board, depth + 1, false);
                board[i] = ' '; // Undo the move
                bestScore = max(score, bestScore);
            }
        }
        return bestScore;
    } else {
        int bestScore = INT_MAX;
        for (int i = 0; i < 9; i++) {
            if (board[i] == ' ') {
                board[i] = 'X';
                int score = minimax(board, depth + 1, true);
                board[i] = ' '; // Undo the move
                bestScore = min(score, bestScore);
            }
        }
        return bestScore;
    }
}

void playTicTacToe(int& credit, double& gpa) {
    bool isHardMode;
    cout<< endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Welcome to the Adventure of Tic Tac Toe!" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "---------------------------------------------------------" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "You are a young student embarking on a thrilling journey through the university campus." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "As you explore, you come across an event organized by IMCC, a prestigious organization in the university." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "They challenge you to a game of Tic Tac Toe to test your logical thinking skills!" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Winning the game will not only bring you glory but also earn you valuable credits towards your graduation." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Are you ready to take on the challenge and prove your strategic prowess?" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "---------------------------------------------------------" << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "\nChoose game mode:\n1. Easy mode\n2. Hard mode\n\n";

    int choice;
    choice = getInput(1, 2);
    clearConsole();
    if (choice == 2) {
        isHardMode = true;
    } else {
        isHardMode = false;
    }
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Here are the rules and regulations of the game:" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "1. The game is played on a 3x3 grid." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "2. Players take turns placing their symbol ('X' or 'O') in an empty cell of the grid." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "3. The first player to get three of their symbols in a row (horizontally, vertically, or diagonally) wins the game." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "4. If all cells are filled and no player has won, the game ends in a draw." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "5. In hard mode, the computer opponent will play strategically to try and win." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "6. Enjoy the game and have fun!" << endl;
    cout << endl;

    TicTacToe game(isHardMode);
    game.playGame(credit, gpa);
}
