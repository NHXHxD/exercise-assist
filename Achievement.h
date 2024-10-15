#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>

class Achievement {
private:
    std::string achievementName;
    std::string description;
public:
    Achievement(std::string name, std::string description);

    // Displays the achievement.
    void displayAchievement() const; // Marked as const

    // Gets the name of the achievement.
    std::string getName() const; // Marked as const

    // Gets the description of the achievement.
    std::string getDescription() const; // Marked as const
};

#endif // ACHIEVEMENT_H
