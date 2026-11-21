// random_questions.cpp  -  Owner: Fah (random question generator)
// Keep every function name, parameter and return type EXACTLY as in quiz.h.

#include <cstdlib>
#include <ctime>
#include "quiz.h"
using namespace std;

// Stores the selected question numbers between the two public functions.
int picked[100];
void pickRandomQuestions(int totalQuestions, int howManyToPick)
{
    // Choose unique question numbers and remember them for getPickedQuestion().
    static bool seeded = false;
    if (!seeded)
    {
        srand(time(0));
        seeded = true;
    }

    // Prevent invalid input and array overflow
    if (totalQuestions <= 0 || howManyToPick <= 0)
    {
        return;
    }

    if (totalQuestions > 100)
    {
        totalQuestions = 100;
    }

    if (howManyToPick > totalQuestions)
    {
        howManyToPick = totalQuestions;
    }

    int pickedCount = 0;

    while (pickedCount < howManyToPick)
    {
        int number = rand() % totalQuestions + 1;
        bool alreadyPicked = false;

        for (int i = 0; i < pickedCount; i++)
        {
            if (picked[i] == number)
            {
                alreadyPicked = true;
                break;
            }
        }

        if (!alreadyPicked)
        {
            picked[pickedCount] = number;
            pickedCount++;
        }
    }
}

int getPickedQuestion(int position)
{
    // position is 1-based; the array is 0-based.
    return picked[position - 1];
}
