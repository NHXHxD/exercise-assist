#include "FBExercise.h"
#include <iostream>
#include <algorithm>
#include <limits>
#include <cctype>

FBExercise::FBExercise(std::string title) : Exercise(title) {
    this->title = title;
    this->type = "FB";
}

Exercise* FBExercise::createExercise(int size) {
    // Clear the input buffer before starting
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < size; i++) {
        FBQuestion q;

        std::cout << "Enter question " << i + 1 << ": \n";
        std::getline(std::cin, q.questionText);

        std::cout << "Enter correct answer: \n";
        std::getline(std::cin, q.correctAnswer);

        questions.push_back(q);
    }
    return this;
}

int FBExercise::checkAnswer() {
    int points = 0;
    std::vector<std::string> userAnswers;

    // Clear the input buffer before starting
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    // Display each question and get user's answer
    for (size_t i = 0; i < questions.size(); ++i) {
        const FBQuestion& q = questions[i];

        std::cout << "\nQuestion " << i + 1 << ": " << q.questionText << std::endl;
        std::cout << "Enter your answer: ";

        std::string ans;
        std::getline(std::cin, ans);

        userAnswers.push_back(ans);
    }

    // Check user's answers after all questions have been answered
    for (size_t i = 0; i < questions.size(); ++i) {
        const FBQuestion& q = questions[i];

        // Convert both answers to lowercase for case-insensitive comparison
        std::string correctAnswer = q.correctAnswer;
        std::string userAnswer = userAnswers[i];

        std::transform(correctAnswer.begin(), correctAnswer.end(), correctAnswer.begin(), ::tolower);
        std::transform(userAnswer.begin(), userAnswer.end(), userAnswer.begin(), ::tolower);

        if (correctAnswer == userAnswer) {
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

std::string FBExercise::getType() {
    return this->type;
}
