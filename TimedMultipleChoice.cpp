#include "TimedMultipleChoiceExercise.h"
#include <iostream>
#include <chrono>
#include <thread>

TimedMultipleChoiceExercise::TimedMultipleChoiceExercise(const std::string& question, const std::vector<std::string>& optionsList, char correctOption, int timeLimitInSeconds, const std::vector<std::string>& skills)
    : MultipleChoiceExercise(question, optionsList, correctOption, skills), timeLimit(timeLimitInSeconds) {
    // Constructor implementation
}

void TimedMultipleChoiceExercise::presentExercise() {
    MultipleChoiceExercise::presentExercise();

    auto startTime = std::chrono::steady_clock::now();
    std::string userAnswer;

    // Use a separate thread to handle user input with timeout
    std::thread inputThread([&]() {
        std::getline(std::cin, userAnswer);
    });

    bool timeExpired = false;
    while (inputThread.joinable()) {
        auto currentTime = std::chrono::steady_clock::now();
        std::chrono::duration<double> elapsedSeconds = currentTime - startTime;

        if (elapsedSeconds.count() > timeLimit) {
            std::cout << "\nTime's up! You exceeded the time limit of " << timeLimit << " seconds." << std::endl;
            userAnswer = ""; // Empty answer indicates time limit exceeded
            timeExpired = true;
            break;
        }
        if (!userAnswer.empty()) {
            inputThread.join();
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Sleep briefly to reduce CPU usage
    }

    if (!timeExpired) {
        if (checkAnswer(userAnswer)) {
            std::cout << "Correct!" << std::endl;
        } else {
            std::cout << "Incorrect." << std::endl;
        }
    }
}
