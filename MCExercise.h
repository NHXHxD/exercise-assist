#ifndef MCEXERCISE_H
#define MCEXERCISE_H

#include "Exercise.h"
#include <vector>
#include <string>

class MCExercise : public Exercise {
protected:
    struct MCQuestion {
        std::string questionText;
        std::string options[4];
        std::string correctAnswer;
    };

    std::vector<MCQuestion> questions;
    std::string type;

public:
    MCExercise(std::string title);
    Exercise* createExercise(int size) override;
    int checkAnswer() override;
    std::string getType() override;
};

#endif // MCEXERCISE_H
