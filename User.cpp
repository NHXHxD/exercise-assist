#include "User.h"

User::User(std::string name) : username(name), correct(0) {
    // Constructor body (if needed)
}

void User::earnAchievement() {
    if (correct >= 5 && !hasAchievement("Correct 5!")) {
        Achievement ach("Correct 5!", "Getting 5 questions correct!");
        achievements.push_back(ach);
        std::cout << "Congratulations! You've earned the achievement: Correct 5!" << std::endl;
    }
    if (correct >= 10 && !hasAchievement("Correct 10!")) {
        Achievement ach("Correct 10!", "Getting 10 questions correct!");
        achievements.push_back(ach);
        std::cout << "Congratulations! You've earned the achievement: Correct 10!" << std::endl;
    }
    if (correct >= 15 && !hasAchievement("Correct 15!")) {
        Achievement ach("Correct 15!", "Getting 15 questions correct!");
        achievements.push_back(ach);
        std::cout << "Congratulations! You've earned the achievement: Correct 15!" << std::endl;
    }
    if (correct >= 20 && !hasAchievement("Correct 20!")) {
        Achievement ach("Correct 20!", "Getting 20 questions correct!");
        achievements.push_back(ach);
        std::cout << "Congratulations! You've earned the achievement: Correct 20!" << std::endl;
    }
}

bool User::hasAchievement(const std::string& name) {
    for (const Achievement& ach : achievements) {
        if (ach.getName() == name) {
            return true;
        }
    }
    return false;
}

std::string User::getUsername() {
    return username;
}

void User::correctChoice(int point) {
    correct += point;
}

std::vector<Exercise*> User::getExercises() {
    return this->exercises;
}

std::vector<Achievement> User::getAchievements() {
    return this->achievements;
}
