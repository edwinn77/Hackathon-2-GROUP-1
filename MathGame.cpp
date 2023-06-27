#include "MathGame.h"
#include "game.h"

#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <iostream>

using namespace std;

MathGame::MathGame(int numQuestions, int maxNumber, int timeLimitSeconds)
    : score(0), numQuestions(numQuestions), maxNumber(maxNumber), timeLimitSeconds(timeLimitSeconds) {}

void playMathGame(int& credit, double& gpa) {
	MathGame gameM;
	srand(time(0));
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "Welcome to the Math School!" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "As a mathematics student, mastering numbers and mental" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "calculation is fundamental. It not only hones your quick thinking skills but also keeps your" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "mind constantly engaged, greatly enhancing memory and logical thinking abilities. Get " << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "ready to embark on a journey of rapid mental calculations and sharpen your mathematical " << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "prowess at the Math School!" << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << endl;
	cout << "**************************************************************************" << endl;
    cout << "**************************************************************************" << endl;
    cout << endl;

    cout << "Press any key to continue...";
    cin.ignore(); // Ignore the input buffer
    cin.get();

    cout<< endl;
    cout << "Answer the following math questions to earn points." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "You will be asked " << gameM.numQuestions << " questions." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));
    cout << "You have " << gameM.timeLimitSeconds << " seconds to answer each question." << endl;
    this_thread::sleep_for(chrono::milliseconds(800));

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
    this_thread::sleep_for(chrono::milliseconds(700));
    cout << "Your score: " << gameM.score << "/50" << endl;
    this_thread::sleep_for(chrono::milliseconds(500));
    if (gameM.score < 30.0) {
    	cout << "============================================" << endl;
    	cout << "============================================" << endl;
        cout << "You have failed the MAA100 course." << endl;
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "Continue your journey to the next stage!\n" << endl;
        credit= 4;
        gpa= 1.0;
    	this_thread::sleep_for(chrono::milliseconds(800));
    } else {
    	cout << "============================================" << endl;
    	cout << "============================================" << endl;
        cout << "You pass the MAA100 course!" << endl;
    	this_thread::sleep_for(chrono::milliseconds(800));
    	cout << "4 credits gained by you." << endl;
    	this_thread::sleep_for(chrono::milliseconds(800));
    	cout << "Continue your journey to the next stage!!\n" << endl;
    	this_thread::sleep_for(chrono::milliseconds(800));
    	credit= 4;
        gpa= 4.0;
    }
}
