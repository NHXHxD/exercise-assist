#include "MCExercise.h"
#include <iostream>
#include "User.h"
MCExercise::MCExercise() {

}
MCExercise* MCExercise::createExercise(int size) {
    MCExercise* exercise;
    for (int i = 0; i < size; i++) {
        string q;
        string a;
        cout << "Enter question " << i + 1<< ": \n";
        cin >> q;
        cout << "Enter option A: \n";
        cin >> exercise->options[i][0];
        cout << "Enter option B: \n";
        cin >>exercise->options[i][1];
        cout << "Enter option C: \n";
        cin >>exercise->options[i][2];
        cout << "Enter option D: \n";
        cin >>exercise->options[i][3];
        cout << "Enter correct answer: \n";
        cin >> a;
        exercise->QnA.insert(pair<string,string>(q,a));
    }
    return exercise;
}


int MCExercise::checkAnswer(MCExercise* exercise) {
    vector<string> answers;
    int point = 0;
    map<string, string>::iterator it = exercise->QnA.begin();
    int i = 0;
    while (it != exercise->QnA.end()) {
        cout << "Question" << i+1 << ": " << it->first  <<  endl;
        cout << "A: " << exercise->options[i][0];
        cout << "B: " << exercise->options[i][1];
        cout << "C: " << exercise->options[i][2];
        cout << "D: " << exercise->options[i][3];
        cout << "Enter your answer: " << endl;
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


