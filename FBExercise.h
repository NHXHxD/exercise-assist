#ifndef FBEXERCISE_H
#define FBEXERCISE_H
#include <map>
#include <string>

using namespace std;
#include "Exercise.h"


class FBExercise : public Exercise {
    protected:
        map<string, string> QnA; 
        string type;
    public:
        FBExercise(string title);
        FBExercise* createExercise(int size);
        string getType();
        int checkAnswer();


};

#endif 