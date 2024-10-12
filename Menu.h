#ifndef MENU_H
#define MENU_H

#include "User.h"
#include "DataManager.h"
#include <vector>

/**
 * @brief Class responsible for displaying menus and handling user input.
 */
class Menu {
public:
    // display menu for user
    void displayMainMenu(User& user);
void User::updateSkillProficiency(const std::string& skill) {
private:
    std::vector<Skill> skills;
    DataManager dataManager;

    // Allows the user to create a new skill.

    void createSkill();

    // add exercises to a skill
    void addExercisesToSkill();

    // study a skill
    void studySkill(User& user);

    // saves data
    void saveData(const User& user);

    // loads data
    void loadData(User& user);

    // check the achievements
    void checkAchievements(User& user, const std::string& skillName);
};

#endif // MENU_H
