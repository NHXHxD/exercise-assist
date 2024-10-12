#ifndef TIMEDMULTIPLECHOICEEXERCISE_H
#define TIMEDMULTIPLECHOICEEXERCISE_H

#include "MultipleChoiceExercise.h"

/**
 * @brief Class representing a timed multiple-choice exercise.
 */
class TimedMultipleChoiceExercise : public MultipleChoiceExercise {
public:
    /**
     * @brief Constructs a TimedMultipleChoiceExercise with the given parameters.
     * @param question The question text.
     * @param options The list of answer options.
     * @param correctOption The correct option character.
     * @param timeLimitInSeconds The time limit for the exercise.
     * @param skills The skills addressed by the exercise.
     */
    TimedMultipleChoiceExercise(const std::string& question, const std::vector<std::string>& options, char correctOption, int timeLimitInSeconds, const std::vector<std::string>& skills);

    /**
     * @brief Presents the exercise to the user, enforcing the time limit.
     */
    void presentExercise() override;

private:
    int timeLimit; // Time limit in seconds
};

#endif // TIMEDMULTIPLECHOICEEXERCISE_H
