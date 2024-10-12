#ifndef TRUEFALSEEXERCISE_H
#define TRUEFALSEEXERCISE_H

#include "Exercise.h"

/**
 * @brief Class representing a true/false exercise.
 */
class TrueFalseExercise : public Exercise {
public:
    /**
     * @brief Constructs a TrueFalseExercise with the given parameters.
     * @param statement The statement to evaluate.
     * @param isTrue The correct answer (true or false).
     * @param skills The skills addressed by the exercise.
     */
    TrueFalseExercise(const std::string& statement, bool isTrue, const std::vector<std::string>& skills);

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
    bool correctAnswer;
};

#endif // TRUEFALSEEXERCISE_H
