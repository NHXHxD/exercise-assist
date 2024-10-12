#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>
#include "User.h"

class Achievement {
    private:
        std::string achievementName;
        std::string description;
    public:
        Achievement(const std::string& name, const std::string& description);

        // Displays the achievement.
        void displayAchievement() const;

        // Gets the name of the achievement.
        std::string getName() const;

        // Gets the description of the achievement.

        std::string getDescription() const;
    };

#endif // ACHIEVEMENT_H
