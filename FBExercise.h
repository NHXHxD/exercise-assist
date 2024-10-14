#ifndef FBEXERCISE_H
#define FBEXERCISE_H
#include <map>
using namespace std;
#include "Exercise.h"


class FBExercise : public Exercise {
    protected:
        map<string, string> QnA; 
    public:
        FBExercise();
        FBExercise* FBExercise::createExercise(int size);

        int checkAnswer(FBExercise* exercise);


};

#endif 
