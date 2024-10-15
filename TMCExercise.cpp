// TMCExercise.cpp

#include "TMCExercise.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include <algorithm>
#include <cctype>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#endif

TMCExercise::TMCExercise(std::string title) : MCExercise(title) {
    this->type = "Timed MC";
    this->timeLimit = 0;
}

Exercise* TMCExercise::createExercise(int size) {
    // Call the base class createExercise to reuse the question creation process
    MCExercise::createExercise(size);

    // Ask the user for the time limit per question
    std::cout << "Enter the time limit per question in seconds: ";
    while (!(std::cin >> timeLimit) || timeLimit <= 0) {
        std::cout << "Invalid input. Please enter a positive integer for the time limit: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    // Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return this;
}

// Platform-specific function to check if input is available without blocking
bool inputAvailable() {
#ifdef _WIN32
    // Windows implementation
    HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
    DWORD events = 0;
    GetNumberOfConsoleInputEvents(hStdin, &events);
    return events > 0;
#else
    // POSIX implementation
    struct termios oldt, newt;
    int oldf;
    bool inputAvailable = false;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO); // Disable canonical mode and echo
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);

    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    char ch;
    if (read(STDIN_FILENO, &ch, 1) > 0) {
        inputAvailable = true;
        ungetc(ch, stdin);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    return inputAvailable;
#endif
}

int TMCExercise::checkAnswer() {
    int points = 0;
    std::vector<std::string> userAnswers;

    // Inform the user about the time limit
    std::cout << "\nYou have " << timeLimit << " seconds to answer each question.\n";

    // Loop through each question
    for (size_t i = 0; i < questions.size(); ++i) {
        const MCQuestion& q = questions[i];

        std::cout << "\nQuestion " << i + 1 << ": " << q.questionText << std::endl;
        std::cout << "A: " << q.options[0] << std::endl;
        std::cout << "B: " << q.options[1] << std::endl;
        std::cout << "C: " << q.options[2] << std::endl;
        std::cout << "D: " << q.options[3] << std::endl;
        std::cout << "Enter your answer (A/B/C/D): ";

        std::string ans;
        bool answered = false;
        bool timeUp = false;

        auto startTime = std::chrono::steady_clock::now();

        while (true) {
            if (inputAvailable()) {
                std::getline(std::cin, ans);
                answered = true;
                break;
            }

            auto currentTime = std::chrono::steady_clock::now();
            auto elapsedSeconds = std::chrono::duration_cast<std::chrono::seconds>(currentTime - startTime).count();

            if (elapsedSeconds >= timeLimit) {
                timeUp = true;
                break;
            }

            // Sleep for a short duration to prevent high CPU usage
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }

        if (timeUp) {
            std::cout << "\nTime's up! Moving to the next question.\n";
            userAnswers.push_back(""); // Empty answer indicates no response
            // Clear any leftover input
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        } else {
            // Convert answer to uppercase
            std::transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
            userAnswers.push_back(ans);
        }
    }

    // Check user's answers after all questions have been answered
    for (size_t i = 0; i < questions.size(); ++i) {
        const MCQuestion& q = questions[i];

        // Convert correctAnswer to uppercase for case-insensitive comparison
        std::string correctAnswer = q.correctAnswer;
        std::transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::toupper);

        if (userAnswers[i].empty()) {
            std::cout << "You did not answer question " << i + 1 << ".\n";
        } else if (correctAnswer == userAnswers[i]) {
            std::cout << "You got question " << i + 1 << " correct!\n";
            points++;
        } else {
            std::cout << "Incorrect answer for question " << i + 1 << "!\n";
            std::cout << "Correct answer is: " << correctAnswer << std::endl;
        }
    }

    std::cout << "You scored " << points << " out of " << questions.size() << "!\n";
    return points;
}

std::string TMCExercise::getType() {
    return type;
}
