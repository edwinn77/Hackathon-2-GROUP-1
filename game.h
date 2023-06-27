#ifndef GAME_H
#define GAME_H

#include <string>

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

int getInput(int, int);

#endif  // GAME_H

