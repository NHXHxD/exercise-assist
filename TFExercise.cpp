#include "TFExercise.h"
#include <iostream>
#include <algorithm>

TFExercise::TFExercise() {

}


TFExercise* TFExercise::createExercise(int size) {
    TFExercise* exercise;
    for (int i = 0; i < size; i++) {
        string q;
        string a;
        cout << "Enter question " << i + 1<< ": \n";
        cin >> q;
        cout << "Enter correct answer (T-F): \n";
        cin >> a;
        exercise->QnA.insert(pair<string,string>(q,a));
    }
    return exercise;

}  


int TFExercise::checkAnswer(TFExercise* exercise) {
    vector<string> answers;
    int point = 0;
    map<string, string>::iterator it = exercise->QnA.begin();
    int i = 0;
    while (it != exercise->QnA.end()) {
        cout << "Question" << i+1 << ": " << it->first  <<  endl;
        cout << "Enter your answer (T-F): " << endl;
        string ans;
        cin >> ans;
        answers.push_back(ans);
        ++it;
        i++;
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
