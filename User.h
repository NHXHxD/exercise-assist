#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Achievement.h"
#include "Exercise.h"

// Remove 'using namespace std;' from header files to avoid namespace pollution.

class User {
protected:
    std::string username;
    std::vector<Achievement> achievements;
    std::vector<Exercise*> exercises;
    std::map<std::string, double> timeSpent; // Skill name to time in seconds
    int correct;

public:
    // Constructor
    User(std::string username);

    // Gets vector of exercises
    std::vector<Exercise*> getExercises();

    // Gets the username of the user.
    std::string getUsername();

    // Earn achievement
    void earnAchievement();

    // Increase the number of correct choices
    void correctChoice(int point);

    // Gets the user's achievements.
    std::vector<Achievement> getAchievements();

    // Helper function to check if an achievement has already been earned
    bool hasAchievement(const std::string& name);
};

#endif // USER_H
