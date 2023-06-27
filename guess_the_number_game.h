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
