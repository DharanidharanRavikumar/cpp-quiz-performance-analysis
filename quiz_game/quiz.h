// quiz.h  -  SHARED HEADER (owner: Dharani)
//
// RULE: Only Dharani edits this file. If you need a different input or
// return value, ask Dharani first. Everyone must keep these signatures
// EXACTLY the same in their own .cpp file.
//
// How it works: this file only ANNOUNCES the functions (name, inputs, return
// type). The real code lives in the .cpp files. Any .cpp file that writes
// #include "quiz.h" is allowed to call every function listed here.

#ifndef QUIZ_H
#define QUIZ_H

#include <string>
using namespace std;

// ---------- Shared settings (change the number here, nowhere else) ----------
const int QUESTIONS_PER_QUIZ   = 10;  // questions asked in one quiz (e.g. 10 out of 20)
const int SECONDS_PER_QUESTION = 30;  // time limit for ONE question

// =====================================================================
//  LIEZEL  -> categories.cpp   (categories + the question bank itself)
//  Questions, choices and answers are numbered starting from 1.
//  Choice numbers: 1 = A, 2 = B, 3 = C, 4 = D.
// =====================================================================

// Receives: nothing.
// Does:     nothing except report the number of categories.
// Returns:  how many categories exist (e.g. 2).
// main.cpp: uses it to print the category menu.
int getNumberOfCategories();

// Receives: category = category number (1 .. getNumberOfCategories()).
// Returns:  the category's name, e.g. "Quiz 1".
// main.cpp: prints it in the category menu.
string getCategoryName(int category);

// Receives: category = category number.
// Returns:  how many questions are in that category's bank (e.g. 20).
// main.cpp / quiz_core.cpp: use it to know how many questions exist.
int getQuestionCount(int category);

// Receives: category, questionNumber (1 .. getQuestionCount(category)).
// Returns:  the question text.
// quiz_core.cpp: prints it.
string getQuestionText(int category, int questionNumber);

// Receives: category, questionNumber, choiceNumber (1 to 4).
// Returns:  the text of that choice.
// quiz_core.cpp: prints it next to A / B / C / D.
string getChoice(int category, int questionNumber, int choiceNumber);

// Receives: category, questionNumber.
// Returns:  the correct answer as a capital letter: 'A', 'B', 'C' or 'D'.
// quiz_core.cpp: compares it with the user's answer.
char getCorrectAnswer(int category, int questionNumber);

// =====================================================================
//  FAH  -> random_questions.cpp   (random question generator)
// =====================================================================

// Receives: totalQuestions = size of the bank (e.g. 20),
//           howManyToPick  = how many to choose (e.g. 10).
// Does:     randomly chooses question numbers, with NO duplicates, and
//           remembers them inside random_questions.cpp.
// Returns:  nothing.
// quiz_core.cpp: calls it ONCE at the start of each quiz.
void pickRandomQuestions(int totalQuestions, int howManyToPick);

// Receives: position = 1 .. howManyToPick (1st question asked, 2nd, ...).
// Returns:  the question number (1 .. totalQuestions) to ask at that position.
// quiz_core.cpp: calls it once per question in a loop.
int getPickedQuestion(int position);

// =====================================================================
//  PAWE  -> timer.cpp   (live countdown + reading the answer)
// =====================================================================

// Receives: seconds = time allowed for this question (we pass SECONDS_PER_QUESTION).
// Does:     shows a live countdown ("Time remaining: 24 seconds") while the
//           player presses A, B, C or D (no Enter needed on Windows).
// Returns:  the answer as a capital letter 'A', 'B', 'C' or 'D',
//           or 'X' if the time ran out (or there was no answer).
// quiz_core.cpp: calls it once per question. 'X' counts as a wrong answer.
char getTimedAnswer(int seconds);

// =====================================================================
//  PAAN  -> scoring.cpp   (scoring, grading, result summary)
// =====================================================================

// Receives: correctAnswers (the raw score), totalQuestions asked.
// Returns:  the score as a percentage, 0 .. 100.
// main.cpp: passes it to calculateGrade and to the ranking.
int calculatePercent(int correctAnswers, int totalQuestions);

// Receives: percent (0 .. 100).
// Returns:  the grade text: "A+", "A", "B", "C", ... (Paan + team decide the ranges).
// main.cpp: stores it and passes it to showResultSummary.
string calculateGrade(int percent);

// Receives: username, correctAnswers (raw score), totalQuestions,
//           percent, grade.
// Does:     prints the result summary (total score, percent, grade).
// Returns:  nothing.
// main.cpp: calls it after the quiz.
void showResultSummary(string username, int correctAnswers, int totalQuestions,
                       int percent, string grade);

// =====================================================================
//  DHARANI  -> quiz_core.cpp and ranking.cpp
// =====================================================================

// Receives: category = chosen category, numberOfQuestions = how many to ask.
// Does:     runs the whole multiple-choice quiz (uses Liezel's, Fah's and
//           Pawe's functions).
// Returns:  the number of correct answers (the raw score).
// main.cpp: stores it as correctAnswers.
int runQuiz(int category, int numberOfQuestions);

// Receives: username, percent (the player's score, 0 .. 100),
//           category = the category that was played.
// Does:     records this result and displays that category's ranking.
// Returns:  nothing.
// main.cpp: calls it last.
void saveAndShowRanking(string username, int percent, int category);

// =====================================================================
//  QUIZ HISTORY  -> quiz_history.cpp   (CSV session export)
// =====================================================================

// Receives: the completed quiz result and its elapsed duration.
// Does:     appends one record to data/quiz_history.csv.
// Returns:  true when the record was written successfully; false otherwise.
bool saveQuizHistory(const string& username, int category, int correctAnswers,
                     int totalQuestions, int percent, const string& grade,
                     double durationSeconds);

#endif
