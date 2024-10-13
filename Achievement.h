#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>
#include "User.h"

class Achievement {
    private:
        std::string achievementName;
        std::string description;
    public:
        Achievement(std::string name, std::string description);

        // Displays the achievement.
        void displayAchievement();

        // Gets the name of the achievement.
        std::string getName();

        // Gets the description of the achievement.

        std::string getDescription();
    };

#endif // ACHIEVEMENT_H
