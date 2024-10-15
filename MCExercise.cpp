#include "MCExercise.h"
#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

MCExercise::MCExercise(std::string title) : Exercise(title) {
    this->title = title;
    this->type = "MC";
}

Exercise* MCExercise::createExercise(int size) {
    // Clear the input buffer before starting
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < size; i++) {
        MCQuestion q;

        std::cout << "Enter question " << i + 1 << ": ";
        std::getline(std::cin, q.questionText);

        std::cout << "Enter option A: ";
        std::getline(std::cin, q.options[0]);

        std::cout << "Enter option B: ";
        std::getline(std::cin, q.options[1]);

        std::cout << "Enter option C: ";
        std::getline(std::cin, q.options[2]);

        std::cout << "Enter option D: ";
        std::getline(std::cin, q.options[3]);

        std::cout << "Enter correct answer (A/B/C/D): ";
        std::getline(std::cin, q.correctAnswer);
        bool valid = false;
            while (!valid) {
                std::cout << "Enter correct answer (A/B/C/D): ";
                std::getline(std::cin, q.correctAnswer);
                
                // Convert input to uppercase to make validation case-insensitive
                std::transform(q.correctAnswer.begin(), q.correctAnswer.end(), q.correctAnswer.begin(), ::toupper);
                
                if (q.correctAnswer == "A" || q.correctAnswer == "B" || q.correctAnswer == "C" || q.correctAnswer == "D") {
                    valid = true;
                } else {
                    std::cout << "Incorrect response. Please enter your answer again.\n";
                }
                    }
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
    return points; // get points to add into the number of correct answers
}

std::string MCExercise::getType() {
    return type;
}
