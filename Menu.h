#ifndef MENU_H
#define MENU_H

#include "User.h"
#include "Lesson.h"
#include "DataManager.h"
#include <vector>

/**
 * @brief Class responsible for displaying menus and handling user input.
 */
class Menu {
public:
    /**
     * @brief Displays the main menu to the user.
     * @param user The user interacting with the menu.
     */
    void displayMainMenu(User& user);

    /**
     * @brief Handles the user's selection from the main menu.
     * @param user The user interacting with the menu.
     */
    void handleUserSelection(User& user);

private:
    std::vector<Lesson> lessons;
    DataManager dataManager;
    Lesson customLesson; // Lesson to hold custom exercises

    /**
     * @brief Initializes available lessons.
     */
    void initializeLessons();

    /**
     * @brief Allows the user to create custom exercises.
     * @param user The user creating exercises.
     */
    void createCustomExercises(User& user);

    /**
     * @brief Adds the custom lesson to the lessons list if it has exercises.
     */
    void addCustomLesson();

    /**
     * @brief Edits custom exercises.
     */
    void editCustomExercises();

    /**
     * @brief Validates integer input.
     * @param prompt The prompt to display.
     * @param min The minimum acceptable value.
     * @param max The maximum acceptable value.
     * @return The validated integer.
     */
    int getValidatedInt(const std::string& prompt, int min, int max);
};

#endif // MENU_H
