#ifndef EXERCISE_H
#define EXERCISE_H

#include <string>
#include <vector>
#include <string>
using namespace std;
/**
 * @brief Abstract base class representing a generic exercise.
 */
class Exercise {
    protected:
        std::string title;
        std::string description;
    public:
        // Constructs an Exercise with the given question text and skills addressed.
        Exercise(std::string title, std::string description);

        // Creates the exercise to the user.
        virtual Exercise* createExercise(int size) = 0;

        virtual string getType() = 0;
        // Checks the user's answer for correctness.
        virtual int checkAnswer() = 0;

        // get title of the exercise
        string getTitle() {
            return this->title;
        }


        // Virtual destructor.
        virtual ~Exercise();


    };

#endif // EXERCISE_H
