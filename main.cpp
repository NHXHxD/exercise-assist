#include "User.h"
#include <vector>
#include <iostream>
#include "Achievement.h"
using namespace std;
int main() {
    std::cout << "Welcome to SkillMaster!" << std::endl;
    std::cout << "Enter your username: ";
    std::string username;
    std::getline(std::cin, username);

    while (username.empty()) {
        std::cout << "Username cannot be empty. Please enter a valid username: ";
        std::getline(std::cin, username);
    }

    User user(username);
    int choice; 
    while (choice != 8) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Create a New Skill\n";
        std::cout << "2. Add Exercises to a Skill\n";
        std::cout << "3. Study a Skill\n";
        std::cout << "4. View Progress\n";
        std::cout << "5. Achievements\n";
        std::cout << "6. Save Data\n";
        std::cout << "7. Load Data\n";
        std::cout << "8. Exit\n";
        switch (choice) {
            case 1:
                user.createSkill();
                break;
            case 2:
                user.addExercisesToSkill();
                break;
            case 3:
                user.studySkill();
                break;
            case 4:
                user.viewProgress();
                break;
            case 5:
                vector<Achievement> achievement = user.getAchievements();
                for (int i = 0; i < achievement.size(); i++) {
                    achievement[i].displayAchievement();
                }
                break;
            case 6:
                //saveData(user);
                break;
            case 7:
                //loadData(user);
                break;
            case 8:
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
    }


    return 0;
}
