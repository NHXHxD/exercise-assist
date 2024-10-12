#include "User.h"

User::User( std::string& name)
    : username(name) {
    int correct = 0;
    skillProficiency
}


void User::updateSkillProficiency( std::string& skill) {
    skillProficiency[skill]++;
}

void User::updateSkillTime( std::string& skill, double time) {
    skillTimeSpent[skill] += time;
}

void User::viewProgress()  {
    std::cout << "Progress for user: " << username << std::endl;
    std::cout << "Skill Proficiency: " << std::endl;
    for ( auto& entry : skillProficiency) {
        std::cout << "- " << entry.first << ": " << entry.second << " points" << std::endl;
    }
    std::cout << "Time Spent on Skills:" << std::endl;
    for ( auto& entry : skillTimeSpent) {
        std::cout << "- " << entry.first << ": " << entry.second << " seconds" << std::endl;
    }
}

void User::correctChoice() {
    this->correct++;
}

void User::earnAchievement() {
    if (this->correct >= 5) {
        Achievement ach_one = Achievement("Correct 5!", "Getting 5 questions correct!");
        achievements.push_back(ach_one);
        std::cout << "Congratulations! You've earned the achievement: Correct 5!" << std::endl;
    }
    if (this->correct >= 10) {
    Achievement ach_one = Achievement("Correct 10!", "Getting 10 questions correct!");
    achievements.push_back(ach_one);
    std::cout << "Congratulations! You've earned the achievement: Correct 10!" << std::endl;
}
    if (this->correct >= 15) {
        Achievement ach_one = Achievement("Correct 15!", "Getting 15 questions correct!");
        achievements.push_back(ach_one);
        std::cout << "Congratulations! You've earned the achievement: Correct 15!" << std::endl;
    }

    if (this->correct >= 10) {
        Achievement ach_one = Achievement("Correct 20!", "Getting 20 questions correct!");
        achievements.push_back(ach_one);
        std::cout << "Congratulations! You've earned the achievement: Correct 20!" << std::endl;
}
}

std::string User::getUsername()  {
    return username;
}

 std::vector<Achievement>& User::getAchievements()  {
    return achievements;
}

 std::map<std::string, int>& User::getSkillProficiency()  {
    return skillProficiency;
}

 std::map<std::string, double>& User::getSkillTimeSpent()  {
    return skillTimeSpent;
}
