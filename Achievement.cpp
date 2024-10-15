#include "Achievement.h"
#include <iostream>

Achievement::Achievement(std::string name, std::string desc)
    : achievementName(name), description(desc) {
    // Constructor implementation
}


// display the achievement of the user
void Achievement::displayAchievement() const {
    std::cout << "Achievement Unlocked: " << achievementName << std::endl;
    std::cout << description << std::endl;
}

std::string Achievement::getName() const {
    return achievementName;
}

std::string Achievement::getDescription() const {
    return description;
}
