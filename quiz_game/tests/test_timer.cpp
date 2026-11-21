// tests/test_timer.cpp  -  for PAWE
// Checks getTimedAnswer on its own. No other teammate's code needed.
#include <iostream>
#include "../quiz.h"
using namespace std;

int main() {
    cout << "Question: Which language are we using?  A. Python  B. C++  C. Java  D. HTML\n";
    cout << "Press A, B, C or D within 10 seconds.\n";
    char answer = getTimedAnswer(10);
    if (answer == 'X') {
        cout << "Result: no answer in time (X)\n";
    } else {
        cout << "Result: you answered " << answer << "\n";
    }
    return 0;
}
