#ifndef ACHIEVEMENT_H
#define ACHIEVEMENT_H

#include <string>

/**
 * @brief Class representing an achievement.
 */
class Achievement {
public:
    /**
     * @brief Constructs an Achievement with the given parameters.
     * @param name The name of the achievement.
     * @param description The description of the achievement.
     */
    Achievement(const std::string& name, const std::string& description);

    /**
     * @brief Displays the achievement.
     */
    void displayAchievement() const;

    /**
     * @brief Gets the name of the achievement.
     * @return The name of the achievement.
     */
    std::string getName() const;

    /**
     * @brief Gets the description of the achievement.
     * @return The description of the achievement.
     */
    std::string getDescription() const;

private:
    std::string achievementName;
    std::string description;
};

#endif // ACHIEVEMENT_H
