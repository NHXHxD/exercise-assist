#ifndef MULTIPLECHOICEEXERCISE_H
#define MULTIPLECHOICEEXERCISE_H

#include "Exercise.h"
#include <vector>

/**
 * @brief Class representing a multiple-choice exercise.
 */
class MultipleChoiceExercise : public Exercise {
public:
    // Constructs a MultipleChoiceExercise with the given parameters.

    MultipleChoiceExercise(const std::string& question, const std::vector<std::string>& options, char correctOption, const std::vector<std::string>& skills);

    /**
     * @brief Presents the exercise to the user.
     */
    void presentExercise() override;

    /**
     * @brief Checks the user's answer for correctness.
     * @param userAnswer The answer provided by the user.
     * @return True if the answer is correct, false otherwise.
     */
    bool checkAnswer(const std::string& userAnswer) override;

protected:
    std::vector<std::string> options;
    char correctAnswer;
};

#endif // MULTIPLECHOICEEXERCISE_H
