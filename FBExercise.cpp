#include "FBExercise.h"
#include <iostream>
#include <algorithm>
using namespace std;

FBExercise::FBExercise() {
}

FBExercise* FBExercise::createExercise(int size) {
    FBExercise* exercise;
    for (int i = 0; i < size; i++) {
        string q;
        string a;
        cout << "Enter question " << i + 1<< ": \n";
        cin >> q;
        cout << "Enter correct answer in the blank: \n";
        cin >> a;
        exercise->QnA.insert(pair<string,string>(q,a));
    }
    return exercise;
}  

int FBExercise::checkAnswer(FBExercise* exercise) {
    vector<string> answers;
    int point = 0;
    int i = 0;
    map<string, string>::iterator it = exercise->QnA.begin();
    while (it != exercise->QnA.end()) {
        cout << "Question" << i+1 << ": " << it->first  <<  endl;
        cout << "Enter your answer: " << endl;
        string ans;
        cin >> ans;
        answers.push_back(ans);
        ++it;
    }
    map<string, string>::iterator it = exercise->QnA.begin();
    int i = 0;
    while (it != exercise->QnA.end()) {
        if (it->second == answers[i]) {
            cout << "You got question " << i+1 << "correct! \n";
            point++;
        }
        else {
            cout << "Incorrect answer for question " << i+1 << "!" << endl;
            cout << "Correct answer is: " << it->second << endl;
        }
        ++it;
        i++;
    }
    return point;
    

}
