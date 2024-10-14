#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <vector>

/**
 * @brief Abstract base class representing a generic exercise.
 */
class Exercise {
    protected:
        std::string title;
        std::string description;
    public:
        // Constructs an Exercise with the given question text and skills addressed.
        Exercise(const std::string& question, const std::vector<std::string>& skills);

        // Creates the exercise to the user.
        virtual void createExercise() = 0;

        // Creates the exercise to the user.
        virtual void presentExercise() = 0;

        // Checks the user's answer for correctness.
        virtual bool checkAnswer(const std::string& userAnswer) = 0;



        // Virtual destructor.
        virtual ~Exercise();


    };

#endif // EXERCISE_H
