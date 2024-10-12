#include "User.h"
#include "Lesson.h"

User::User(const std::string& name)
    : username(name) {
    // Constructor implementation
}

void User::startLesson(Lesson& lesson) {
    lesson.startLesson(*this);
}

void User::updateSkillProficiency(const std::string& skill, int points) {
    skillProficiency[skill] += points;
}

void User::updateSkillTime(const std::string& skill, double time) {
    skillTimeSpent[skill] += time;
}

void User::viewProgress() const {
    std::cout << "Progress for user: " << username << std::endl;
    std::cout << "Skill Proficiency:" << std::endl;
    for (const auto& entry : skillProficiency) {
        std::cout << "- " << entry.first << ": " << entry.second << " points" << std::endl;
    }
    std::cout << "Time Spent on Skills:" << std::endl;
    for (const auto& entry : skillTimeSpent) {
        std::cout << "- " << entry.first << ": " << entry.second << " seconds" << std::endl;
    }
}

void User::earnAchievement(const Achievement& achievement) {
    achievements.push_back(achievement);
    std::cout << "Congratulations! You've earned the achievement: " << achievement.getName() << std::endl;
}

std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "Username: " << user.username << std::endl;
    os << "Achievements: " << std::endl;
    for (const auto& achievement : user.achievements) {
        os << "- " << achievement.getName() << ": " << achievement.getDescription() << std::endl;
    }
    return os;
}

std::string User::getUsername() const {
    return username;
}

const std::vector<Achievement>& User::getAchievements() const {
    return achievements;
}

const std::map<std::string, int>& User::getSkillProficiency() const {
    return skillProficiency;
}

const std::map<std::string, double>& User::getSkillTimeSpent() const {
    return skillTimeSpent;
}
