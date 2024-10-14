#include "User.h"
#include <map>
using namespace std;
User::User( string& name)
    : username(name) {
    int correct = 0;
}


void User::updateProficiency( string& skill) {
    // proficiency++;
}

void User::updateTime( double time) {
    timeSpent += time;
}

void User::viewProgress()  {
    cout << "Progress for user: " << username << endl;
    cout << "Proficiency: " << endl;
    for ( auto& entry : proficiency) {
        cout << "- " << entry.first << ": " << entry.second << " points" << endl;
    }
    cout << "Time Spent:" << endl;
    for ( auto& entry : timeSpent) {
        cout << "- " << entry.first << ": " << entry.second << " seconds" << endl;
    }
}


void User::studySkill() {

}
void User::viewProgress() {

}



void User::correctChoice() {
    this->correct++;
}

void User::earnAchievement() {
    if (this->correct >= 5) {
        Achievement ach = Achievement("Correct 5!", "Getting 5 questions correct!");
        achievements.push_back(ach);
        cout << "Congratulations! You've earned the achievement: Correct 5!" << endl;
    }
    if (this->correct >= 10) {
        Achievement ach = Achievement("Correct 10!", "Getting 10 questions correct!");
        achievements.push_back(ach);
    cout << "Congratulations! You've earned the achievement: Correct 10!" << endl;
}
    if (this->correct >= 15) {
        Achievement ach = Achievement("Correct 15!", "Getting 15 questions correct!");
        achievements.push_back(ach);
        cout << "Congratulations! You've earned the achievement: Correct 15!" << endl;
    }

    if (this->correct >= 10) {
        Achievement ach = Achievement("Correct 20!", "Getting 20 questions correct!");
        achievements.push_back(ach);
        cout << "Congratulations! You've earned the achievement: Correct 20!" << endl;
    }
}

string User::getUsername()  {
    return username;
}

    return achievements;
}

map<string, int>& User::getProficiency()  {
    return proficiency;
}

map<string, double>& User::getTimeSpent()  {
    return timeSpent;
}

vector<Exercise*> User::getExercises() {
    return this->exercises;
}
