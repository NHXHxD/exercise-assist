#ifndef FILLINTHEBLANKEXERCISE_H
#define FILLINTHEBLANKEXERCISE_H

#include "Exercise.h"

/**
 * @brief Class representing a fill-in-the-blank exercise.
 */
class FillInTheBlankExercise : public Exercise {
public:
    /**
     * @brief Constructs a FillInTheBlankExercise with the given parameters.
     * @param prompt The prompt with blanks.
     * @param correctAnswer The correct answer to fill in.
     * @param skills The skills addressed by the exercise.
     */
    FillInTheBlankExercise(const std::string& prompt, const std::string& correctAnswer, const std::vector<std::string>& skills);

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

private:
    std::string correctAnswer;
};

#endif // FILLINTHEBLANKEXERCISE_H
