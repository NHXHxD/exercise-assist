#ifndef TMCEXERCISE_H
#define TMCEXERCISE_H

#include "MCExercise.h"
#include <string>

class TMCExercise : public MCExercise {
protected:
    int timeLimit; // Time limit in seconds for each question
    // Removed redundant 'type' declaration

public:
    TMCExercise(std::string title);
    Exercise* createExercise(int size) override;
    int checkAnswer() override;
    std::string getType() override;
};

#endif // TMCEXERCISE_H
