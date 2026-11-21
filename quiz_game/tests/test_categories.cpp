// tests/test_categories.cpp  -  for LIEZEL
// This file has its own main(). It prints everything your functions return,
// so you can check your work WITHOUT anybody else's code.
#include <iostream>
#include "../quiz.h"
using namespace std;

int main() {
    int total = getNumberOfCategories();
    cout << "Number of categories: " << total << "\n";

    for (int c = 1; c <= total; c++) {
        cout << "\n===== Category " << c << ": " << getCategoryName(c) << " =====\n";
        int count = getQuestionCount(c);
        cout << "Questions in this category: " << count << "\n";

        for (int q = 1; q <= count; q++) {
            cout << "\n" << q << ") " << getQuestionText(c, q) << "\n";
            cout << "   A. " << getChoice(c, q, 1) << "\n";
            cout << "   B. " << getChoice(c, q, 2) << "\n";
            cout << "   C. " << getChoice(c, q, 3) << "\n";
            cout << "   D. " << getChoice(c, q, 4) << "\n";
            cout << "   Correct answer: " << getCorrectAnswer(c, q) << "\n";
        }
    }
    return 0;
}
