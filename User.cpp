#include "User.h"
#include <map>
using namespace std;
User::User(string name) {
    username = name;
    correct = 0;
}





void User::viewProgress()  {
    cout << "Progress for user: " << username << endl;
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


vector<Exercise*> User::getExercises() {
    return this->exercises;
}

std::vector<Achievement> User::getAchievements() {
    return this->achievements;
}