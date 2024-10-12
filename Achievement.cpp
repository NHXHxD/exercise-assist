#include "Achievement.h"
#include <iostream>

Achievement::Achievement(const std::string& name, const std::string& desc)
    : achievementName(name), description(desc) {
    // Constructor implementation
}

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
