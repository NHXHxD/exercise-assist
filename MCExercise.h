#ifndef MULTIPLECHOICEEXERCISE_H
#define MULTIPLECHOICEEXERCISE_H

#include "Exercise.h"
#include <vector>
#include <map>
#include <vector>
using namespace std;

class MCExercise : public Exercise {
    protected:
        map<string, string> QnA;
        string options[100][4];
    public:
        MCExercise();
        MCExercise* createExercise(int size);
        int checkAnswer(MCExercise* exercise);
        void presentExercise(MCExercise* exercise);

};
#endif 
