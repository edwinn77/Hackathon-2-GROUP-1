#include "game.h"

#include <iostream>
#include <limits>

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

