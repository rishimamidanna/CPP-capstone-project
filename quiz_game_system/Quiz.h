#ifndef QUIZ_H
#define QUIZ_H

#include "question.h"
#include "Score.h"

class Quiz
{
private:
    Question questions[10];
    int totalQuestions;
    Score score;

public:
    Quiz();

    void loadQuestions();

    void startQuiz();

    void askQuestion(int index);

    void checkAnswer(char userAnswer, int index);
};

#endif