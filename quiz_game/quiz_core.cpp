// quiz_core.cpp  -  Owner: Dharani (baseline multiple-choice quiz)
//
// runQuiz() asks the questions one by one and counts the correct answers.
// It does NOT store any questions itself. It asks the other files:
//   Fah    -> which questions to ask (random)
//   Liezel -> the question text, the 4 choices, the correct letter
//   Pawe   -> the live countdown and the player's answer

#include <iostream>
#include "quiz.h"
using namespace std;

int runQuiz(int category, int numberOfQuestions) {
    int correct = 0;

    // 1. Fah chooses which questions will be asked this time.
    pickRandomQuestions(getQuestionCount(category), numberOfQuestions);

    // 2. Ask the questions one by one.
    for (int position = 1; position <= numberOfQuestions; position++) {

        int questionNumber = getPickedQuestion(position);

        // Show the question and its 4 choices (Liezel's functions).
        cout << "Question " << position << " of " << numberOfQuestions << ":\n";
        cout << getQuestionText(category, questionNumber) << "\n";
        cout << "  A. " << getChoice(category, questionNumber, 1) << "\n";
        cout << "  B. " << getChoice(category, questionNumber, 2) << "\n";
        cout << "  C. " << getChoice(category, questionNumber, 3) << "\n";
        cout << "  D. " << getChoice(category, questionNumber, 4) << "\n";
        cout << "Choose A, B, C or D. You have " << SECONDS_PER_QUESTION << " seconds.\n";

        // Pawe's function shows the countdown and returns 'A'-'D', or 'X' if time ran out.
        char answer = getTimedAnswer(SECONDS_PER_QUESTION);
        char rightAnswer = getCorrectAnswer(category, questionNumber);

        if (answer == 'X') {
            cout << "No answer in time. The correct answer was " << rightAnswer << ".\n";
        } else if (answer == rightAnswer) {
            cout << "Correct!\n";
            correct++;
        } else {
            cout << "Wrong. The correct answer was " << rightAnswer << ".\n";
        }
        cout << "\n";
    }

    // 3. Send the number of correct answers back to main.cpp.
    return correct;
}
