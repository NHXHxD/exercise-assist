#ifndef FBEXERCISE_H
#define FBEXERCISE_H

#include "Exercise.h"
#include <vector>
#include <string>

class FBExercise : public Exercise {
protected:
    struct FBQuestion {
        std::string questionText;
        std::string correctAnswer;
    };

    std::vector<FBQuestion> questions;
    std::string type;

public:
    FBExercise(std::string title);
    Exercise* createExercise(int size) override;
    int checkAnswer() override;
    std::string getType() override;
};

#endif // FBEXERCISE_H
