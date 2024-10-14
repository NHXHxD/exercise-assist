#ifndef TMCEXERCISE_H
#define TMCEXERCISE_H

#include "MCExercise.h"

/**
 * @brief Class representing a timed multiple-choice exercise.
 */
class TimedMultipleChoiceExercise : public MCExercise {
public:
    // constructor
    TMCExercise()

    /**
     * @brief Presents the exercise to the user, enforcing the time limit.
     */
    void presentExercise() override;

private:
    int timeLimit; // Time limit in seconds
};

#endif 
