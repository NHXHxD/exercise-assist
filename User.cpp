#include "User.h"
#include <map>
using namespace std;
User::User( string& name)
    : username(name) {
    int correct = 0;
}


void User::updateSkillProficiency( string& skill) {
    skillProficiency[skill]++;
}

void User::updateSkillTime( string& skill, double time) {
    skillTimeSpent[skill] += time;
}

void User::viewProgress()  {
    cout << "Progress for user: " << username << endl;
    cout << "Skill Proficiency: " << endl;
    for ( auto& entry : skillProficiency) {
        cout << "- " << entry.first << ": " << entry.second << " points" << endl;
    }
    cout << "Time Spent on Skills:" << endl;
    for ( auto& entry : skillTimeSpent) {
        cout << "- " << entry.first << ": " << entry.second << " seconds" << endl;
    }
}

void User::createSkill() {
    map<string, int> skills = getSkillProficiency();
    string skill;
    cout << "Enter a skill you wish to learn: ";
    cin >> skill;
    skills.insert(pair<string, int>(skill, 0));
}
void User::addExercisesToSkill() {
    int choice; 
    while (choice < 1 || choice > 4) {
        cout << "Which type of exercise would you like to create? (1-4): " << endl;
        cout << "1. Multiple Choice\n";
        cout << "2. Timed Multiple Choice\n";
        cout << "3. True/False\n";
        cout << "4. Fill in the Blank\n";
    }
    if (choice == 1) {

    } 
    else if (choice == 2) {

    }
    else if (choice == 3) {

    }
    else if (choice == 4) {

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

 vector<Achievement> User::getAchievements()  {
    return achievements;
}

 map<string, int>& User::getSkillProficiency()  {
    return skillProficiency;
}

 map<string, double>& User::getSkillTimeSpent()  {
    return skillTimeSpent;
}
