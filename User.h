#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include "Achievement.h"
#include "Exercise.h"
using namespace std;

// Class representing a user profile.
class User {
    protected:
        std::string username;
        std::vector<Achievement> achievements;
        vector<Exercise*> exercises; 
        std::map<std::string, int> proficiency; // Skill name to points
        std::map<std::string, double> timeSpent; // Skill name to time in seconds
        int correct;
    public:
        // constructor
        User(std::string& username);

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

        // Gets vector of exercises
        vector<Exercise*> getExercises();
         

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
