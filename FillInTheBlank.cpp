#include "FillInTheBlankExercise.h"
#include <iostream>
#include <algorithm>

FillInTheBlankExercise::FillInTheBlankExercise(const std::string& prompt, const std::string& answer, const std::vector<std::string>& skills)
    : Exercise(prompt, skills), correctAnswer(answer) {
    // Constructor implementation
}

void FillInTheBlankExercise::presentExercise() {
    std::cout << questionText << std::endl;
    std::cout << "Please fill in the blank: ";
}

bool FillInTheBlankExercise::checkAnswer(const std::string& userAnswer) {
    std::string userAns = userAnswer;
    std::string correctAns = correctAnswer;
    std::transform(userAns.begin(), userAns.end(), userAns.begin(), ::tolower);
    std::transform(correctAns.begin(), correctAns.end(), correctAns.begin(), ::tolower);
    return userAns == correctAns;
}
