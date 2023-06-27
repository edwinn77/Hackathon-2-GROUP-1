#include "guess_the_number_game.h"
#include "game.h"
#include "clearconsole.h"

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>

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
        cout << "Previous guesses: ";
        while (current != nullptr) {
            cout << current->data << " ";
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
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "As a psychology student, you have embarked on a journey to test and " << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "enhance your skills as a psychologist analytician. In this challenging game," << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "you will face a series of intriguing scenarios that require sharp observation" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "and logical thinking. Dive deep into the human mind, unravel mysteries," << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "and prove your expertise in the fascinating realm of psychology." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Can you emerge as a successful psychologist analytician?" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << endl;
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;

    cout << "You have to guess a number in the range of 1 - 100." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Try to use the least step to achieve your goal to score higher marks!!" << endl;
    this_thread::sleep_for(chrono::milliseconds(2000));
    cout << "You have 2 chances to guess the number without penalty." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Gambateh!!" << endl << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << endl;
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;

    while (true) {
    	cout<< "\n\nPress 0 to quit the game. ";
		cout<<"\nOnce quit, the progress will be deleted.";
        cout << endl << "Enter your guess: ";
        this_thread::sleep_for(chrono::milliseconds(800));
        guess= getInput(0, 100);
            if(guess == 0){
            	return;
			}

        cout<< endl;
        game.addGuess(guess);

        if (guess == number_to_guess) {
            cout << "Congratulations! You guessed the number correctly." << endl;
            this_thread::sleep_for(chrono::milliseconds(2000));
            break;
        } else if (guess < number_to_guess) {
        	clearConsole();
//          cout << "\n\n";
        	cout << "\033[1;34m###################################################\033[0m" << endl;
          cout << "\033[1;36m\t\tToo low! Try again.\033[0m" << endl;
          cout << "\033[1;34m###################################################\033[0m" << endl << endl;

        } else {
        	clearConsole();
//          cout << "\n\n";
        	cout << "\033[1;34m###################################################\033[0m" << endl;
          cout << "\033[1;36m\t\tToo high! Try again.\033[0m" << endl;
          cout << "\033[1;34m###################################################\033[0m" << endl << endl;
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
    this_thread::sleep_for(chrono::milliseconds(800));
    if (game.score < 70.0) {
        cout << "============================================" << endl;
        cout << "============================================" << endl;
        cout << "You have failed the STU202 course." << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "Continue your journey to the next stage!!\n" << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        credit=4;
        gpa= 1.0;
    } else {
        cout << "============================================" << endl;
        cout << "============================================" << endl;
        cout << "You pass the STU202 course!" << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "4 credits gained by you." << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "Continue your journey to the next stage!!\n" << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        credit=4;
        gpa= 4.0;
    }
}
