#include "Menu.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>

void Menu::displayMainMenu(User& user) {
    int choice = 0;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Create a New Skill\n";
        std::cout << "2. Add Exercises to a Skill\n";
        std::cout << "3. Study a Skill\n";
        std::cout << "4. View Progress\n";
        std::cout << "5. Achievements\n";
        std::cout << "6. Save Data\n";
        std::cout << "7. Load Data\n";
        std::cout << "8. Exit\n";
        int choice;
        std::cin >> choice;
        switch (choice) {
            case 1:
                createSkill();
                break;
            case 2:
                addExercisesToSkill();
                break;
            case 3:
                studySkill(user);
                break;
            case 4:
                user.viewProgress();
                break;
            case 5:
                user.getAchievements();
                break;
            case 6:
                saveData(user);
                break;
            case 7:
                loadData(user);
                break;
            case 8:
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    } while (choice != 8);
}

void Menu::createSkill() {
    std::cout << "Enter the name of the new skill: ";
    std::string skillName;
    std::getline(std::cin, skillName);
    if (skillName.empty()) {
        std::cout << "Skill name cannot be empty." << std::endl;
        return;
    }
    // Check if skill already exists
    for (const auto& skill : skills) {
        if (skill.getName() == skillName) {
            std::cout << "Skill already exists." << std::endl;
            return;
        }
    }
    skills.emplace_back(skillName);
    std::cout << "Skill '" << skillName << "' created successfully." << std::endl;
}

void Menu::addExercisesToSkill() {
    if (skills.empty()) {
        std::cout << "No skills available. Please create a skill first." << std::endl;
        return;
    }
    std::cout << "Select a skill to add exercises to:" << std::endl;
    for (size_t i = 0; i < skills.size(); ++i) {
        std::cout << i + 1 << ". " << skills[i].getName() << std::endl;
    }
    int choice;
    std::cin >> choice;

    Skill& selectedSkill = skills[choice - 1];

    int numExercises;
    std::cin >> numExercises;

    // choose exercise to create
    for (int i = 0; i < numExercises; i++) {
        std::cout << "\nCreating Exercise " << i + 1 << " for skill '" << selectedSkill.getName() << "':\n";
        std::cout << "Select exercise type:\n";
        std::cout << "1. Multiple Choice\n";
        std::cout << "2. True/False\n";
        std::cout << "3. Fill in the Blank\n";
        int exerciseType;
        std::cin >> exerciseType;
        std::string question;
        std::cout << "Enter the question/prompt: ";
        std::getline(std::cin, question);

        switch (exerciseType) {
            case 1: {
                // Multiple Choice (A - B - C - D)
                std::vector<std::string> options;
                for (int j = 0; j < 4; ++j) {
                    std::string option;
                    std::cout << "Enter option " << static_cast<char>('A' + j) << ": ";
                    std::getline(std::cin, option);
                    options.push_back(option);
                }

                char correctOption;
                do {
                    std::cout << "Enter the correct option letter (";
                    for (int j = 0; j < 4; ++j) {
                        std::cout << static_cast<char>('A' + j);
                        if (j < 4 - 1) std::cout << ", ";
                    }
                    std::cout << "): ";
                    std::string input;
                    std::getline(std::cin, input);
                    if (!input.empty()) {
                        correctOption = toupper(input[0]);
                        if (correctOption >= 'A' && correctOption < 'A' + numOptions) {
                            break;
                        }
                    }
                    std::cout << "Invalid option. Please try again." << std::endl;
                } while (true);

                selectedSkill.addExercise(new MultipleChoiceExercise(question, options, correctOption, selectedSkill.getName()));
                break;
            }
            case 2: {
                // True/False
                std::string answer;
                do {
                    std::cout << "Enter the correct answer (True/False): ";
                    std::getline(std::cin, answer);
                    std::transform(answer.begin(), answer.end(), answer.begin(), ::tolower);
                } while (answer != "true" && answer != "false");
                bool isTrue = (answer == "true");
                selectedSkill.addExercise(new TrueFalseExercise(question, isTrue, selectedSkill.getName()));
                break;
            }
            case 3: {
                // Fill in the Blank
                std::string correctAnswer;
                std::cout << "Enter the correct answer: ";
                std::getline(std::cin, correctAnswer);
                selectedSkill.addExercise(new FillInTheBlankExercise(question, correctAnswer, selectedSkill.getName()));
                break;
            }
            default:
                std::cout << "Invalid exercise type. Skipping this exercise." << std::endl;
                break;
        }
    }

    std::cout << "Exercises added to skill '" << selectedSkill.getName() << "' successfully!" << std::endl;
}

void Menu::studySkill(User& user) {
    if (skills.empty()) {
        std::cout << "No skills available. Please create a skill first." << std::endl;
        return;
    }
    std::cout << "Select a skill to study:" << std::endl;
    for (size_t i = 0; i < skills.size(); ++i) {
        std::cout << i + 1 << ". " << skills[i].getName() << std::endl;
    }
    int choice = getValidatedInt("Enter your choice: ", 1, static_cast<int>(skills.size()));
    Skill& selectedSkill = skills[choice - 1];

    if (selectedSkill.getExercises().empty()) {
        std::cout << "No exercises available for this skill. Please add exercises first." << std::endl;
        return;
    }

    std::cout << "Starting study session for skill: " << selectedSkill.getName() << std::endl;

    int correctAnswers = 0;
    auto startTime = std::chrono::steady_clock::now();

    for (auto exercise : selectedSkill.getExercises()) {
        exercise->presentExercise();
        std::string userAnswer;
        std::getline(std::cin, userAnswer);

        bool isCorrect = exercise->checkAnswer(userAnswer);
        if (isCorrect) {
            std::cout << "Correct!" << std::endl;
            correctAnswers++;
        } else {
            std::cout << "Incorrect." << std::endl;
        }
    }

    auto endTime = std::chrono::steady_clock::now();
    std::chrono::duration<double> elapsedSeconds = endTime - startTime;

    user.updateSkillTime(selectedSkill.getName(), elapsedSeconds.count());

    std::cout << "Study session completed. Your score: " << correctAnswers << "/" << selectedSkill.getExercises().size() << std::endl;

    checkAchievements(user, selectedSkill.getName());
}

int Menu::getValidatedInt(const std::string& prompt, int min, int max) {
    int value;
    while (true) {
        std::cout << prompt;
        std::string input;
        std::getline(std::cin, input);
        std::stringstream ss(input);
        if (ss >> value && value >= min && value <= max) {
            break;
        } else {
            std::cout << "Invalid input. Plea
