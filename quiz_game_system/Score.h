#ifndef SCORE_H
#define SCORE_H

#include <iostream>
using namespace std;

class Score
{
private:
    int score;
    int totalQuestions;

public:
    // Constructors
    Score();

    // Functions
    void setTotalQuestions(int total);

    void incrementScore();

    int getScore() const;

    int getWrongAnswers() const;

    double getPercentage() const;

    void displayResult() const;

    void reset();
};

#endif