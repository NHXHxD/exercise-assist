#ifndef TFEXERCISE_H
#define TFEXERCISE_H
#include <string>
using namespace std;
#include <map>
#include "Exercise.h"

/**
 * @brief Class representing a true/false exercise.
 */
class TFExercise : public Exercise {
    protected:
        map<string, string> QnA;
    public:
        TFExercise();
        TFExercise* createExercise(int size);

        int checkAnswer(TFExercise* exercise);


};

#endif 
