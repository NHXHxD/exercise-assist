#include "MCExercise.h"
#include <iostream>
#include <limits>

MCExercise::MCExercise(std::string title) : Exercise(title) {
    this->title = title;
    this->type = "MC";
}

Exercise* MCExercise::createExercise(int size) {
    // Clear the input buffer before starting
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < size; i++) {
        MCQuestion q;

        std::cout << "Enter question " << i + 1 << ": \n";
        std::getline(std::cin, q.questionText);

        std::cout << "Enter option A: \n";
        std::getline(std::cin, q.options[0]);

        std::cout << "Enter option B: \n";
        std::getline(std::cin, q.options[1]);

        std::cout << "Enter option C: \n";
        std::getline(std::cin, q.options[2]);

        std::cout << "Enter option D: \n";
        std::getline(std::cin, q.options[3]);

        std::cout << "Enter correct answer (A/B/C/D): \n";
        std::getline(std::cin, q.correctAnswer);

        questions.push_back(q);
    }
    return this; // Return the current object
}

int MCExercise::checkAnswer() {
    int points = 0;
    std::vector<std::string> userAnswers;

    // Clear the input buffer before starting
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ensure input buffer is clear

    // Display each question and get user's answer
    for (size_t i = 0; i < questions.size(); ++i) {
        const MCQuestion& q = questions[i];

        std::cout << "\nQuestion " << i + 1 << ": " << q.questionText << std::endl;
        std::cout << "A: " << q.options[0] << std::endl;
        std::cout << "B: " << q.options[1] << std::endl;
        std::cout << "C: " << q.options[2] << std::endl;
        std::cout << "D: " << q.options[3] << std::endl;
        std::cout << "Enter your answer: ";

        std::string ans;
        std::getline(std::cin, ans);
        userAnswers.push_back(ans);
    }

    // Check user's answers after all questions have been answered
    for (size_t i = 0; i < questions.size(); ++i) {
        const MCQuestion& q = questions[i];
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

std::string MCExercise::getType() {
    return type;
}
