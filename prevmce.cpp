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
#endif

#include "MCExercise.h"
#include <iostream>
#include "User.h"
MCExercise::MCExercise(std::string title) : Exercise(title)  {
    this->title = title;
    this->type = "MC";
}
Exercise* MCExercise::createExercise(int size) {
    for (int i = 0; i < size; i++) {
        string q;
        string a;

        cout << "Enter question " << i + 1 << ": \n";
        cin.ignore(); // Clear the input buffer before getline
        getline(cin, q);

        cout << "Enter option A: \n";
        getline(cin, options[i][0]);

        cout << "Enter option B: \n";
        getline(cin, options[i][1]);

        cout << "Enter option C: \n";
        getline(cin, options[i][2]);

        cout << "Enter option D: \n";
        getline(cin, options[i][3]);

        cout << "Enter correct answer (A/B/C/D): \n";
        getline(cin, a);

        QnA.insert(pair<string, string>(q, a));
    }
    return this; // Return the current object
}


int MCExercise::checkAnswer() {
    vector<string> answers;
    int point = 0;
    auto it = QnA.begin();
    int i = 0;

    while (it != QnA.end()) {
        cout << "Question " << i + 1 << ": " << it->first << endl;
        cout << "A: " << options[i][0] << endl;
        cout << "B: " << options[i][1] << endl;
        cout << "C: " << options[i][2] << endl;
        cout << "D: " << options[i][3] << endl;
        cout << "Enter your answer: " << endl;

        string ans;
        getline(cin, ans); // Use getline to read the answer
        answers.push_back(ans);
        ++it;
        i++;
    }

    // Reset iterator and counter for checking answers
    it = QnA.begin();
    i = 0;

    while (it != QnA.end()) {
        if (it->second == answers[i]) {
            cout << "You got question " << i + 1 << " correct!\n";
            point++;
        } else {
            cout << "Incorrect answer for question " << i + 1 << "!" << endl;
            cout << "Correct answer is: " << it->second << endl;
        }
        ++it;
        i++;
    }
    return point;
}
string MCExercise::getType() {
    return type;
}


