// scoring.cpp  -  Owner: Paan (scoring, grading, result summary)
// Keep every function name, parameter and return type EXACTLY as in quiz.h.

#include <iostream>
#include "quiz.h"
using namespace std;

int calculatePercent(int correctAnswers, int totalQuestions) {
    if (totalQuestions <= 0) {
        return 0;
    }
    return correctAnswers * 100 / totalQuestions;
}

string calculateGrade(int percent) {
    if (percent >= 90) {
        return "A+";
    } else if (percent >= 80) {
        return "A";
    } else if (percent >= 70) {
        return "B";
    } else if (percent >= 60) {
        return "C";
    } else if (percent >= 50) {
        return "D";
    }
    return "F";
}

void showResultSummary(string username, int correctAnswers, int totalQuestions,
                       int percent, string grade) {
    cout << "Player:  " << username << endl;
    cout << "Score:   " << correctAnswers << " / " << totalQuestions << endl;
    cout << "Percent: " << percent << "%" << endl;
    cout << "Grade:   " << grade << endl;
}