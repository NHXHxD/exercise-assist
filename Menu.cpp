#include "Menu.h"
#include <iostream>
#include <sstream>
#include <algorithm>

void Menu::displayMainMenu(User& user) {
    initializeLessons();

    int choice = 0;
    do {
        std::cout << "\nMain Menu:\n";
        std::cout << "1. Start Lesson\n";
        std::cout << "2. View Progress\n";
        std::cout << "3. Achievements\n";
        std::cout << "4. Save Progress\n";
        std::cout << "5. Load Progress\n";
        std::cout << "6. Create Custom Exercises\n";
        std::cout << "7. Edit Custom Exercises\n";
        std::cout << "8. Exit\n";
        choice = getValidatedInt("Enter your choice: ", 1, 8);

        switch (choice) {
            case 1:
                handleUserSelection(user);
                break;
            case 2:
                user.viewProgress();
                break;
            case 3:
                std::cout << user;
                break;
            case 4:
                dataManager.saveProgress(user, customLesson);
                break;
            case 5:
                dataManager.loadProgress(user, customLesson);
                break;
            case 6:
                createCustomExercises(user);
                break;
            case 7:
                editCustomExercises();
                break;
            case 8:
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please select a valid option." << std::endl;
        }
    } while (choice != 8);
}

void Menu::handleUserSelection(User& user) {
    addCustomLesson(); // Ensure custom lesson is included if it has exercises

    std::cout << "Available Lessons:\n";
    for (size_t i = 0; i < lessons.size(); ++i) {
        std::cout << i + 1 << ". " << lessons[i].getTitle() << std::endl;
    }
    int lessonChoice = getValidatedInt("Enter the number of the lesson you want to start: ", 1, static_cast<int>(lessons.size()));

    lessons[lessonChoice - 1].startLesson(user);
}

void Menu::initializeLessons() {
    // Initialize lessons only once
    if (lessons.empty()) {
        Lesson lesson1("Mathematics Basics", "Learn the fundamentals of mathematics.", {"Mathematics"});
        lesson1.addExercise(new MultipleChoiceExercise(
            "What is 2 + 2?",
            {"1", "2", "3", "4"},
            'D',
            {"Mathematics"}));
        lesson1.addExercise(new TrueFalseExercise(
            "Is 5 a prime number?",
            true,
            {"Mathematics"}));
        lessons.push_back(lesson1);

        Lesson lesson2("Critical Thinking", "Enhance your problem-solving skills.", {"Critical Thinking"});
        lesson2.addExercise(new FillInTheBlankExercise(
            "The sun rises in the ____.",
            "east",
            {"Critical Thinking"}));
        lesson2.addExercise(new TimedMultipleChoiceExercise(
            "What is the next number in the sequence: 2, 4, 6, ?",
            {"7", "8", "9", "10"},
            'B',
            10,
            {"Critical Thinking"}));
        lessons.push_back(lesson2);

        customLesson = Lesson("Custom Exercises", "Your own custom exercises.", {});
    }
}

void Menu::createCustomExercises(User& user) {
    int numExercises = getValidatedInt("How many exercises would you like to create? ", 1, 100);

    for (int i = 0; i < numExercises; ++i) {
        std::cout << "\nCreating Exercise " << i + 1 << ":\n";
        std::cout << "Select exercise type:\n";
        std::cout << "1. Multiple Choice\n";
        std::cout << "2. True/False\n";
        std::cout << "3. Fill in the Blank\n";
        int exerciseType = getValidatedInt("Enter your choice: ", 1, 3);

        std::string question;
        std::vector<std::string> skills;
        std::string skillInput;

        std::cout << "Enter the question/prompt: ";
        std::getline(std::cin, question);

        std::cout << "Enter the skill(s) addressed (separated by commas): ";
        std::getline(std::cin, skillInput);
        // Split skills by commas
        std::istringstream skillStream(skillInput);
        std::string skill;
        while (std::getline(skillStream, skill, ',')) {
            skill.erase(std::remove(skill.begin(), skill.end(), ' '), skill.end()); // Remove spaces
            if (!skill.empty()) {
                skills.push_back(skill);
            }
        }

        switch (exerciseType) {
            case 1: {
                // Multiple Choice
                int numOptions = getValidatedInt("How many options? (2-6): ", 2, 6);

                std::vector<std::string> options;
                for (int j = 0; j < numOptions; ++j) {
                    std::string option;
                    std::cout << "Enter option " << static_cast<char>('A' + j) << ": ";
                    std::getline(std::cin, option);
                    options.push_back(option);
                }

                char correctOption;
                do {
                    std::cout << "Enter the correct option letter (";
                    for (int j = 0; j < numOptions; ++j) {
                        std::cout << static_cast<char>('A' + j);
                        if (j < numOptions - 1) std::cout << ", ";
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

                customLesson.addExercise(new MultipleChoiceExercise(question, options, correctOption, skills));
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
                customLesson.addExercise(new TrueFalseExercise(question, isTrue, skills));
                break;
            }
            case 3: {
                // Fill in the Blank
                std::string correctAnswer;
                std::cout << "Enter the correct answer: ";
                std::getline(std::cin, correctAnswer);
                customLesson.addExercise(new FillInTheBlankExercise(question, correctAnswer, skills));
                break;
            }
            default:
                std::cout << "Invalid exercise type. Skipping this exercise." << std::endl;
                break;
        }
        customLesson.addSkills(skills);
    }

    std::cout << "Custom exercises created successfully!" << std::endl;
}

void Menu::addCustomLesson() {
    // If customLesson has exercises and is not already in the lessons list, add it
    if (!customLesson.getExercises().empty()) {
        bool exists = false;
        for (const auto& lesson : lessons) {
            if (lesson.getTitle() == customLesson.getTitle()) {
                exists = true;
                break;
            }
        }
        if (!exists) {
            lessons.push_back(customLesson);
        }
    }
}

void Menu::editCustomExercises() {
    if (customLesson.getExercises().empty()) {
        std::cout << "No custom exercises to edit." << std::endl;
        return;
    }

    std::cout << "Custom Exercises:\n";
    const auto& exercises = customLesson.getExercises();
    for (size_t i = 0; i < exercises.size(); ++i) {
        std::cout << i + 1 << ". " << exercises[i]->questionText << std::endl;
    }
    std::cout << (exercises.size() + 1) << ". Back to Main Menu\n";
    int choice = getValidatedInt("Enter the number of the exercise to delete (or choose to go back): ", 1, static_cast<int>(exercises.size() + 1));

    if (choice == static_cast<int>(exercises.size() + 1)) {
        return;
    }

    // Delete the selected exercise
    delete exercises[choice - 1];
    customLesson.getExercises().erase(customLesson.getExercises().begin() + (choice - 1));

    std::cout << "Exercise deleted successfully." << std::endl;
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
            std::cout << "Invalid input. Please enter a number between " << min << " and " << max << "." << std::endl;
        }
    }
    return value;
}
