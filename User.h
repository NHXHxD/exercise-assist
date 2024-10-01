#ifndef USER_H
#define USER_H
#include <iostream>
#include <map>
#include <string>
class User {
    private: 
        std::string username;
        std::map<std::string, int> skillProficiency; // Maps Skill objects to proficiency points.
        std::map<std::string, double> skillTimeSpent; // Maps Skill objects to time spent.


};

#endif