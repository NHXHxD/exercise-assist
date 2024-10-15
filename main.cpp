#include "User.h"
#include <vector>
#include <iostream>
#include "Achievement.h"
#include "MCExercise.h"
#include "TFExercise.h"
#include "FBExercise.h"
#include "TMCExercise.h"
using namespace std;

int main() {
    std::cout << "Welcome to ExerciseAssist!" << std::endl;
    std::cout << "Enter your username: ";
    std::string username;
    cin >> username;
    while (username.empty()) {
        std::cout << "Username cannot be empty. Please enter a valid username: ";
        std::getline(std::cin, username);
    }

    User user(username);
    vector<Exercise*> exercises;
    int choice = 0;  // Initialize choice to prevent undefined behavior

    while (choice != 6) {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Create a New Exercise\n";
        std::cout << "2. Study a Exercise\n";
        std::cout << "3. Achievements\n";
        std::cout << "4. Save Data\n";
        std::cout << "5. Load Data\n";
        std::cout << "6. Exit\n";
        std::cout << "Enter your choice: ";
        cin >> choice;  // Get user input for choice

        if (choice == 1) {
            int ch = 0;  // Initialize ch to prevent undefined behavior
            while (ch < 1 || ch > 4) {
                cout << "Which type of exercise would you like to create? (1-4): " << endl;
                cout << "1. Multiple Choice\n";
                cout << "2. Timed Multiple Choice\n";
                cout << "3. True/False\n";
                cout << "4. Fill in the Blank\n";
                cout << "Enter your choice: ";
                cin >> ch;  // Get user input for ch
            }

            int numOfExercise = 0;
            string name;
            cout << "Enter a name for your exercise: ";
            cin >> name;
            while (numOfExercise < 1 || numOfExercise > 100) {
                cout << "How many questions will your exercise have? (1-100): ";
                cin >> numOfExercise;
            }

            // Create an exercise based on the user's choice
            if (ch == 1) {
                Exercise* exercise = new MCExercise(name);
                exercise->createExercise(numOfExercise);
                exercises.push_back(exercise);
            }
            if (ch == 2) {
                Exercise* exercise = new TMCExercise(name);
                exercise->createExercise(numOfExercise);
                exercises.push_back(exercise);
            }
            else if (ch == 3) {
                Exercise* exercise = new TFExercise(name);
                exercise->createExercise(numOfExercise);
                exercises.push_back(exercise);
            }
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
            else {
                for (int i = 0; i < exercises.size(); i++) {
                    cout << i + 1 << ". " << exercises[i]->getTitle() << endl;
                }
                cout << "Select an exercise: ";
                int c;
                cin >> c;
                while (c < 1 || c > exercises.size()) {
                    cout << "Invalid input! Please select an exercise: ";
                    cin >> c;
                }
                int point = exercises[c - 1]->checkAnswer();  // Adjusted index to c - 1
                user.correctChoice(point);
                user.earnAchievement();
            }
        }
        else if (choice == 3) {
            vector<Achievement> achievement = user.getAchievements();
            for (int i = 0; i < achievement.size(); i++) {
                achievement[i].displayAchievement();
            }
        }
        else if (choice == 6) {
            // Free the memory allocated for the exercises
            for (Exercise* exercise : exercises) {
                delete exercise;
    }
            std::cout << "Exiting the application." << std::endl;
            break;
        }
        else {
            std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    }

    return 0;
}
