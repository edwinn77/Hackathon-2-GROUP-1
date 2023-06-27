#include <iostream>
#include <chrono>
#include <thread>
#include <limits>
#include <climits>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <fstream>

using namespace std;

#ifndef GAME_H
#define GAME_H

using namespace std;

class Game {
private:
    int pos;
    int credit;
    double GPA;
    void (*playFunction)(int&, double&);  // Function pointer member variable

public:
    string title;

    // Constructors
    Game();
    Game(string t, int p, int c, int g, void (*playFunc)(int&, double&));

    // Accessor methods
    string getTitle() const;
    int getPos() const;
    int getCredit() const;
    double getGPA() const;
    void (*getPlayFunction())(int&, double&) const;

    // Mutator methods
    void setTitle(string t);
    void setPos(int p);
    void setCredit(int c);
    void setGPA(int g);
    void setPlayFunction(void (*playFunc)(int&, double&));

    // Display method
    void displayGame() const;

    // Play function
    void playGame(int& credit, double& gpa) const;
};

#endif  // GAME_H

#include "game.h"
#include <iostream>

using namespace std;

// Constructors
Game::Game() {
    title = "";
    pos = 0;
    credit = 0;
    GPA = 0;
    playFunction = nullptr;
}

Game::Game(string t, int p, int c, int g, void (*playFunc)(int&, double&)) {
    title = t;
    pos = p;
    credit = c;
    GPA = g;
    playFunction = playFunc;
}

// Accessor methods
string Game::getTitle() const {
    return title;
}

int Game::getPos() const {
    return pos;
}

int Game::getCredit() const {
    return credit;
}

double Game::getGPA() const {
    return GPA;
}

void (*Game::getPlayFunction())(int&, double&) const {
    return playFunction;
}

// Mutator methods
void Game::setTitle(string t) {
    title = t;
}

void Game::setPos(int p) {
    pos = p;
}

void Game::setCredit(int c) {
    credit = c;
}

void Game::setGPA(int g) {
    GPA = g;
}

void Game::setPlayFunction(void (*playFunc)(int&, double&)) {
    playFunction = playFunc;
}

// Display method
void Game::displayGame() const {
    cout << "Game: " << title << endl;
    // cout << "Position: " << pos << endl;
    cout << "Credit: " << credit << endl;
    cout << "GPA: " << GPA << endl;
}

// Play function
void Game::playGame(int& credit, double& gpa) const {
    if (playFunction) {
        playFunction(credit, gpa);
    } else {
        cout << "No play function assigned to this game." << endl;
    }
}


#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList {
public:
	struct ListNode {
        T value;              // Node value of type T
        ListNode* next;    // Pointer to the next node
    };
    ListNode* head;
    // Constructor
    LinkedList();

    // Destructor
    ~LinkedList();

    // Linked list operations
    void appendNode(T);
    void insertNode(T);
    void deleteNode(int);
    void searchNode(int);
    void displayList() const;
};

//#include "linkedlist.cpp"  // Include the source file

#endif  // LINKEDLIST_H

#include "linkedlist.h"
#include "game.h"  // Include the necessary header file(s)

#include <iostream>

using namespace std;

template <class T>
LinkedList<T>::LinkedList() {
    head = nullptr;
}

template <class T>
LinkedList<T>::~LinkedList() {
    ListNode* nodePtr = head;
    while (nodePtr) {
        ListNode* garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

template <class T>
void LinkedList<T>::appendNode(T newValue) {
    ListNode* newNode = new ListNode;
    newNode->value = newValue;
    newNode->next = nullptr;

    if (!head) {
        head = newNode;
    } else {
        ListNode* nodePtr = head;
        while (nodePtr->next) {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
    }
}

template <class T>
void LinkedList<T>::displayList() const {
    ListNode* nodePtr = head;
    double totalCredit = 0;
    double totalGPA = 0.0;
    double totalCGPA = 0.0;

    while (nodePtr) {
        nodePtr->value.displayGame();
        cout << endl;

        totalCredit += nodePtr->value.getCredit();
        totalGPA += nodePtr->value.getGPA() * nodePtr->value.getCredit();

        nodePtr = nodePtr->next;
    }
    cout << "Total Credit: " << totalCredit << endl;
    if (totalCredit != 0.0) {
        totalCGPA = totalGPA / totalCredit;
    } else {
        totalCGPA = 0.0; // Handle the case where totalCredit is zero to avoid division by zero
    }
    cout << "Total CGPA: " << totalCGPA << endl
         << endl;
}

template <class T>
void LinkedList<T>::insertNode(T newValue) {
    ListNode* newNode = new ListNode;
    newNode->value = newValue;

    if (!head) {
        head = newNode;
        newNode->next = nullptr;
    } else {
        ListNode* nodePtr = head;
        ListNode* previousNode = nullptr;

        while (nodePtr && nodePtr->value.getPos() < newValue.getPos()) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (previousNode == nullptr) {
            head = newNode;
            newNode->next = nodePtr;
        } else {
            previousNode->next = newNode;
            newNode->next = nodePtr;
        }
    }
}

template <class T>
void LinkedList<T>::deleteNode(int pos) {
    ListNode* nodePtr = head;
    ListNode* previousNode = nullptr;

    if (head->value.getPos() == pos) {
        head = nodePtr->next;
        delete nodePtr;
    } else {
        while (nodePtr && nodePtr->value.getPos() != pos) {
            previousNode = nodePtr;
            nodePtr = nodePtr->next;
        }

        if (nodePtr) {
            previousNode->next = nodePtr->next;
            delete nodePtr;
        }
    }
}

template <class T>
void LinkedList<T>::searchNode(int pos) {
    ListNode* nodePtr = head;
    while (nodePtr) {
        if (nodePtr->value.getPos() == pos) {
            nodePtr->value.displayGame();
            return;
        }
        nodePtr = nodePtr->next;
    }

    cout << "Game not found." << endl;
}


//int getInput(int min, int max) {
//    int input;
//    while (true) {
//        if (cin >> input) {
//            if (input >= min && input <= max) {
//                break;  // Valid input within range
//            }
//        }
//        cin.clear();
//        cin.ignore(numeric_limits<streamsize>::max(), '\n');
//        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
//    }
//    return input;
//}

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

#include "tictactoe.h"

#include <limits>
#include <climits>
#include <ctime>
#include <iostream>

using namespace std;

int getInput(int min, int max) {
    int input;
    while (true) {
        if (cin >> input) {
            if (input >= min && input <= max) {
                break;  // Valid input within range
            }
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between " << min << " and " << max << ": ";
    }
    return input;
}

TicTacToe::TicTacToe(bool isHardMode) : hardMode(isHardMode) {
    // Set seed for random number generation
    srand(time(0));

    // Initialize the board with empty spaces
    for (int i = 0; i < 9; i++) {
        board[i] = ' ';
    }
}

void TicTacToe::printBoard() {
    cout << endl << board[0] << " | " << board[1] << " | " << board[2] << endl;
    cout << "---------" << endl;
    cout << board[3] << " | " << board[4] << " | " << board[5] << endl;
    cout << "---------" << endl;
    cout << board[6] << " | " << board[7] << " | " << board[8] << endl;
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

        if (currentPlayer == 'X') {
            int move;
            cout << "Press 0 to quit the game. Once quit, the progress will be deleted\n";
            cout << "Player " << currentPlayer << ", choose your spot: ";
            move = getInput(0, 9);
            if (move == 0) {
                return;
            }
            move--;

            if (board[move] != ' ') {
                cout << "Invalid move. Please try again." << endl;
                continue;
            }

            makeMove(move, currentPlayer);
        } else {
            int move = getComputerMove();
            makeMove(move, currentPlayer);
            cout << "Computer chose spot " << move + 1 << endl;
        }

        if (checkWin()) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            if (currentPlayer == 'X') {
                cout << "============================================" << endl;
                cout << "============================================" << endl;

                cout << "4 credits gained by you." << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "Pointer of 4.0 is gained by you." << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "Continue your journey to the next stage!!" << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                credit = 4;
                gpa = 4.0;
            } else {
                cout << "============================================" << endl;
                cout << "============================================" << endl;

                cout << "4 credits gained by you." << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "Pointer of 1.0 is gained by you." << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "Continue your journey to the next stage!!" << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                credit = 4;
                gpa = 1.0;
            }

            break;
        } else if (checkDraw()) {
            printBoard();
            cout << "It's a draw!" << endl;
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
    //this_thread::sleep_for(chrono::milliseconds(800));
    cout << "You are exploring the university campus when you stumble upon an event organized by IMCC (an organization in USM)." << endl;
    //this_thread::sleep_for(chrono::milliseconds(800));
    cout << "The event aims to train your logical thinking skills through playing Tic Tac Toe." << endl;
    //this_thread::sleep_for(chrono::milliseconds(800));
    cout << "You are intrigued and decide to participate." << endl;
    //this_thread::sleep_for(chrono::milliseconds(800));
    cout << "If you win the game, you will earn 4 unit credit hours!" << endl;
    //this_thread::sleep_for(chrono::milliseconds(800));
    cout << "\nChoose game mode:\n1. Easy mode\n2. Hard mode\n\n";

    int choice;
    choice = getInput(1, 2);
    if (choice == 2) {
        isHardMode = true;
    } else {
        isHardMode = false;
    }

    TicTacToe game(isHardMode);
    game.playGame(credit, gpa);
}


#ifndef CONNECT4_H
#define CONNECT4_H

const int ROWS = 6;
const int COLS = 7;
const int WINNING_SCORE = 1000000;

enum class Player { RED, YELLOW };

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

#endif  // CONNECT4_H

#include "connect4.h"
#include <iostream>
#include <climits>

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
            cout << "| " << board[i][j] << " ";
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
        if (board[startRow + i * rowDelta][startCol + i * colDelta] == getPlayerSymbol(Player::RED)) {
            playerCount++;
        }
        else if (board[startRow + i * rowDelta][startCol + i * colDelta] == getPlayerSymbol(Player::YELLOW)) {
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
    Player currentPlayer = (maximizingPlayer) ? Player::YELLOW : Player::RED;

    if (depth == 0 || checkWin(Player::YELLOW) || checkWin(Player::RED) || isBoardFull()) {
        if (checkWin(Player::YELLOW)) {
            return WINNING_SCORE;
        }
        else if (checkWin(Player::RED)) {
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
            makeMove(col, Player::YELLOW);
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
    return (player == Player::RED) ? 'R' : 'Y';
}

void playConnect4(int& credit, double& gpa) {
    // Connect 4 game code
    cout << "\nPlaying Connect 4 game..." << endl;
    cout << "You stumble upon a competition organized by the Chess and Board Club, where participants are playing Connect 4." << endl;
    cout << "The winner of the competition will receive 4 unit credits of co-curricular!" << endl;

    Connect4 game;
    Player currentPlayer = Player::RED;

    while (true) {
    	//this_thread::sleep_for(chrono::milliseconds(1000));
        game.printBoard();

        if (currentPlayer == Player::RED) {
            int column;
            cout<< "Press 0 to quit the game. Once quit, the progress will be deleted\n";
            cout << "Player's turn (RED). Enter column (1-7): ";
            column= getInput(0, 7);
                if(column == 0){
                	return;
				}

            if (game.isValidMove(column)) {
                game.makeMove(column, currentPlayer);
                if (game.checkWin(currentPlayer)) {
                    game.printBoard();
                    cout << "Player (RED) wins!\n";
                    cout << "============================================" << endl;
        			cout << "============================================" << endl;
            		
        			cout << "4 credits gained by you." << endl;
        			//this_thread::sleep_for(chrono::milliseconds(1000));
        			cout << "Pointer of 4.0 is gained by you." << endl;
        			//this_thread::sleep_for(chrono::milliseconds(1000));
        			cout << "Continue your journey to the next stage!!" << endl;
        			//this_thread::sleep_for(chrono::milliseconds(1000));
                    credit= 4;
        			gpa= 4.0;
                    break;
                }
                currentPlayer = Player::YELLOW;
            }
            else {
                cout << "Invalid move. Try again.\n";
            }
        }
        else {
            cout << "Computer's turn (YELLOW).\n";
            int column = game.getComputerMove();

            if (column != -1) {
                game.makeMove(column, currentPlayer);
                if (game.checkWin(currentPlayer)) {
                    game.printBoard();
                    cout << "Computer (YELLOW) wins!\n";
                    cout << "============================================" << endl;
        			cout << "============================================" << endl;
            		
        			cout << "2 credits gained by you." << endl;
        			//this_thread::sleep_for(chrono::milliseconds(1000));
        			cout << "Pointer of 1.0 is gained by you." << endl;
        			//this_thread::sleep_for(chrono::milliseconds(1000));
        			cout << "Continue your journey to the next stage!!" << endl;
        			//this_thread::sleep_for(chrono::milliseconds(1000));
                    credit= 4;
        			gpa= 1.0;
                    break;
                }
                currentPlayer = Player::RED;
            }
        }

        if (game.isBoardFull()) {
            game.printBoard();
            cout << "It's a tie!\n";
            break;
        }
    }
}



#ifndef GUESS_THE_NUMBER_GAME_H
#define GUESS_THE_NUMBER_GAME_H

class GuessTheNumberGame {
private:
    class Node {
    public:
        int data;
        Node* next;
        Node(int value) : data(value), next(nullptr) {}
    };
    Node* head;
    int remainingChances;
    float score;
    int totalGuesses;

public:
    GuessTheNumberGame();
    void addGuess(int guess);
    void displayGuesses();
    friend void playGuessTheNumber(int&, double&);
};

void playGuessTheNumber(int& credit, double& gpa);

#endif  // GUESS_THE_NUMBER_GAME_H


//#include "guess_the_number_game.h"
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

GuessTheNumberGame::GuessTheNumberGame() : head(nullptr), remainingChances(2), totalGuesses(0), score(100.0) {}

void GuessTheNumberGame::addGuess(int guess) {
    Node* new_node = new Node(guess);

    if (head == nullptr) {
        head = new_node;
    } else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new_node;
    }
    totalGuesses++;
}

void GuessTheNumberGame::displayGuesses() {
    Node* current = head;
    if (current == nullptr) {
        cout << "No guesses yet." << endl;
    } else {
        cout << "Previous guesses:" << endl;
        while (current != nullptr) {
            cout << current->data << endl;
            current = current->next;
        }
    }
}

void playGuessTheNumber(int& credit, double& gpa) {
    GuessTheNumberGame game;

    unsigned seed = time(0);
    srand(seed);
    int number_to_guess = rand() % 100 + 1;
    int guess;
    //this_thread::sleep_for(chrono::milliseconds(800));
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "As a psychology student, you have embarked on a journey to test and " << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "enhance your skills as a psychologist analytician. In this challenging game," << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "you will face a series of intriguing scenarios that require sharp observation" << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "and logical thinking. Dive deep into the human mind, unravel mysteries," << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "and prove your expertise in the fascinating realm of psychology." << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Can you emerge as a successful psychologist analytician?" << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << endl;
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;

    cout << "You have to guess a number in the range of 1 - 100." << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Try to use the least step to achieve your goal to score higher marks!!" << endl;
    //this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "You have 2 chances to guess the number without penalty." << endl;
    //this_thread::sleep_for(chrono::milliseconds(1300));
    cout << "Gambateh!!" << endl << endl;
    //this_thread::sleep_for(chrono::milliseconds(1000));
    cout << endl;
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;

    while (true) {
    	cout<< "\nPress 0 to quit the game. Once quit, the progress will be deleted";
        cout << endl << "Enter your guess: ";
        //this_thread::sleep_for(chrono::milliseconds(1000));
        guess= getInput(0, 100);
            if(guess == 0){
            	return;
			}
        
        cout<< endl;
        game.addGuess(guess);

        if (guess == number_to_guess) {
            cout << "Congratulations! You guessed the number correctly." << endl;
            //this_thread::sleep_for(chrono::milliseconds(2000));
            break;
        } else if (guess < number_to_guess) {
            cout << "Too low! Try again.\n" << endl;
            //this_thread::sleep_for(chrono::milliseconds(1000));
        } else {
            cout << "Too high! Try again.\n" << endl;
            //this_thread::sleep_for(chrono::milliseconds(1000));
        }

        game.displayGuesses();
        game.remainingChances--;

        if (game.remainingChances < 0) {
            game.score -= 10.0; // Deduct 10% score for each additional guess
        }

        if (game.score < 0.0) {
            game.score = 0.0;
        }
    }

    cout << "Total guesses: " << game.totalGuesses << endl;
    cout << "Score: " << game.score << "%" << endl;
    //this_thread::sleep_for(chrono::milliseconds(1000));
    if (game.score < 70.0) {
        cout << "============================================" << endl;
        cout << "============================================" << endl;
        cout << "You have failed the STU202 course." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Continue your journey to the next stage!!" << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        credit=4;
        gpa= 1.0;
    } else {
        cout << "============================================" << endl;
        cout << "============================================" << endl;
        cout << "You pass the STU202 course!" << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "4 credits gained by you." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Continue your journey to the next stage!!" << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        credit=4;
        gpa= 4.0;
    }
}


#ifndef MATH_GAME_H
#define MATH_GAME_H

#include <iostream>

class MathGame {
private:
    int score;
    int numQuestions;
    int maxNumber;
    int timeLimitSeconds;

public:
    MathGame(int numQuestions = 5, int maxNumber = 50, int timeLimitSeconds = 10);
    friend void playMathGame(int&, double&);
};

void playMathGame(int& credit, double& gpa);

#endif


//#include "MathGame.h"

MathGame::MathGame(int numQuestions, int maxNumber, int timeLimitSeconds)
    : score(0), numQuestions(numQuestions), maxNumber(maxNumber), timeLimitSeconds(timeLimitSeconds) {}

void playMathGame(int& credit, double& gpa) {
	MathGame gameM;
	srand(time(0));
    //this_thread::sleep_for(chrono::milliseconds(800));
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Welcome to the Math School!" << endl;
    cout << "As a mathematics student, mastering numbers and mental" << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "calculation is fundamental. It not only hones your quick thinking skills but also keeps your" << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "mind constantly engaged, greatly enhancing memory and logical thinking abilities. Get " << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "ready to embark on a journey of rapid mental calculations and sharpen your mathematical " << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "prowess at the Math School!" << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << endl;
	cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;
    
	//this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Answer the following math questions to earn points." << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "You will be asked " << gameM.numQuestions << " questions." << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "You have " << gameM.timeLimitSeconds << " seconds to answer each question." << endl;
    //this_thread::sleep_for(chrono::milliseconds(1500));

    for (int i = 1; i <= gameM.numQuestions; i++) {
        int num1 = rand() % gameM.maxNumber + 1;
        int num2 = rand() % gameM.maxNumber + 1;
        int answer;
        int userAnswer;

        // Generate a random math operation (+, -, *)
        int operation = rand() % 3;
        char operatorSymbol;

        switch (operation) {
            case 0:
                answer = num1 + num2;
                operatorSymbol = '+';
                break;
            case 1:
                answer = num1 - num2;
                operatorSymbol = '-';
                break;
            case 2:
                answer = num1 * num2;
                operatorSymbol = '*';
                break;
        }

        cout << "\nQuestion " << i << ": ";
        cout << num1 << " " << operatorSymbol << " " << num2 << " = ";

        // Start the timer
        auto startTime = chrono::steady_clock::now();

        // Read user input
    	userAnswer= getInput(-1661992959, 1661992959);

        // Stop the timer
        auto endTime = chrono::steady_clock::now();
        auto elapsedTime = chrono::duration_cast<chrono::seconds>(endTime - startTime).count();

        if (elapsedTime > gameM.timeLimitSeconds) {
            cout << "Time's up! You took too long to answer." << endl;
        } else {
            if (userAnswer == answer) {
                cout << "Correct! You earned 10 points." << endl;
                gameM.score += 10;
            } else {
                cout << "Wrong answer. The correct answer is " << answer << "." << endl;
            }
        }
    }

    cout << "\nGame Over!" << endl;
    //this_thread::sleep_for(chrono::milliseconds(700));
    cout << "Your score: " << gameM.score << "/50" << endl;
    //this_thread::sleep_for(chrono::milliseconds(500));
    if (gameM.score < 30.0) {
    	cout << "============================================" << endl;
    	cout << "============================================" << endl;
        cout << "You have failed the MAA100 course." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Continue your journey to the next stage!!" << endl;
        credit= 4;
        gpa= 1.0;
    	//this_thread::sleep_for(chrono::milliseconds(1000));
    } else {
    	cout << "============================================" << endl;
    	cout << "============================================" << endl;
        cout << "You pass the MAA100 course!" << endl;
    	//this_thread::sleep_for(chrono::milliseconds(1000));
    	cout << "4 credits gained by you." << endl;
    	//this_thread::sleep_for(chrono::milliseconds(1000));
    	cout << "Continue your journey to the next stage!!" << endl;
    	//this_thread::sleep_for(chrono::milliseconds(1000));
    	credit= 4;
        gpa= 4.0;
    }
}


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

//#include "SudokuGame.h"
#include <iostream>

bool SudokuGame::isValidMove(int row, int col, int value) {
    // Check if the move is valid by comparing with the solution
    return board[row][col] == 0 && solution[row][col] == value;
}

bool SudokuGame::isGameOver() {
    // Check if the Sudoku is solved
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

void SudokuGame::displayBoard() {
    std::cout << "---------------------" << std::endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 0) {
                std::cout << " .";
            } else {
                std::cout << " " << board[i][j];
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------" << std::endl;
}

int SudokuGame::calculateScore() {
    int maxPossibleScore = 100;
    double penaltyPercentage = 0.1;
    double penaltyFactor = 1.0 - (penaltyPercentage * totalPenalty);
    int score = static_cast<int>(maxPossibleScore * penaltyFactor);
    return score;
}

SudokuGame::SudokuGame() : penalty(0), totalPenalty(0) {
}

void SudokuGame::initialize(const int initialBoard[5][5], const int solutionBoard[5][5]) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            board[i][j] = initialBoard[i][j];
            solution[i][j] = solutionBoard[i][j];
        }
    }
}

void SudokuGame::instruction() {
    std::cout << "**************************************************************************" << std::endl;
    std::cout << "**************************************************************************" << std::endl;
    std::cout << std::endl;
    std::cout << "As a management student, having a clear mindset and logical thinking is crucial for solving " << std::endl;
    std::cout << "real-life problems. Sudoku, a challenging game, tests your ability to maintain focus and" << std::endl;
    std::cout << "follow a systematic approach step by step, ensuring the accuracy of your answers. These" << std::endl;
    std::cout << "skills are invaluable in your future management career, where you'll navigate complex tasks " << std::endl;
    std::cout << "and employ a methodical approach, including the management of pseudocode. By " << std::endl;
    std::cout << "mastering Sudoku, you cultivate analytical thinking and develop a systematic problem-" << std::endl;
    std::cout << "solving mindset to tackle the challenges that lie ahead." << std::endl;
    std::cout << std::endl;
    std::cout << "**************************************************************************" << std::endl;
    std::cout << "**************************************************************************" << std::endl << std::endl;

    std::cout << "Welcome to Sudoku!" << std::endl;
    std::cout << "Fill in the numbers from 1 to 5 in each row, column, and block." << std::endl;
    std::cout << "You will receive a penalty for each wrong move." << std::endl;
    std::cout << "10% will be deducted when you get each penalty." << std::endl;
    std::cout << "You will fail when your score is below 70%." << std::endl;
    std::cout << "So, you have only 3 chances to pass this game!" << std::endl;
    std::cout << "Good luck!" << std::endl;
    std::cout << std::endl;
}

void playSudokuGame(int& credit, double& gpa) 
{
	SudokuGame GameS;
	GameS.instruction();
	
	int initialBoard[5][5] = {
    {0, 0, 1, 0, 4},
    {0, 2, 0, 1, 0},
    {0, 0, 2, 0, 3},
    {4, 1, 0, 0, 0},
    {0, 0, 0, 2, 1}
    };

    int solutionBoard[5][5] = {
    {2, 3, 1, 5, 4},
    {3, 2, 4, 1, 5},
    {1, 5, 2, 4, 3},
    {4, 1, 5, 3, 2},
    {5, 4, 3, 2, 1}
    };
	
	GameS.initialize(initialBoard, solutionBoard);
	
    while (!GameS.isGameOver()) 
	{
        GameS.displayBoard();
        int row, col, value;
        cout<< "Press 0 to quit the game. Once quit, the progress will be deleted\n";
        cout << "Enter row (1-5): ";
        row= getInput(0, 5);
        if(row == 0){
        	return;
		}
        cout << "Enter column (1-5): ";
        col= getInput(0, 5);
        if(col == 0){
        	return;
		}
        cout << "Enter value (1-5): ";
        value= getInput(0, 5);
        if(value == 0){
        	return;
		}

        if (GameS.isValidMove(row - 1, col - 1, value)) 
		{
            GameS.board[row - 1][col - 1] = value;
        }
		else
		{
            GameS.penalty++;
            GameS.totalPenalty++;
            cout << "Wrong move! Penalty applied." << endl;
            ////this_thread::sleep_for(chrono::milliseconds(1500));
        }
    }

    GameS.displayBoard();
    
    int score = GameS.calculateScore();
    cout << "Congratulations! You solved the Sudoku." <<endl;
    ////this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Penalty: " << GameS.totalPenalty << endl;
    ////this_thread::sleep_for(chrono::milliseconds(1500));
    cout << "Score: " << score << "%" <<endl;
    ////this_thread::sleep_for(chrono::milliseconds(1500));
	
    if (score >= 70) {
        cout << "You passed the game!" << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "You pass the AKW100 course!" << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "4 credits gained by you." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Pointer of 4.0 is gained by you." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Continue your journey to the next stage!!" << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        credit= 4;
        gpa= 4.0;
    } else {
        cout << "You did not pass the game." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
		cout << "You have failed the AKW100 course!" << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "4 credits gained by you." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Pointer of 1.0 is gained by you." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Continue your journey to the next stage!!" << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        credit= 4;
        gpa= 1.0;
    }
    
}


int main() {
    LinkedList<Game> gameList;
    LinkedList<Game>::ListNode* nodePtr = nullptr; // Move the declaration here

    Game ticTacToe("Tic Tac Toe", 1, 0, 0, playTicTacToe);
    Game connect4("Connect 4", 2, 0, 0, playConnect4);
    Game guessTheNumber("Guess the Number", 3, 0, 0, playGuessTheNumber);
    Game mathGame("Math Game", 4, 0, 0, playMathGame);
    Game sudokuGame("Sudoku Game", 5, 0, 0, playSudokuGame);

    gameList.appendNode(ticTacToe);
    gameList.appendNode(connect4);
    gameList.appendNode(guessTheNumber);
    gameList.appendNode(mathGame);
    gameList.appendNode(sudokuGame);

    cout << "========================================================================================================================" << endl;
    cout << "========================================================================================================================" << endl;
    cout << "========================================================================================================================" << endl;
    cout << "===================                          *                            *                          ===================" << endl;
    cout << "===================                          * *    University Life:    * *                          ===================" << endl;
    cout << "===================                          * *  The Parallel Journey  * *                          ===================" << endl;
    cout << "===================                          *                            *                          ===================" << endl;
    cout << "========================================================================================================================" << endl;
    cout << "========================================================================================================================" << endl;
    cout << "============================================      -> Start New Game     ================================================" << endl;
    cout << "============================================      -> Continue Game      ================================================" << endl;
    cout << "========================================================================================================================" << endl;
    cout << "========================================================================================================================" << endl;
    cout << "========================================================================================================================" << endl << endl;

    int mode;
    int num;

    cout << "Enter '1' to start a new game or '0' to continue the previous game." << endl;
    mode = getInput(0, 1);

    if (mode == 1) {
        cout << setw(50) << "University Life: The Parallel Journey" << endl << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "\"University Life\" is an immersive game that takes you on a thrilling " << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "adventure through a parallel time space. After a mysterious accident," << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "you find yourself transported into the world of Universiti Sains Malaysia (USM)," << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "where your sole mission is to graduate and escape this unfamiliar reality." << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "To achieve graduation, you must pass at least 4 out of 5 games, with your final score " << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "determining your future path. As you navigate this unknown world," << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "the outcome of your journey remains uncertain, and only your determination " << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "and wit will lead you towards the truth. Brace yourself for an unforgettable " << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "experience and face the challenges that lie ahead. " << endl << endl;
        //this_thread::sleep_for(chrono::milliseconds(1000));
        cout << "Good luck, young adventurer!" << endl << endl;
    } else if (mode == 0) {

        ifstream inputFile("Copy.txt"); // Open input file
        if (!inputFile) {
            cout << "Failed to open input file." << endl;
            return 1; // Return an error code
        }

        nodePtr = gameList.head;
        int c = 0;
        int g = 0.0;
        while (inputFile >> c >> g) {
            nodePtr->value.setCredit(c);
            nodePtr->value.setGPA(g);
            nodePtr = nodePtr->next;
        }
    }


    do {
        cout << "What do you want to do next?" << endl;
        cout << "1: Play game..." << endl;
        cout << "2. Store your game..." << endl;
        cout << "3. Open your storing part... " << endl;
        cout << "4. Calculate result..." << endl;
        cout << "5. Leave the game..." << endl;
        cout << "Enter a number between 1-5: ";

        num = getInput(1, 5);
        if (num == 1) {

            int pos;
            char choice;

            do {
                nodePtr = gameList.head; // Assign the value here
                cout << endl;
                cout << "Game 1: Tic Tac Toe" << endl;
                cout << "Game 2: Connect 4" << endl;
                cout << "Game 3: Guess The Number" << endl;
                cout << "Game 4: Math Game" << endl;
                cout << "Game 5: Sudoku Game" << endl;
                cout << "Enter a number between 1 and 5 to choose a game: ";
                pos = getInput(1, 5);


                while (nodePtr) {
                    if (nodePtr->value.getPos() == pos) {
                        int credit = nodePtr->value.getCredit(); // Retrieve the initial credit value
                        double gpa = nodePtr->value.getGPA();
                        nodePtr->value.playGame(credit, gpa);
                        nodePtr->value.setCredit(credit);
                        nodePtr->value.setGPA(gpa);
                        break;
                    }
                    nodePtr = nodePtr->next;
                }

                if (!nodePtr) {
                    cout << "Game not found." << endl;
                }

                cout << "Do you want to play another game?:" << endl;
                cout << "Press 'Y' - Yes" << endl;
                cout << "Press 'N' - No" << endl;
                cin >> choice;
                while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                    cout << "\nWrong character is chosen..." << endl;
                    cout << "Please type again: ";
                    cin >> choice;
                }
            } while (choice == 'Y' || choice == 'y');

            cout << endl << "----- Updated Game List -----" << endl;
            gameList.displayList();
        } else if (num == 2) {

            ofstream outputFile;
            outputFile.open("Copy.txt"); // Open output file

            if (!outputFile) {
                std::cout << "Failed to open output file." << std::endl;
                return 1; // Return an error code
            }

            nodePtr = gameList.head;

            while (nodePtr) {
                outputFile << nodePtr->value.getCredit() << "\t";
                outputFile << nodePtr->value.getGPA() << "\n";
                nodePtr = nodePtr->next;
            }


            outputFile.close();
            cout << "\nGame progress saved successfully.\n" << endl;
        } else if (num == 3) {
            ifstream inputFile("Copy.txt"); // Open input file
            if (!inputFile) {
                cout << "There is no stored game." << endl;
                return 1; // Return an error code
            }

            nodePtr = gameList.head;
            int c = 0;
            int g = 0.0;
            while (inputFile >> c >> g) {
                nodePtr->value.setCredit(c);
                nodePtr->value.setGPA(g);
                nodePtr = nodePtr->next;
            }


            inputFile.close();

            cout << endl << "----- Updated Game List -----" << endl;
            gameList.displayList();
        } else if (num == 4) {
            double totalCredit = 0;
            double totalGPA = 0.0;
            double totalCGPA = 0.0;
            nodePtr = gameList.head;

            while (nodePtr) {

                totalCredit += nodePtr->value.getCredit();
                totalGPA += nodePtr->value.getGPA() * nodePtr->value.getCredit();
                nodePtr = nodePtr->next;
            }
            cout << "\nTotal Credit: " << totalCredit << endl;
            if (totalCredit != 0.0) {
                totalCGPA = totalGPA / totalCredit;
            } else {
                totalCGPA = 0.0; // Handle the case where totalCredit is zero to avoid division by zero
            }
            cout << "Total CGPA: " << totalCGPA << endl << endl;
            if (totalCredit >= 16 && totalCGPA >= 2.5) {
                cout << "Congratulations, brave adventurer! You've conquered every challenge at USM. " << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "Cherish the memories, embrace the opportunities ahead, and let your achievements" << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "pave the way for a successful future. Onward to new horizons!" << endl;
                exit(0);
            } else {
                cout << "Unfortunately, You no have not achieve the criteria to pass this game. " << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "Even in the face of challenges, setbacks, and the occasional loss, you've displayed resilience" << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "and a determination to overcome. Embrace these experiences as valuable lessons on your " << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "path to success. Dust yourself off, learn from defeat, and let it fuel your journey towards " << endl;
                //this_thread::sleep_for(chrono::milliseconds(1000));
                cout << "victory. Keep pushing forward!\n" << endl;
            }
        } else if (num == 5) {
            break;
        }
    } while (num != 5);


    return 0;


}

