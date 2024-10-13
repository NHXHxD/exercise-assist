#include "Achievement.h"
#include <iostream>

Achievement::Achievement(std::string name,  std::string desc)
    : achievementName(name), description(desc) {
    // ructor implementation
}

void Achievement::displayAchievement()  {
    std::cout << "Achievement Unlocked: " << achievementName << std::endl;
    std::cout << description << std::endl;
}

std::string Achievement::getName()  {
    return achievementName;
}

std::string Achievement::getDescription()  {
    return description;
}
