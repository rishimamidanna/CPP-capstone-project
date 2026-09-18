#include <iostream>
#include "Quiz.h"

using namespace std;

void welcomeScreen();
void instructions();
int mainMenu();

int main()
{
    int choice;

    do
    {
        welcomeScreen();

        choice = mainMenu();

        switch(choice)
        {
            case 1:
            {
                Quiz quiz;
                quiz.startQuiz();
                break;
            }

            case 2:
            {
                instructions();
                break;
            }

            case 3:
            {
                cout << "\nThank you for using Quiz Game System.\n";
                cout << "Goodbye!\n";
                break;
            }

            default:
            {
                cout << "\nInvalid Choice!\n";
            }
        }

        if(choice != 3)
        {
            cout << "\nPress Enter to continue...";
            cin.ignore();
            cin.get();
        }

    } while(choice != 3);

    return 0;
}

void welcomeScreen()
{
    cout << "\n=========================================\n";
    cout << "         QUIZ GAME SYSTEM\n";
    cout << "=========================================\n";
}

int mainMenu()
{
    int choice;

    cout << "\n1. Start Quiz\n";
    cout << "2. Instructions\n";
    cout << "3. Exit\n";

    cout << "\nEnter Choice : ";
    cin >> choice;

    return choice;
}

void instructions()
{
    cout << "\n========== INSTRUCTIONS ==========\n";

    cout << "1. There are 10 questions.\n";
    cout << "2. Each question has 4 options.\n";
    cout << "3. Enter A, B, C or D.\n";
    cout << "4. Correct Answer = 1 Mark.\n";
    cout << "5. No Negative Marking.\n";

    cout << "==================================\n";
}