#ifndef MATH_GAME_H
#define MATH_GAME_H

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
