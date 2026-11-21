// tests/test_random.cpp  -  for FAH
// Checks your two functions on their own. No other teammate's code needed.
#include <iostream>
#include "../quiz.h"
using namespace std;

// Picks 'howMany' questions out of 'total', prints them and checks them.
void runCheck(int total, int howMany) {
    cout << "Picking " << howMany << " questions out of " << total << ":\n";
    pickRandomQuestions(total, howMany);

    bool allGood = true;
    for (int pos = 1; pos <= howMany; pos++) {
        int q = getPickedQuestion(pos);
        cout << q << " ";

        if (q < 1 || q > total) {
            allGood = false;                       // outside 1..total
        }
        for (int earlier = 1; earlier < pos; earlier++) {
            if (getPickedQuestion(earlier) == q) {
                allGood = false;                   // the same number twice
            }
        }
    }
    cout << "\n";
    if (allGood) {
        cout << "OK: all numbers are between 1 and " << total << " and none repeat.\n\n";
    } else {
        cout << "PROBLEM: a number is out of range or repeated!\n\n";
    }
}

int main() {
    runCheck(20, 10);
    runCheck(5, 5);     // must contain 1,2,3,4,5 in any order
    cout << "Now run this program AGAIN (wait 2 seconds first).\n";
    cout << "The first line of numbers should look different.\n";
    return 0;
}
