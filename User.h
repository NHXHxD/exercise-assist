#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Achievement.h"

class Lesson; // Forward declaration

/**
 * @brief Class representing a user profile.
 */
class User {
public:
    /**
     * @brief Constructs a User with the given username.
     * @param username The username of the user.
     */
    User(const std::string& username);

    /**
     * @brief Starts a lesson for the user.
     * @param lesson The lesson to start.
     */
    void startLesson(Lesson& lesson);

    /**
     * @brief Updates the user's skill proficiency.
     * @param skill The skill to update.
     * @param points The points to add to the skill proficiency.
     */
    void updateSkillProficiency(const std::string& skill, int points);

    /**
     * @brief Updates the time spent on a skill.
     * @param skill The skill to update.
     * @param time The time to add (in seconds).
     */
    void updateSkillTime(const std::string& skill, double time);

    /**
     * @brief Displays the user's progress.
     */
    void viewProgress() const;

    /**
     * @brief Awards an achievement to the user.
     * @param achievement The achievement to award.
     */
    void earnAchievement(const Achievement& achievement);

    /**
     * @brief Overloads the << operator to display user information.
     */
    friend std::ostream& operator<<(std::ostream& os, const User& user);

    /**
     * @brief Gets the username of the user.
     * @return The username.
     */
    std::string getUsername() const;

    /**
     * @brief Gets the user's achievements.
     * @return A vector of achievements.
     */
    const std::vector<Achievement>& getAchievements() const;

    /**
     * @brief Gets the user's skill proficiency.
     * @return A map of skill names to proficiency points.
     */
    const std::map<std::string, int>& getSkillProficiency() const;

    /**
     * @brief Gets the user's skill time spent.
     * @return A map of skill names to time spent.
     */
    const std::map<std::string, double>& getSkillTimeSpent() const;

private:
    std::string username;
    std::vector<Achievement> achievements;
    std::map<std::string, int> skillProficiency; // Skill name to points
    std::map<std::string, double> skillTimeSpent; // Skill name to time in seconds
};

#endif // USER_H
