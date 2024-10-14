#include "User.h"
#include <vector>
#include <iostream>
#include "Achievement.h"
using namespace std;
int main() {
    std::cout << "Welcome to SkillMaster!" << std::endl;
    std::cout << "Enter your username: ";
    std::string username;
    cin >> username;
    while (username.empty()) {
        std::cout << "Username cannot be empty. Please enter a valid username: ";
        std::getline(std::cin, username);
    }

    User user(username);
    vector<Exercise*> exercise;
    int choice; 
    while (choice != 8) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Create a New Exercise\n";
        std::cout << "3. Study a Exercise\n";
        std::cout << "4. View Progress\n";
        std::cout << "5. Achievements\n";
        std::cout << "6. Save Data\n";
        std::cout << "7. Load Data\n";
        std::cout << "8. Exit\n";
        switch (choice) {
            case 1:
            int ch; 
            while (ch < 1 || ch > 4) { 
                cout << "Which type of exercise would you like to create? (1-4): " << endl;
                cout << "1. Multiple Choice\n";
                cout << "2. Timed Multiple Choice\n";
                cout << "3. True/False\n";
                cout << "4. Fill in the Blank\n";
                int numOfExercise = 0;
                string name;
                cout << "Enter a name for your exercise: " << endl;
                cin >> name;
                while (numOfExercise < 1 || numOfExercise > 100) {
                    cout << "How many questions will your exercise have? (1-100): " << endl;
                    cin >> numOfExercise;
                }
                switch (ch) {
                    case 1:
               }

            }
            if (choice == 1) {
                
            } 
            else if (choice == 2) {

            }
            else if (choice == 3) {

            }
            else if (choice == 4) {

            }
        }                   
                break;
            case 2:
                user.addExercise();
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
