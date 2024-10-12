#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <vector>

/**
 * @brief Abstract base class representing a generic exercise.
 */
class Exercise {
public:
    /**
     * @brief Constructs an Exercise with the given question text and skills addressed.
     * @param question The question text for the exercise.
     * @param skills The skills addressed by the exercise.
     */
    Exercise(const std::string& question, const std::vector<std::string>& skills);

    /**
     * @brief Presents the exercise to the user.
     *        Pure virtual function to be overridden by derived classes.
     */
    virtual void presentExercise() = 0;

    /**
     * @brief Checks the user's answer for correctness.
     *        Pure virtual function to be overridden by derived classes.
     * @param userAnswer The answer provided by the user.
     * @return True if the answer is correct, false otherwise.
     */
    virtual bool checkAnswer(const std::string& userAnswer) = 0;

    /**
     * @brief Gets the skills addressed by the exercise.
     * @return A vector of skill names.
     */
    const std::vector<std::string>& getSkills() const;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Exercise();

protected:
    std::string questionText;
    std::vector<std::string> skillsAddressed;
};

#endif // EXERCISE_H
