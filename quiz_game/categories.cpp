// categories.cpp  -  Owner: Liezel (categories + question bank)
// Keep every function name, parameter and return type EXACTLY as in quiz.h.
// Hint: simple if / else if or switch statements are enough. No arrays required.

#include <string>
#include "quiz.h"
using namespace std;

int getNumberOfCategories() {
    return 2;
}

string getCategoryName(int category) {
    if (category == 1) {
        return "Quiz 1";
    }
    if (category == 2) {
        return "Quiz 2";
    }
    return "Unknown category";
}

int getQuestionCount(int category) {
    if (category == 1) {
        return 18;
    }
    if (category == 2) {
        return 10;
    }
    return 0;
}

string getQuestionText(int category, int questionNumber) {
    
    // Quiz 1
    if (category == 1 && questionNumber == 1) {
        return "Who invented the C programming language in 1972?";
    }
    if (category == 1 && questionNumber == 2) {
        return "What is the most preferred programming language between 1895 to 1990?";
    }
    if (category == 1 && questionNumber == 3) {
        return "What is the most preferred programming language in 2020?";
    }
    if (category == 1 && questionNumber == 4) {
        return "Which of the following describes a parameter of C++ programming language?";
    }
    if (category == 1 && questionNumber == 5) {
        return "A student writes a C program using standard language features and libraries.\nThe same source code compiles and runs on Windows and Linux with little or\nno modification.Which feature is demonstrated?";
    }
    if (category == 1 && questionNumber == 6) {
        return "An engineer uses C to express calculations with functions and loops\nwhile also accessing memory through pointers and manipulating individual bits.\nWhich feature combines these capabilities?";
    }
    if (category == 1 && questionNumber == 7) {
        return "A program learns during execution how many records it must store.\nThe programmer uses malloc() to allocate enough space and\nfree() to release that space when it is no longer needed.\nWhich feature is demonstrated?";
    }
    if (category == 1 && questionNumber == 8) {
        return "What is the first operating system designed using the C language?";
    }
    if (category == 1 && questionNumber == 9) {
        return "The following are advantages of the C programming language EXCEPT?";
    }
    if (category == 1 && questionNumber == 10) {
        return "A programmer develops a C program that attempts to divide a number by zero.\nUnlike some other programming languages,C does not provide built-in\ntry-catch statements to handle such errors.\nWhich disadvantage of C programming is described in this situation?";
    }
    if (category == 1 && questionNumber == 11) {
        return "A beginner wants to learn a programming language that uses\ninstructions that are relatively easy for humans to read, write, and understand.\nWhich type of programming language best meets this description?";
    }
    if (category == 1 && questionNumber == 12) {
        return "A programmer is developing a student grading system in C.\nThe program needs to store a student's letter grade,\nsuch as 'A', 'B', or 'C', in a variable.\nWhich C data type is most appropriate?";
    }
    if (category == 1 && questionNumber == 13) {
        return "Coding consists of these three components per line in C Basic EXCEPT?";
    }
    if (category == 1 && questionNumber == 14) {
        return "It is used to recall where an object is stored in memory.";
    }
    if (category == 1 && questionNumber == 15) {
        return "The following are basic instructions of programming language EXCEPT?";
    }
    if (category == 1 && questionNumber == 16) {
        return "It refers to a low-level programming language made up of binary digits ones and zeros.";
    }
    if (category == 1 && questionNumber == 17) {
        return "The following are used in developing a C program EXCEPT?";
    }
    if (category == 1 && questionNumber == 18) {
        return "A programmer discovers that a program produces an incorrect result.\nBecause the high-level language uses understandable statements and structures,\nthe programmer can locate and correct the error more easily.\nWhich advantage is illustrated?";
    }

    // Quiz 2
    if (category == 2 && questionNumber == 1) {
        return "HTML stands for?";
    }
    if (category == 2 && questionNumber == 2) {
        return "It refers to a word processor that has been specialized to make the writing of HTML code easier and faster.";
    }
    if (category == 2 && questionNumber == 3) {
        return "It is a file or code-sharing service to collaborate with different people on a project.";
    }
    if (category == 2 && questionNumber == 4) {
        return "Webpages format are influenced by formats of";
    }
    if (category == 2 && questionNumber == 5) {
        return "It is a style guide for formatting whatever is to be printed in hardcopy or soft copy format.";
    }
    if (category == 2 && questionNumber == 6) {
        return "Which of the following is NOT a supporting feature of HTML5?";
    }
    if (category == 2 && questionNumber == 7) {
        return "Which of the following is NOT true about HTML5 attributes?";
    }
    if (category == 2 && questionNumber == 8) {
        return "It refers to an open-source and free to use text and code editor with a rich set of plug-ins for different functions.";
    }
    if (category == 2 && questionNumber == 9) {
        return "It describes the way in which Web pages are linked together and how users can navigate between them.";
    }
    if (category == 2 && questionNumber == 10) {
        return "Which of the following is TRUE?";
    }
    return "Invalid question";
}

string getChoice(int category, int questionNumber, int choiceNumber) {
    if (category == 1 && questionNumber == 1) {
        switch (choiceNumber) {
            case 1: return "Dennis Ritchie";
            case 2: return "James Gosling";
            case 3: return "Bjarne Stroustrup";
            case 4: return "Ken Thompson";
        }
    }
    if (category == 1 && questionNumber == 2) {
        switch (choiceNumber) {
            case 1: return "C";
            case 2: return "Ada";
            case 3: return "BASIC";
            case 4: return "FORTRAN";
        }
    }
    if (category == 1 && questionNumber == 3) {
        switch (choiceNumber) {
            case 1: return "Python";
            case 2: return "JavaScript";
            case 3: return "Java";
            case 4: return "C++";
        }
    }
    if (category == 1 && questionNumber == 4) {
        switch (choiceNumber) {
            case 1: return "Variables can be defined anywhere within the program";
            case 2: return "It is procedure oriented.";
            case 3: return "It has complicated mapping";
            case 4: return "It does not support templates.";
        }
    }
    if (category == 1 && questionNumber == 5) {
        switch (choiceNumber) {
            case 1: return "Modularity";
            case 2: return "Simple and portable";
            case 3: return "Built-in operations";
            case 4: return "Memory management";
        }
    }
    if (category == 1 && questionNumber == 6) {
        switch (choiceNumber) {
            case 1: return "Easy to extend";
            case 2: return "Middle language level";
            case 3: return "Rich library";
            case 4: return "Simple and portable";
        }
    }
    if (category == 1 && questionNumber == 7) {
        switch (choiceNumber) {
            case 1: return "Easy to extend";
            case 2: return "Middle language level";
            case 3: return "Modularity";
            case 4: return "Procedural language";
        }
    }
    if (category == 1 && questionNumber == 8) {
        switch (choiceNumber) {
            case 1: return "UNIX";
            case 2: return "Linux";
            case 3: return "Windows";
            case 4: return "macOS";
        }
    }
    if (category == 1 && questionNumber == 9) {
        switch (choiceNumber) {
            case 1: return "It has many libraries";
            case 2: return "It is easy to understand.";
            case 3: return "Its execution is fast";
            case 4: return "It is a low-level language";
        }
    }
    if (category == 1 && questionNumber == 10) {
        switch (choiceNumber) {
            case 1: return "Lack of runtime checking";
            case 2: return "No automatic garbage collection.";
            case 3: return "Lack of built-in exception handling";
            case 4: return "No support for modular programming";
        }
    }
    if (category == 1 && questionNumber == 11) {
        switch (choiceNumber) {
            case 1: return "Middle-level language";
            case 2: return "High-level language";
            case 3: return "Low-level language";
            case 4: return "Domain-specific language";
        }
    }
    if (category == 1 && questionNumber == 12) {
        switch (choiceNumber) {
            case 1: return "char";
            case 2: return "int";
            case 3: return "float";
            case 4: return "double";
        }
    }
    if (category == 1 && questionNumber == 13) {
        switch (choiceNumber) {
            case 1: return "Data type";
            case 2: return "Variable name";
            case 3: return "Statement";
            case 4: return "Value";
        }
    }
    if (category == 1 && questionNumber == 14) {
        switch (choiceNumber) {
            case 1: return "Function";
            case 2: return "Array";
            case 3: return "Memory allocation";
            case 4: return "Pointer";
        }
    }
    if (category == 1 && questionNumber == 15) {
        switch (choiceNumber) {
            case 1: return "Input";
            case 2: return "Output";
            case 3: return "Math";
            case 4: return "Replication";
        }
    }
    if (category == 1 && questionNumber == 16) {
        switch (choiceNumber) {
            case 1: return "Computer programming";
            case 2: return "Machine code";
            case 3: return "Assembly language";
            case 4: return "Domain-specific language";
        }
    }
    if (category == 1 && questionNumber == 17) {
        switch (choiceNumber) {
            case 1: return "Compiler";
            case 2: return "Assembler";
            case 3: return "Debugger";
            case 4: return "Editor";
        }
    }
    if (category == 1 && questionNumber == 18) {
        switch (choiceNumber) {
            case 1: return "Machine independence";
            case 2: return "Portability";
            case 3: return "Easy software development";
            case 4: return "Easy debugging";
        }
    }
    if (category == 2 && questionNumber == 1) {
        switch (choiceNumber) {
            case 1: return "Hyper Text Markup Language";
            case 2: return "Hyperlinks and Text Markup Language";
            case 3: return "Home Tool Markup Language";
            case 4: return "Hyperlinking Text Marking Language";
        }
    }
    if (category == 2 && questionNumber == 2) {
        switch (choiceNumber) {
            case 1: return "HTML debugger";
            case 2: return "HTML compiler";
            case 3: return "HTML interpreter";
            case 4: return "HTML editor";
        }
    }
    if (category == 2 && questionNumber == 3) {
        switch (choiceNumber) {
            case 1: return "Google Drive";
            case 2: return "GitHub";
            case 3: return "Dropbox";
            case 4: return "OneDrive";
        }
    }
    if (category == 2 && questionNumber == 4) {
        switch (choiceNumber) {
            case 1: return "Books";
            case 2: return "Nature";
            case 3: return "Newspaper";
            case 4: return "All of the choices";
        }
    }
    if (category == 2 && questionNumber == 5) {
        switch (choiceNumber) {
            case 1: return "Markup";
            case 2: return "Language";
            case 3: return "Hypertext";
            case 4: return "Bracket";
        }
    }
    if (category == 2 && questionNumber == 6) {
        switch (choiceNumber) {
            case 1: return "Uppercase tag names.";
            case 2: return "Quotes are required for attributes.";
            case 3: return "Attribute values are optional";
            case 4: return "Closing empty elements are optional.";
        }
    }
    if (category == 2 && questionNumber == 7) {
        switch (choiceNumber) {
            case 1: return "Align attribute horizontally aligns tags.";
            case 2: return "Context menu specifies if the user can edit the element's content or not.";
            case 3: return "Accesskey is a user defined attribute.";
            case 4: return "Class classified an element for use with Cascading StyleSheets.";
        }
    }
    if (category == 2 && questionNumber == 8) {
        switch (choiceNumber) {
            case 1: return "Visual Studio Code";
            case 2: return "Sublime Text";
            case 3: return "Atom";
            case 4: return "Brackets";
        }
    }
    if (category == 2 && questionNumber == 9) {
        switch (choiceNumber) {
            case 1: return "Hypereditor";
            case 2: return "Hyperlink";
            case 3: return "Hypermedia";
            case 4: return "Hypertext";
        }
    }
    if (category == 2 && questionNumber == 10) {
        switch (choiceNumber) {
            case 1: return "The two most essential tools for developing a website are a text editor and a web browser.";
            case 2: return "HTML makes it possible to organize and format documents, similarly to Microsoft Word.";
            case 3: return "A link relation is a relation between two files.";
            case 4: return "All of the statements are TRUE.";
        }
    }

    return "Invalid choice";
}

char getCorrectAnswer(int category, int questionNumber) {
    
    // Quiz 1
    if (category == 1 && questionNumber == 1) {
        return 'A';
    }
    if (category == 1 && questionNumber == 2) {
        return 'B';
    }
    if (category == 1 && questionNumber == 3) {
        return 'D';
    }
    if (category == 1 && questionNumber == 4) {
        return 'A';
    }
    if (category == 1 && questionNumber == 5) {
        return 'B';
    }
    if (category == 1 && questionNumber == 6) {
        return 'C';
    }
    if (category == 1 && questionNumber == 7) {
        return 'D';
    }
    if (category == 1 && questionNumber == 8) {
        return 'A';
    }
    if (category == 1 && questionNumber == 9) {
        return 'D';
    }
    if (category == 1 && questionNumber == 10) {
        return 'C';
    }
    if (category == 1 && questionNumber == 11) {
        return 'B';
    }
    if (category == 1 && questionNumber == 12) {
        return 'A';
    }
    if (category == 1 && questionNumber == 13) {
        return 'C';
    }
    if (category == 1 && questionNumber == 14) {
        return 'D';
    }
    if (category == 1 && questionNumber == 15) {
        return 'C';
    }
    if (category == 1 && questionNumber == 16) {
        return 'B';
    }
    if (category == 1 && questionNumber == 17) {
        return 'B';
    }
    if (category == 1 && questionNumber == 18) {
        return 'D';
    }

    // Quiz 2
    if (category == 2 && questionNumber == 1) {
        return 'A';
    }
    if (category == 2 && questionNumber == 2) {
        return 'D';
    }
    if (category == 2 && questionNumber == 3) {
        return 'B';
    }
    if (category == 2 && questionNumber == 4) {
        return 'C';
    }
    if (category == 2 && questionNumber == 5) {
        return 'A';
    }
    if (category == 2 && questionNumber == 6) {
        return 'B';
    }
    if (category == 2 && questionNumber == 7) {
        return 'B';
    }
    if (category == 2 && questionNumber == 8) {
        return 'C';
    }
    if (category == 2 && questionNumber == 9) {
        return 'D';
    }
    if (category == 2 && questionNumber == 10) {
        return 'D';
    }
 return 'x';
}
