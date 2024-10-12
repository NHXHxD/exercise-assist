#include "MultipleChoiceExercise.h"
#include <iostream>
#include <cctype>
#include <algorithm>

MultipleChoiceExercise::MultipleChoiceExercise(const std::string& question, const std::vector<std::string>& optionsList, char correctOption, const std::vector<std::string>& skills)
    : Exercise(question, skills), options(optionsList), correctAnswer(toupper(correctOption)) {
    // Constructor implementation
}

void MultipleChoiceExercise::presentExercise() {
    std::cout << questionText << std::endl;
    char optionLabel = 'A';
    for (const auto& option : options) {
        std::cout << optionLabel << ") " << option << std::endl;
        ++optionLabel;
    }
    std::cout << "Please enter the correct option (A, B, C, etc.): ";
}

bool MultipleChoiceExercise::checkAnswer(const std::string& userAnswer) {
    if (userAnswer.empty()) {
        return false;
    }
    char answer = toupper(userAnswer[0]);
    return answer == correctAnswer;
}
