// timer.cpp  -  Owner: Pawe (live countdown + reading the answer)
//
// The live countdown idea and most of this code is Pawe's (timer_test.cpp).
// Adapted by Dharani to fit the shared quiz.h:
//   1. optional<char> became a plain char: it returns 'X' when time runs out.
//   2. main() was removed (main.cpp has the only main()).
//   3. Windows-only parts (conio.h, Sleep) are inside #ifdef _WIN32, with a
//      simple fallback so the project still builds on Mac/Linux.

#include <iostream>
#include <string>
#include <chrono>
#include <cctype>
#include "quiz.h"
using namespace std;

#ifdef _WIN32
#include <conio.h>      // _kbhit() and _getch(): read a key WITHOUT pressing Enter
#include <windows.h>    // Sleep()
#endif

char getTimedAnswer(int seconds) {
    using Clock = chrono::steady_clock;

#ifdef _WIN32
    // ---------- Windows: live countdown ----------
    Clock::time_point deadline = Clock::now() + chrono::seconds(seconds);
    int lastDisplayed = -1;

    while (Clock::now() < deadline) {
        int remaining = static_cast<int>(
            (chrono::duration_cast<chrono::milliseconds>(deadline - Clock::now()).count() + 999) / 1000);

        if (remaining != lastDisplayed) {
            cout << "\rTime remaining: " << remaining << " seconds   " << flush;
            lastDisplayed = remaining;
        }

        // Check the keyboard without waiting
        if (_kbhit()) {
            int key = _getch();

            if (key == 0 || key == 224) {      // arrow keys etc: ignore
                _getch();
                continue;
            }

            char answer = static_cast<char>(toupper(static_cast<unsigned char>(key)));
            if (answer >= 'A' && answer <= 'D') {
                if (Clock::now() >= deadline) {
                    break;
                }
                cout << "\nYour answer: " << answer << "\n";
                return answer;
            }
        }

        Sleep(25);      // short pause so the program does not use 100% CPU
    }

    cout << "\nTIME'S UP!\n";
    return 'X';

#else
    // ---------- Mac / Linux: no live countdown, type a letter + Enter ----------
    cout << "Time limit: " << seconds << " seconds (no live countdown on this system)\n";
    Clock::time_point start = Clock::now();
    string line;
    while (true) {
        cout << "Your answer (A/B/C/D): ";
        if (!getline(cin, line)) {
            return 'X';
        }
        if (!line.empty()) {
            char letter = static_cast<char>(toupper(static_cast<unsigned char>(line[0])));
            if (letter >= 'A' && letter <= 'D') {
                long used = chrono::duration_cast<chrono::seconds>(Clock::now() - start).count();
                if (used >= seconds) {
                    cout << "TIME'S UP!\n";
                    return 'X';
                }
                return letter;
            }
        }
        cout << "Please type only A, B, C or D.\n";
    }
#endif
}
