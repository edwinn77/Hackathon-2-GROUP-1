#include "linkedlist.h"
#include "linkedlist.cpp"
#include "game.h"
#include "tictactoe.h"
#include "connect4.h"
#include "guess_the_number_game.h"
#include "MathGame.h"
#include "SudokuGame.h"
#include "clearconsole.h"

#include <iostream>
#include <iomanip>
#include <fstream>
#include <chrono>
#include <thread>

using namespace std;

void deleteEntireCode(const string& fileName) {
    ofstream file(fileName, ios::trunc); // Open file in truncate mode to clear its contents

    if (file.is_open()) {
        file.close();
        //cout << "Previous game record is clear"<< endl;
    } else {
        cerr << "Unable to open file: " << fileName << endl;
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

    cout << "Enter '1' to start a new game or '0' to continue the previous game: ";
    mode = getInput(0, 1);
    clearConsole();

    if (mode == 1) {
				string fileName = "Copy.txt"; // Replace with the desired file name

    		deleteEntireCode(fileName);

    	cout<< setw(50)<< "###################################################################"<< endl;
        cout << setw(50) << "University Life: The Parallel Journey" << endl;
        cout<< setw(50)<< "###################################################################"<< endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "\"University Life\" is an immersive game that takes you on a thrilling " << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "adventure through a parallel time space. After a mysterious accident," << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "you find yourself transported into the world of Universiti Sains Malaysia (USM)," << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "where your sole mission is to graduate and escape this unfamiliar reality." << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "To achieve graduation, you must pass at least 4 out of 5 games, with your final score " << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "determining your future path. As you navigate this unknown world," << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "the outcome of your journey remains uncertain, and only your determination " << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "and wit will lead you towards the truth. Brace yourself for an unforgettable " << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "experience and face the challenges that lie ahead. " << endl << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
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
        cout << "3. Open your stored progress... " << endl;
        cout << "4. Show your result..." << endl;
        cout << "5. Leave the game..." << endl;
        cout << "Enter a number between 1-5: ";

        num = getInput(1, 5);
        clearConsole();
        if (num == 1) {

            int pos;
            char choice;

            do {
                nodePtr = gameList.head; // Assign the value here
                cout<< endl;
                cout << "Game 1: Tic Tac Toe" << endl;
                cout << "Game 2: Connect 4" << endl;
                cout << "Game 3: Guess The Number" << endl;
                cout << "Game 4: Math Game" << endl;
                cout << "Game 5: Sudoku Game" << endl;
                cout << "Enter a number between 1 and 5 to choose a game: ";
                pos = getInput(1, 5);
                clearConsole();

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
                clearConsole();
            } while (choice == 'Y' || choice == 'y');

            cout << endl << "----- Updated Game List -----" << endl;
            gameList.displayList();
        }
		else if (num == 2) {

            ofstream outputFile;
            outputFile.open("Copy.txt"); // Open output file

            if (!outputFile) {
                cout << "Failed to open output file." << endl;
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
        }
		else if (num == 3) {
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
        }
		else if (num == 4) {
            double totalCredit = 0;
            double totalGPA = 0.0;
            double totalCGPA = 0.0;
            nodePtr = gameList.head;

            while (nodePtr) {

                totalCredit += nodePtr->value.getCredit();
                totalGPA += nodePtr->value.getGPA() * nodePtr->value.getCredit();
                nodePtr = nodePtr->next;
            }
            if (totalCredit != 0.0) {
                totalCGPA = totalGPA / totalCredit;
            } else {
                totalCGPA = 0.0; // Handle the case where totalCredit is zero to avoid division by zero
            }
            cout<< "\nThe passing criteria is 16 unit credit and CGPA 2.5."<< endl;
            this_thread::sleep_for(chrono::milliseconds(800));
            cout << "You get total " << totalCredit << " credit and achieve CGPA "<< totalCGPA << endl << endl;
            this_thread::sleep_for(chrono::milliseconds(800));

            if (totalCredit >= 16 && totalCGPA >= 2.5) {
                cout << "Congratulations, brave adventurer! You've conquered every challenge at USM. " << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "Cherish the memories, embrace the opportunities ahead, and let your achievements" << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "pave the way for a successful future. Onward to new horizons!" << endl;

                char choice;
                cout<<"\nDo you want to back to the game to achieve a higher credit and CGPA ?"<< endl;
                cout << "Press 'Y' - Yes" << endl;
                cout << "Press 'N' - No" << endl;
                cin >> choice;
                while (choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
                    cout << "\nWrong character is chosen..." << endl;
                    cout << "Please type again: ";
                    cin >> choice;
                }
                if(choice == 'N' || choice == 'n'){
                	cout<<"You are the champion of the game!!!";
                	exit(0);
                }
                else{
                  cout<< endl;
                }

            } else {
                cout << "Unfortunately, You no have not achieve the criteria to pass this game. " << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "Even in the face of challenges, setbacks, and the occasional loss, you've displayed resilience" << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "and a determination to overcome. Embrace these experiences as valuable lessons on your " << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "path to success. Dust yourself off, learn from defeat, and let it fuel your journey towards " << endl;
                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "victory."<< endl<< endl;
				cout<< "Keep pushing forward to achieve a higher credit and CGPA!!!\n" << endl;
            }
        } else if (num == 5) {
        	ofstream outputFile;
            outputFile.open("Copy.txt"); // Open output file

            if (!outputFile) {
                cout << "Failed to open output file." << endl;
                return 1; // Return an error code
            }

            nodePtr = gameList.head;

            while (nodePtr) {
                outputFile << nodePtr->value.getCredit() << "\t";
                outputFile << nodePtr->value.getGPA() << "\n";
                nodePtr = nodePtr->next;
            }


            outputFile.close();
            cout << "\nGame progress saved successfully." << endl;
            cout << "Game quited";
            break;
        }
    } while (num != 5);
    return 0;
}
