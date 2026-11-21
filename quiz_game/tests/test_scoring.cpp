// tests/test_scoring.cpp  -  for PAAN
// Checks your three functions on their own. No other teammate's code needed.
#include <iostream>
#include "../quiz.h"
using namespace std;

int main() {
    cout << "--- calculatePercent ---\n";
    cout << "7 out of 10  -> " << calculatePercent(7, 10)  << "   (expected 70)\n";
    cout << "10 out of 10 -> " << calculatePercent(10, 10) << "   (expected 100)\n";
    cout << "0 out of 10  -> " << calculatePercent(0, 10)  << "   (expected 0)\n";
    cout << "5 out of 0   -> " << calculatePercent(5, 0)   << "   (expected 0, must not crash)\n";

    cout << "\n--- calculateGrade ---\n";
    int tests[] = {100, 95, 90, 85, 80, 75, 70, 60, 50, 0};
    for (int i = 0; i < 10; i++) {
        cout << tests[i] << "% -> " << calculateGrade(tests[i]) << "\n";
    }

    cout << "\n--- showResultSummary ---\n";
    showResultSummary("TestUser", 7, 10, 70, "B");
    return 0;
}
