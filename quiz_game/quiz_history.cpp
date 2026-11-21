// quiz_history.cpp - CSV export for completed quiz sessions

#include <cerrno>
#include <cmath>
#include <ctime>
#include <fstream>
#include <iomanip>
#include <string>

#ifdef _WIN32
#include <direct.h>
#include <sys/stat.h>
#else
#include <sys/stat.h>
#include <sys/types.h>
#endif

#include "quiz.h"

namespace {

const char* const HISTORY_DIRECTORY = "data";
const char* const HISTORY_FILE = "data/quiz_history.csv";
const char* const CSV_HEADER =
    "timestamp,username,category,correct_answers,total_questions,percentage,grade,duration_seconds";

bool ensureHistoryDirectory() {
#ifdef _WIN32
    struct _stat directoryInfo;
    if (_stat(HISTORY_DIRECTORY, &directoryInfo) == 0) {
        return (directoryInfo.st_mode & _S_IFDIR) != 0;
    }
    if (_mkdir(HISTORY_DIRECTORY) == 0) {
        return true;
    }
    return errno == EEXIST && _stat(HISTORY_DIRECTORY, &directoryInfo) == 0
           && (directoryInfo.st_mode & _S_IFDIR) != 0;
#else
    struct stat directoryInfo;
    if (stat(HISTORY_DIRECTORY, &directoryInfo) == 0) {
        return S_ISDIR(directoryInfo.st_mode);
    }
    if (mkdir(HISTORY_DIRECTORY, 0755) == 0) {
        return true;
    }
    return errno == EEXIST && stat(HISTORY_DIRECTORY, &directoryInfo) == 0
           && S_ISDIR(directoryInfo.st_mode);
#endif
}

std::string escapeCsvField(const std::string& value) {
    bool needsQuotes = false;
    for (std::string::size_type i = 0; i < value.size(); ++i) {
        if (value[i] == ',' || value[i] == '"' || value[i] == '\n' || value[i] == '\r') {
            needsQuotes = true;
            break;
        }
    }

    if (!needsQuotes) {
        return value;
    }

    std::string escaped = "\"";
    for (std::string::size_type i = 0; i < value.size(); ++i) {
        if (value[i] == '"') {
            escaped += "\"\"";
        } else {
            escaped += value[i];
        }
    }
    escaped += '"';
    return escaped;
}

bool getLocalTimestamp(std::string& timestamp) {
    std::time_t now = std::time(NULL);
    if (now == static_cast<std::time_t>(-1)) {
        return false;
    }

    std::tm localTime;
#ifdef _WIN32
    if (localtime_s(&localTime, &now) != 0) {
        return false;
    }
#else
    if (localtime_r(&now, &localTime) == NULL) {
        return false;
    }
#endif

    char buffer[20];
    if (std::strftime(buffer, sizeof(buffer), "%Y-%m-%d %H:%M:%S", &localTime) == 0) {
        return false;
    }
    timestamp = buffer;
    return true;
}

void inspectHistoryFile(bool& writeHeader, bool& writeLeadingNewline) {
    writeHeader = true;
    writeLeadingNewline = false;

    std::ifstream existingFile(HISTORY_FILE, std::ios::binary | std::ios::ate);
    if (!existingFile) {
        return;
    }

    std::streampos size = existingFile.tellg();
    if (size <= std::streampos(0)) {
        return;
    }

    writeHeader = false;
    existingFile.seekg(-1, std::ios::end);
    char lastCharacter = '\0';
    existingFile.get(lastCharacter);
    writeLeadingNewline = lastCharacter != '\n' && lastCharacter != '\r';
}

} // namespace

bool saveQuizHistory(const std::string& username, int category, int correctAnswers,
                     int totalQuestions, int percent, const std::string& grade,
                     double durationSeconds) {
    if (!std::isfinite(durationSeconds) || durationSeconds < 0.0) {
        return false;
    }

    if (!ensureHistoryDirectory()) {
        return false;
    }

    std::string timestamp;
    if (!getLocalTimestamp(timestamp)) {
        return false;
    }

    bool writeHeader = false;
    bool writeLeadingNewline = false;
    inspectHistoryFile(writeHeader, writeLeadingNewline);
    std::ofstream historyFile(HISTORY_FILE, std::ios::out | std::ios::app | std::ios::binary);
    if (!historyFile) {
        return false;
    }

    if (writeHeader) {
        historyFile << CSV_HEADER << '\n';
    } else if (writeLeadingNewline) {
        historyFile << '\n';
    }

    historyFile << escapeCsvField(timestamp) << ','
                << escapeCsvField(username) << ','
                << category << ','
                << correctAnswers << ','
                << totalQuestions << ','
                << percent << ','
                << escapeCsvField(grade) << ','
                << std::fixed << std::setprecision(3) << durationSeconds << '\n';
    historyFile.flush();
    return historyFile.good();
}
