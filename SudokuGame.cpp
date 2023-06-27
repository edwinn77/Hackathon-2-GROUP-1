#include "SudokuGame.h"
#include "game.h"
#include "clearconsole.h"

#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

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
    cout << "---------------------" << endl;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (board[i][j] == 0) {
                cout << " .";
            } else {
                cout << " " << board[i][j];
            }
        }
        cout << endl;
    }
    cout << "---------------------" << endl;
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
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "As a management student, having a clear mindset and logical thinking is crucial for solving " << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "real-life problems. Sudoku, a challenging game, tests your ability to maintain focus and" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "follow a systematic approach step by step, ensuring the accuracy of your answers. These" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "skills are invaluable in your future management career, where you'll navigate complex tasks " << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "and employ a methodical approach, including the management of pseudocode. By " << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "mastering Sudoku, you cultivate analytical thinking and develop a systematic problem-" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "solving mindset to tackle the challenges that lie ahead." << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Welcome to Sudoku!" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Here are the rules and regulations of the game:" << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "1. Fill in the numbers from 1 to 5 in each row, column, and block." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "2. You will receive a penalty for each wrong move." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "3. 10% will be deducted when you get each penalty." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "4. You will fail when your score is below 70%." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "5. You have only 3 chances to pass this game!" << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Please keep the following points in mind:" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "- Input the row, column, and value for each move." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "- To quit the game and delete your progress, enter 0 for row, column, or value." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "- The game will display the current board after each move." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "- If you make a wrong move, a penalty will be applied." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "- Take your time, think carefully, and solve the Sudoku puzzle!" << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;
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
		clearConsole();

        if (GameS.isValidMove(row - 1, col - 1, value))  // valid move
		{
            GameS.board[row - 1][col - 1] = value;
        }
		else
		{
            GameS.penalty++;
            GameS.totalPenalty++;
            cout << "Wrong move! Penalty applied." << endl;
            this_thread::sleep_for(chrono::milliseconds(800));

            if(GameS.penalty>=3)
            {
            	int score = GameS.calculateScore();
            	cout << "Sorry , you already achived the maximum penalty"<< endl;
            	this_thread::sleep_for(chrono::milliseconds(800));
    			cout << "Penalty: " << GameS.totalPenalty << endl;
    			this_thread::sleep_for(chrono::milliseconds(800));
    			cout << "Score: " << score << "%" <<endl;
    			this_thread::sleep_for(chrono::milliseconds(800));
            	cout << "You did not pass the game." << endl;
		        this_thread::sleep_for(chrono::milliseconds(800));
				cout << "You have failed the AKW100 course!" << endl;
		        this_thread::sleep_for(chrono::milliseconds(800));
		        cout << "4 credits gained by you." << endl;
		        this_thread::sleep_for(chrono::milliseconds(800));
		        cout << "Pointer of 1.0 is gained by you." << endl;
		        this_thread::sleep_for(chrono::milliseconds(800));
		        cout << "Continue your journey to the next stage!!\n" << endl;
		        this_thread::sleep_for(chrono::milliseconds(800));
		        credit= 4;
		        gpa= 1.0;
            	return;
			}
        }
    }

    GameS.displayBoard();

    int score = GameS.calculateScore();
    cout << "Congratulations! You solved the Sudoku." <<endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Penalty: " << GameS.totalPenalty << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Score: " << score << "%" <<endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "You passed the game!" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
	cout << "You pass the AKW100 course!" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "4 credits gained by you." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Pointer of 4.0 is gained by you." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Continue your journey to the next stage!!\n" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    credit= 4;
    gpa= 4.0;

}
