#include "Quiz.h"
#include <iostream>
#include <cctype>

using namespace std;

// Constructor
Quiz::Quiz()
{
    totalQuestions = 10;

    score.setTotalQuestions(totalQuestions);

    loadQuestions();
}

// Load all questions
void Quiz::loadQuestions()
{
    questions[0] = Question(
        "What is the capital of India?",
        "Hyderabad",
        "Delhi",
        "Mumbai",
        "Chennai",
        'B'
    );

    questions[1] = Question(
        "Which language is object oriented?",
        "HTML",
        "CSS",
        "C++",
        "SQL",
        'C'
    );

    questions[2] = Question(
        "2 + 2 = ?",
        "3",
        "4",
        "5",
        "6",
        'B'
    );

    questions[3] = Question(
        "Largest planet?",
        "Earth",
        "Mars",
        "Jupiter",
        "Venus",
        'C'
    );

    questions[4] = Question(
        "Who invented C++?",
        "James Gosling",
        "Dennis Ritchie",
        "Bjarne Stroustrup",
        "Guido van Rossum",
        'C'
    );

    questions[5] = Question(
        "Which is a loop?",
        "if",
        "switch",
        "for",
        "case",
        'C'
    );

    questions[6] = Question(
        "Which symbol ends a C++ statement?",
        ".",
        ",",
        ";",
        ":",
        'C'
    );

    questions[7] = Question(
        "Which keyword creates an object?",
        "new",
        "create",
        "object",
        "make",
        'A'
    );

    questions[8] = Question(
        "CPU stands for?",
        "Central Processing Unit",
        "Computer Processing Unit",
        "Central Program Unit",
        "Core Processing Unit",
        'A'
    );

    questions[9] = Question(
        "Which operator compares equality?",
        "=",
        "==",
        "!=",
        ">=",
        'B'
    );
}

// Ask one question
void Quiz::askQuestion(int index)
{
    char answer;

    questions[index].displayQuestion();

    cout << "Enter Answer (A/B/C/D): ";
    cin >> answer;

    answer = toupper(answer);

    checkAnswer(answer, index);
}

// Check answer
void Quiz::checkAnswer(char userAnswer, int index)
{
    if(userAnswer == questions[index].getCorrectAnswer())
    {
        cout << "Correct!\n";
        score.incrementScore();
    }
    else
    {
        cout << "Wrong!\n";
        cout << "Correct Answer : "
             << questions[index].getCorrectAnswer()
             << endl;
    }
}

// Start Quiz
void Quiz::startQuiz()
{
    cout << "\n========== QUIZ START ==========\n";

    for(int i = 0; i < totalQuestions; i++)
    {
        cout << "\nQuestion " << i + 1 << endl;

        askQuestion(i);
    }

    score.displayResult();
}