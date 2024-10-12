#include "TrueFalseExercise.h"
#include <iostream>
#include <algorithm>

TrueFalseExercise::TrueFalseExercise(const std::string& statement, bool isTrue, const std::vector<std::string>& skills)
    : Exercise(statement, skills), correctAnswer(isTrue) {
    // Constructor implementation
}

void TrueFalseExercise::presentExercise() {
    std::cout << questionText << std::endl;
    std::cout << "Please enter 'True' or 'False': ";
}

bool TrueFalseExercise::checkAnswer(const std::string& userAnswer) {
    std::string answer = userAnswer;
    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);

    if ((answer == "true" && correctAnswer) || (answer == "false" && !correctAnswer)) {
        return true;
    }
    return false;
}
