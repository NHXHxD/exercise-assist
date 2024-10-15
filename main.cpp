#include "User.h"
#include <vector>
#include <iostream>
#include "Achievement.h"
#include "MCExercise.h"
#include "TMCExercise.h"
#include "TFExercise.h"
#include "FBExercise.h"
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
    vector<Exercise*> exercises;
    int choice; 
    while (choice != 7) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Create a New Exercise\n";
        std::cout << "2. Study a Exercise\n";
        std::cout << "3. View Progress\n";
        std::cout << "4. Achievements\n";
        std::cout << "5. Save Data\n";
        std::cout << "6. Load Data\n";
        std::cout << "7. Exit\n";
        if (choice == 1) {
            int ch; 
            while (ch < 1 || ch > 4) { 
                cout << "Which type of exercise would you like to create? (1-4): " << endl;
                cout << "1. Multiple Choice\n";
                cout << "2. Timed Multiple Choice\n";
                cout << "3. True/False\n";
                cout << "4. Fill in the Blank\n";
            }
                int numOfExercise = 0;
                string name;
                cout << "Enter a name for your exercise: " << endl;
                cin >> name;
                while (numOfExercise < 1 || numOfExercise > 100) {
                    cout << "How many questions will your exercise have? (1-100): " << endl;
                    cin >> numOfExercise;
                }
                // create a multiple choice exercise
                if (ch == 1) {
                    Exercise* exercise = new MCExercise(name);
                    exercise->createExercise(numOfExercise);
                    exercises.push_back(exercise);
                }
                /*
                else if (ch == 2) {
                    Exercise* exercise = new TMCExercise(name);
                    exercise->createExercise(numOfExercise);
                    exercises.push_back(exercise);
                }
                */
                // create True False exercise
                else if (ch == 3) {
                    Exercise* exercise = new TFExercise(name);
                    exercise->createExercise(numOfExercise);
                    exercises.push_back(exercise);
                }
                
                // create a fill in the blank exercise
                else if (ch == 4) {
                    Exercise* exercise = new FBExercise(name);
                    exercise->createExercise(numOfExercise);
                    exercises.push_back(exercise);
                }
               
}
        else if (choice == 2) {
            if (exercises.size() == 0) {
                cout << "There is no available exercises. Please create more exercises!\n";
            }

            for (int i = 0; i < exercises.size();i++) {
                cout << i + 1 << ". "<< exercises[i]->getTitle() << endl;
            }
            cout << "Select an exercise: \n";
            int c;
            cin >> c;
            int point = exercises[c]->checkAnswer();
        }
        else if (choice == 3) {
            user.viewProgress();
}
        else if (choice == 4) {
            vector<Achievement> achievement = user.getAchievements();
            for (int i = 0; i < achievement.size(); i++) {
                achievement[i].displayAchievement();
            }

        }
        else if (choice == 7) {
            std::cout << "Exiting the application." << std::endl;
            break;
    }
        else {
                    std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
        }

    return 0;
}
