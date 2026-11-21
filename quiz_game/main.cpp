// main.cpp  -  Owner: Dharani (integration)
// main() decides the ORDER of the program. It does not contain the
// features; it calls the functions listed in quiz.h.

#include <chrono>
#include <iostream>
#include <string>
#include "quiz.h"
using namespace std;

// Helper used only in this file: reads a whole number between low and high.
int readNumberInRange(int low, int high) {
    int number = 0;
    while (true) {
        cin >> number;
        if (cin.fail()) {          // user typed letters instead of a number
            cin.clear();
            number = low - 1;
        }
        cin.ignore(1000, '\n');    // throw away the rest of the line
        if (number >= low && number <= high) {
            return number;
        }
        cout << "Please enter a number from " << low << " to " << high << ": ";
    }
}

int main() {
    char playAgain = 'y';

    cout << "=== QUIZ GAME ===\n";

    while (playAgain == 'y' || playAgain == 'Y') {

        // STEP 1: username (must be asked BEFORE the quiz starts)
        string username;
        cout << "\nEnter your username: ";
        getline(cin, username);
        while (username.empty()) {
            cout << "Username cannot be empty. Enter your username: ";
            getline(cin, username);
        }

        // STEP 2: category menu (data comes from Liezel's functions)
        int numberOfCategories = getNumberOfCategories();
        cout << "\nChoose a category:\n";
        for (int i = 1; i <= numberOfCategories; i++) {
            cout << i << ". " << getCategoryName(i) << "\n";
        }
        cout << "Your choice: ";
        int category = readNumberInRange(1, numberOfCategories);

        // STEP 3: how many questions to ask (never more than the bank has)
        int totalQuestions = QUESTIONS_PER_QUIZ;
        if (getQuestionCount(category) < totalQuestions) {
            totalQuestions = getQuestionCount(category);
        }

        // STEP 4: run the quiz -> returns the number of correct answers
        cout << "\nGood luck, " << username << "!\n\n";
        chrono::steady_clock::time_point quizStart = chrono::steady_clock::now();
        int correctAnswers = runQuiz(category, totalQuestions);
        chrono::steady_clock::time_point quizEnd = chrono::steady_clock::now();
        double durationSeconds = chrono::duration<double>(quizEnd - quizStart).count();

        // STEP 5: scoring (Paan) -> percent and grade come back
        int percent = calculatePercent(correctAnswers, totalQuestions);
        string grade = calculateGrade(percent);

        // Save one history record for this completed quiz. Export failure does
        // not interrupt the result, ranking, or replay flow.
        if (!saveQuizHistory(username, category, correctAnswers, totalQuestions,
                             percent, grade, durationSeconds)) {
            cout << "\nWarning: Could not save quiz history.\n";
        }

        // STEP 6: result summary (Paan prints it)
        cout << "\n=== RESULT ===\n";
        showResultSummary(username, correctAnswers, totalQuestions, percent, grade);

        // STEP 7: ranking (Dharani) -> results are kept separate by category
        cout << "\n=== " << getCategoryName(category) << " RANKING ===\n";
        saveAndShowRanking(username, percent, category);

        // STEP 8: play again?
        cout << "\nPlay again? (y/n): ";
        if (!(cin >> playAgain)) {
            playAgain = 'n';
        }
        cin.ignore(1000, '\n');
    }

    cout << "\nThanks for playing!\n";
    return 0;
}
