#include "TFExercise.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <cctype>

TFExercise::TFExercise(std::string title) : Exercise(title) {
    this->title = title;
    this->type = "TF";
}

Exercise* TFExercise::createExercise(int size) {
    // Clear the input buffer before starting
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < size; i++) {
        TFQuestion q;

        std::cout << "Enter question " << i + 1 << ": \n";
        std::getline(std::cin, q.questionText);

        std::cout << "Enter correct answer (T/F): \n";
        bool validInput = false;
        while (!validInput) {
            std::getline(std::cin, q.correctAnswer);
            // Convert to uppercase
            std::transform(q.correctAnswer.begin(), q.correctAnswer.end(), q.correctAnswer.begin(), ::toupper);
            if (q.correctAnswer == "T" || q.correctAnswer == "F") {
                validInput = true;
            } else {
                std::cout << "Invalid input. Please enter 'T' or 'F': ";
            }
        }

        questions.push_back(q);
    }
    return this;
}

int TFExercise::checkAnswer() {
    int points = 0;
    std::vector<std::string> userAnswers;

    // Clear the input buffer before starting
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Display each question and get user's answer
    for (size_t i = 0; i < questions.size(); ++i) {
        const TFQuestion& q = questions[i];

        std::cout << "\nQuestion " << i + 1 << ": " << q.questionText << std::endl;
        std::cout << "Enter your answer (T/F): ";

        std::string ans;
        bool validInput = false;
        while (!validInput) {
            std::getline(std::cin, ans);
            // Convert to uppercase
            std::transform(ans.begin(), ans.end(), ans.begin(), ::toupper);
            if (ans == "T" || ans == "F") {
                validInput = true;
            } else {
                std::cout << "Invalid input. Please enter 'T' or 'F': ";
            }
        }
        userAnswers.push_back(ans);
    }

    // Check user's answers after all questions have been answered
    for (size_t i = 0; i < questions.size(); ++i) {
        const TFQuestion& q = questions[i];
        if (q.correctAnswer == userAnswers[i]) {
            std::cout << "You got question " << i + 1 << " correct!\n";
            points++;
        } else {
            std::cout << "Incorrect answer for question " << i + 1 << "!\n";
            std::cout << "Correct answer is: " << q.correctAnswer << std::endl;
        }
    }

    std::cout << "You scored " << points << " out of " << questions.size() << "!\n";
    return points;
}

std::string TFExercise::getType() {
    return type;
}
