#include "Score.h"

// Constructor
Score::Score()
{
    score = 0;
    totalQuestions = 0;
}

// Set total number of questions
void Score::setTotalQuestions(int total)
{
    totalQuestions = total;
}

// Increase score
void Score::incrementScore()
{
    score++;
}

// Return score
int Score::getScore() const
{
    return score;
}

// Return wrong answers
int Score::getWrongAnswers() const
{
    return totalQuestions - score;
}

// Calculate percentage
double Score::getPercentage() const
{
    if(totalQuestions == 0)
        return 0;

    return (score * 100.0) / totalQuestions;
}

// Display result
void Score::displayResult() const
{
    cout << "\n=====================================\n";
    cout << "          QUIZ RESULT\n";
    cout << "=====================================\n";

    cout << "Correct Answers : " << score << endl;
    cout << "Wrong Answers   : " << getWrongAnswers() << endl;
    cout << "Percentage      : " << getPercentage() << "%" << endl;

    if(getPercentage() >= 90)
        cout << "Grade : Excellent" << endl;
    else if(getPercentage() >= 75)
        cout << "Grade : Very Good" << endl;
    else if(getPercentage() >= 50)
        cout << "Grade : Good" << endl;
    else
        cout << "Grade : Needs Improvement" << endl;

    cout << "=====================================\n";
}

// Reset score
void Score::reset()
{
    score = 0;
}