#ifndef TFEXERCISE_H
#define TFEXERCISE_H
#include <string>
using namespace std;
#include <map>
#include "Exercise.h"


class TFExercise : public Exercise {
    protected:
        map<string, string> QnA;
        string type;
    public:
        TFExercise(std::string title);
        TFExercise* createExercise(int size);
        int checkAnswer() override;
        string getType();



};

#endif 