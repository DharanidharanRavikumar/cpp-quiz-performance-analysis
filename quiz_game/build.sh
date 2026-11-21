#!/usr/bin/env sh
set -e

cd "$(dirname "$0")"
mkdir -p data

g++ -Wall -std=c++11 main.cpp quiz_core.cpp ranking.cpp categories.cpp random_questions.cpp timer.cpp scoring.cpp quiz_history.cpp -o quiz
./quiz
