#ifndef TFEXERCISE_H
#define TFEXERCISE_H

#include "Exercise.h"
#include <vector>
#include <string>

class TFExercise : public Exercise {
protected:
    struct TFQuestion {
        std::string questionText;
        std::string correctAnswer;
    };

    std::vector<TFQuestion> questions;
    std::string type;

public:
    TFExercise(std::string title);
    Exercise* createExercise(int size) override;
    int checkAnswer() override;
    std::string getType() override;
};

#endif // TFEXERCISE_H
