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
        std::map<std::string, int> skillProficiency; // Skill name to points
        std::map<std::string, double> skillTimeSpent; // Skill name to time in seconds
        int correct;
    public:
        // constructor
        User(std::string& username);

        // create a skill for user
        void createSkill();

        // add exercises to the skill
        void addExercisesToSkill();

        // study the skill
        void studySkill();

        // view user's progress
        void viewProgress();

        // Updates the user's skill proficiency.
        void updateSkillProficiency(std::string& skill);

        // Updates the time spent on a skill.
        void updateSkillTime(std::string& skill, double time);


        // Displays the user's progress.
        void viewProgress();


        // Gets the username of the user.

        std::string getUsername() ;
        // earn achievement
        void earnAchievement();

        // increase the number of corect choices
        void correctChoice();

        // Gets the user's achievements.
        std::vector<Achievement> getAchievements();

        // Gets the user's skill proficiency.
        std::map<std::string, int>& getSkillProficiency();

        // Gets the user's skill time spent.
        std::map<std::string, double>& getSkillTimeSpent();

        
};

#endif USER_H
