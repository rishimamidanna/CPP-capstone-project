#include "question.h"

// Default Constructor
Question::Question()
{
    question = "";
    optionA = "";
    optionB = "";
    optionC = "";
    optionD = "";
    correctAnswer = 'A';
}

// Parameterized Constructor
Question::Question(string q,
                   string a,
                   string b,
                   string c,
                   string d,
                   char ans)
{
    question = q;
    optionA = a;
    optionB = b;
    optionC = c;
    optionD = d;
    correctAnswer = ans;
}

// Setters

void Question::setQuestion(string q)
{
    question = q;
}

void Question::setOptionA(string a)
{
    optionA = a;
}

void Question::setOptionB(string b)
{
    optionB = b;
}

void Question::setOptionC(string c)
{
    optionC = c;
}

void Question::setOptionD(string d)
{
    optionD = d;
}

void Question::setCorrectAnswer(char ans)
{
    correctAnswer = toupper(ans);
}

// Getters

string Question::getQuestion() const
{
    return question;
}

string Question::getOptionA() const
{
    return optionA;
}

string Question::getOptionB() const
{
    return optionB;
}

string Question::getOptionC() const
{
    return optionC;
}

string Question::getOptionD() const
{
    return optionD;
}

char Question::getCorrectAnswer() const
{
    return correctAnswer;
}

// Display Question

void Question::displayQuestion() const
{
    cout << "\n---------------------------------\n";
    cout << question << endl;
    cout << "A. " << optionA << endl;
    cout << "B. " << optionB << endl;
    cout << "C. " << optionC << endl;
    cout << "D. " << optionD << endl;
    cout << "---------------------------------\n";
}