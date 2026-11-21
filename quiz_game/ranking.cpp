// ranking.cpp  -  Owner: Dharani (username-based ranking)
//
// Results are saved in a separate file for each category inside data/
// (for example, "data/leaderboard_category_1.txt"), so each ranking is
// still there the next time the program is started.
// File format, 2 lines per player:   percent
//                                    username

#include <iostream>
#include <fstream>
#include <string>
#include "quiz.h"
using namespace std;

const int MAX_PLAYERS = 100;              // the most results we keep in memory
const int HOW_MANY_TO_SHOW = 10;          // show the top 10

void saveAndShowRanking(string username, int percent, int category) {
    string rankingFile = "data/leaderboard_category_" + to_string(category) + ".txt";
    ofstream saveFile(rankingFile.c_str(), ios::app);
    if (saveFile) {
        saveFile << percent << "\n" << username << "\n";
        saveFile.close();
    } else {
        cout << "(Could not save to " << rankingFile << ")\n";
    }

    // 2. Read ALL saved results back into two arrays.
    string names[MAX_PLAYERS];
    int scores[MAX_PLAYERS];
    int count = 0;

    ifstream readFile(rankingFile.c_str());
    int savedPercent;
    string savedName;
    while (count < MAX_PLAYERS && readFile >> savedPercent) {
        readFile.ignore(1000, '\n');      // finish the "percent" line
        getline(readFile, savedName);     // the username line
        scores[count] = savedPercent;
        names[count] = savedName;
        count++;
    }
    readFile.close();

    // 3. Sort from highest percent to lowest (bubble sort).
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - 1 - i; j++) {
            if (scores[j] < scores[j + 1]) {
                int tempScore = scores[j];
                scores[j] = scores[j + 1];
                scores[j + 1] = tempScore;

                string tempName = names[j];
                names[j] = names[j + 1];
                names[j + 1] = tempName;
            }
        }
    }

    // 4. Print the top results.
    cout << "Rank  Username              Score\n";
    cout << "----------------------------------\n";
    int showCount = count;
    if (showCount > HOW_MANY_TO_SHOW) {
        showCount = HOW_MANY_TO_SHOW;
    }
    for (int i = 0; i < showCount; i++) {
        cout << (i + 1) << ".    " << names[i] << "   " << scores[i] << "%";
        if (names[i] == username) {
            cout << "   <-- you";
        }
        cout << "\n";
    }
}
