#ifndef MULTIPLECHOICEEXERCISE_H
#define MULTIPLECHOICEEXERCISE_H

#include "Exercise.h"
#include <vector>
#include <map>
#include <vector>
using namespace std;

class MultipleChoiceExercise : public Exercise {
    protected:
        map<string, string> QnA;
        string options[4][100];
    public:
        

#endif // MULTIPLECHOICEEXERCISE_H
