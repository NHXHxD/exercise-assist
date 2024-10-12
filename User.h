#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Achievement.h"


// Class representing a user profile.
class User {
    protected:
        std::string username;
        std::vector<Achievement> achievements;
        int numOfAch;
        std::map<std::string, int> skillProficiency; // Skill name to points
        std::map<std::string, double> skillTimeSpent; // Skill name to time in seconds
        int correct;
    public:
        User(const std::string& username);


        // Updates the user's skill proficiency.
        void updateSkillProficiency(const std::string& skill);

        // Updates the time spent on a skill.
        void updateSkillTime(const std::string& skill, double time);


        // Displays the user's progress.
        void viewProgress() const;


        // Gets the username of the user.

        std::string getUsername() const;
        // earn achievement
        void earnAchievement(const Achievement& achievement) {

        // increase the number of corect choices
        void correctChoice();

        // Gets the user's achievements.
        std::vector<Achievement>& getAchievements();

        // Gets the user's skill proficiency.
        std::map<std::string, int>& getSkillProficiency();

        // Gets the user's skill time spent.
        std::map<std::string, double>& getSkillTimeSpent();


};

#endif 
