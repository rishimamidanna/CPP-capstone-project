#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>

using namespace std;

class Question
{
private:
    string question;
    string optionA;
    string optionB;
    string optionC;
    string optionD;
    char correctAnswer;

public:
    // Default Constructor
    Question();

    // Parameterized Constructor
    Question(string q,
             string a,
             string b,
             string c,
             string d,
             char ans);

    // Setters
    void setQuestion(string q);
    void setOptionA(string a);
    void setOptionB(string b);
    void setOptionC(string c);
    void setOptionD(string d);
    void setCorrectAnswer(char ans);

    // Getters
    string getQuestion() const;
    string getOptionA() const;
    string getOptionB() const;
    string getOptionC() const;
    string getOptionD() const;
    char getCorrectAnswer() const;

    // Display Question
    void displayQuestion() const;
};

#endif