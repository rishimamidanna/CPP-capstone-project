#include <iostream>
// Quiz Game System: module review edition
// Based on https://github.com/rishimamidanna/C-project
// Six menu operations share one quiz attempt. Compile this file on its own.
// Question and Score use the same quiz rules with simpler text storage.
// Uses only iostream. Fixed question text refers to string literals.
// The review interface adds staged execution, input checks and screenshot pauses.




using namespace std;

class Question
{
private:
    const char* question;
    const char* optionA;
    const char* optionB;
    const char* optionC;
    const char* optionD;
    char correctAnswer;

public:
    // Default Constructor
    Question();

    // Parameterized Constructor
    Question(const char* q,
             const char* a,
             const char* b,
             const char* c,
             const char* d,
             char ans);

    // Setters
    void setQuestion(const char* q);
    void setOptionA(const char* a);
    void setOptionB(const char* b);
    void setOptionC(const char* c);
    void setOptionD(const char* d);
    void setCorrectAnswer(char ans);

    // Getters
    const char* getQuestion() const;
    const char* getOptionA() const;
    const char* getOptionB() const;
    const char* getOptionC() const;
    const char* getOptionD() const;
    char getCorrectAnswer() const;

    // Display Question
    void displayQuestion() const;
};



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
Question::Question(const char* q,
                   const char* a,
                   const char* b,
                   const char* c,
                   const char* d,
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

void Question::setQuestion(const char* q)
{
    question = q;
}

void Question::setOptionA(const char* a)
{
    optionA = a;
}

void Question::setOptionB(const char* b)
{
    optionB = b;
}

void Question::setOptionC(const char* c)
{
    optionC = c;
}

void Question::setOptionD(const char* d)
{
    optionD = d;
}

void Question::setCorrectAnswer(char ans)
{
    correctAnswer = (ans >= 'a' && ans <= 'd') ? ans - 'a' + 'A' : ans;
}

// Getters

const char* Question::getQuestion() const
{
    return question;
}

const char* Question::getOptionA() const
{
    return optionA;
}

const char* Question::getOptionB() const
{
    return optionB;
}

const char* Question::getOptionC() const
{
    return optionC;
}

const char* Question::getOptionD() const
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



// Read one line into a fixed character array.
const char* readLine()
{
    static char line[100];
    while (true) {
        if (cin.getline(line, 100)) return line;
        if (cin.eof()) throw "Input closed.";
        cin.clear();
        char ch;
        while (cin.get(ch) && ch != '\n') {}
        cout << "Input is too long. Please enter a shorter value: ";
    }
}

bool isSpace(char ch)
{
    return ch == ' ' || ch == '\t' || ch == '\r';
}

// Validate a whole line so entries such as 2abc are rejected.
int readNumber(const char* prompt, int minimum, int maximum)
{
    while (true) {
        cout << prompt;
        const char* line = readLine();
        int i = 0;
        while (isSpace(line[i])) ++i;
        int number = 0;
        bool hasDigit = false;
        bool valid = true;
        while (line[i] >= '0' && line[i] <= '9') {
            hasDigit = true;
            // Stop accumulating once the allowed range is exceeded.
            if (number <= maximum) number = number * 10 + (line[i] - '0');
            if (number > maximum) valid = false;
            ++i;
        }
        while (isSpace(line[i])) ++i;
        if (hasDigit && valid && line[i] == '\0' && number >= minimum)
            return number;
        cout << "Enter a number from " << minimum << " to " << maximum << ".\n";
    }
}

char readAnswer()
{
    while (true) {
        cout << "Enter Answer (A/B/C/D): ";
        const char* line = readLine();
        int i = 0;
        while (isSpace(line[i])) ++i;
        char answer = line[i];
        if (answer != '\0') ++i;
        while (isSpace(line[i])) ++i;
        if (answer >= 'a' && answer <= 'd') answer = answer - 'a' + 'A';
        if (line[i] == '\0' && answer >= 'A' && answer <= 'D') return answer;
        cout << "Please enter A, B, C or D.\n";
    }
}

void heading(const char* title)
{
    cout << "\n============================================================\n";
    cout << title << '\n';
    cout << "============================================================\n";
}

class QuizReview
{
private:
    static constexpr int totalQuestions = 10;
    Question questions[totalQuestions];
    char answers[totalQuestions]{};
    Score score;
    bool attempted = false;
    bool evaluated = false;

    void loadQuestions();

    bool requireEvaluation() const
    {
        if (!evaluated) {
            cout << "Complete Module 3, then Module 4 first.\n";
            return false;
        }
        return true;
    }

public:
    QuizReview()
    {
        score.setTotalQuestions(totalQuestions);
        loadQuestions();
    }

    void module1Instructions() const
    {
        heading("MODULE 1: QUIZ INSTRUCTIONS");
        cout << "1. There are 10 questions.\n"
             << "2. Each question has 4 options.\n"
             << "3. Enter A, B, C or D.\n"
             << "4. Correct Answer = 1 Mark.\n"
             << "5. No Negative Marking.\n\n"
             << "Review sequence:\n"
             << "Module 2: Display all questions.\n"
             << "Module 3: Answer all 10 questions.\n"
             << "Module 4: Check the submitted answers.\n"
             << "Module 5: View the score calculation.\n"
             << "Module 6: Display the final result and grade.\n";
    }

    void module2Questions() const
    {
        heading("MODULE 2: QUESTION DISPLAY");
        cout << "All questions in the quiz:\n";
        for (int i = 0; i < totalQuestions; ++i)
        {
            cout << "\nQuestion " << i + 1 << " of " << totalQuestions << '\n';
            questions[i].displayQuestion();
        }
        cout << "\nAll questions displayed.\n";
    }

    void module3Attempt()
    {
        heading("MODULE 3: QUIZ ATTEMPT");
        if (attempted) {
            int replace = readNumber("Replace the current attempt? (1 = Yes, 0 = No): ", 0, 1);
            if (!replace) return;
        }
        attempted = false;
        evaluated = false;
        score.reset();
        for (int i = 0; i < totalQuestions; ++i) {
            cout << "\nQuestion " << i + 1 << " of " << totalQuestions << '\n';
            questions[i].displayQuestion();
            answers[i] = readAnswer();
        }
        attempted = true;
        heading("MODULE 3: ANSWERS SUBMITTED");
        cout << "Question    Your answer\n";
        for (int i = 0; i < totalQuestions; ++i)
            cout << i + 1 << "           " << answers[i] << '\n';
        cout << "\n10 answers stored for this session.\n"
             << "Choose Module 4 to evaluate them.\n";
    }

    void module4Check()
    {
        heading("MODULE 4: ANSWER CHECKING");
        if (!attempted) {
            cout << "Complete Module 3 first to submit your answers.\n";
            return;
        }
        score.reset();
        cout << "Question   Your answer   Correct   Status\n";
        cout << "------------------------------------------------------------\n";
        for (int i = 0; i < totalQuestions; ++i) {
            bool correct = answers[i] == questions[i].getCorrectAnswer();
            if (correct) score.incrementScore();
            cout << i + 1 << (i == 9 ? "         " : "          ") << answers[i]
                 << "             " << questions[i].getCorrectAnswer() << "         "
                 << (correct ? "Correct" : "Wrong") << '\n';
        }
        evaluated = true;
        cout << "\nEvaluation complete. Choose Module 5 for the calculation.\n";
    }

    void module5Score() const
    {
        heading("MODULE 5: SCORE CALCULATION");
        if (!requireEvaluation()) return;
        cout << "Total questions : " << totalQuestions << '\n'
             << "Correct answers : " << score.getScore() << '\n'
             << "Wrong answers   : " << score.getWrongAnswers() << '\n'
             << "\nScore = correct answers x 1\n"
             << "      = " << score.getScore() << " x 1 = " << score.getScore() << " marks\n"
             << "\nPercentage = (score / total questions) x 100\n"
             << "           = (" << score.getScore() << " / " << totalQuestions
             << ") x 100 = " << score.getPercentage() << "%\n";
    }

    void module6Result() const
    {
        heading("MODULE 6: FINAL RESULT AND GRADE");
        if (!requireEvaluation()) return;
        score.displayResult();
    }

    void run()
    {
        while (true) {
            heading("QUIZ GAME SYSTEM - MODULE MENU");
            cout << "1. Module 1: Quiz Instructions\n"
                 << "2. Module 2: Question Display\n"
                 << "3. Module 3: Quiz Attempt\n"
                 << "4. Module 4: Answer Checking\n"
                 << "5. Module 5: Score Calculation\n"
                 << "6. Module 6: Final Result and Grade\n"
                 << "0. Exit\n\n";
            int choice = readNumber("Enter your choice (0-6): ", 0, 6);
            switch (choice) {
                case 1: module1Instructions(); break;
                case 2: module2Questions(); break;
                case 3: module3Attempt(); break;
                case 4: module4Check(); break;
                case 5: module5Score(); break;
                case 6: module6Result(); break;
                case 0: cout << "\nThank you for using Quiz Game System.\n"; return;
            }
            cout << "\nPress Enter to return to the module menu...";
            readLine();
        }
    }
};


void QuizReview::loadQuestions()
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




int main()
{
    try {
        QuizReview quiz;
        quiz.run();
    } catch (const char* error) {
        cout << "\n" << error << '\n';
    }
    return 0;
}
