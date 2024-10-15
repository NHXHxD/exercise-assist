#ifndef MCEXERCISE_H
#define MCEXERCISE_H

#include "Exercise.h"
#include <vector>
#include <map>
#include <vector>
using namespace std;

class MCExercise : public Exercise {
    protected:
        map<string, string> QnA;
        string options[100][4];
        string type;
    public:
        MCExercise(string title);
        Exercise* createExercise(int size) override;
        int checkAnswer() override;
        string getType();
 
};
#endif MCEXERCISE_H
