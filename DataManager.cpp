#include "DataManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

void DataManager::saveProgress(const User& user, const Lesson& customLesson) const {
    std::ofstream outFile("userdata.txt");
    if (outFile.is_open()) {
        // Save user data
        outFile << "Username:" << user.getUsername() << std::endl;

        // Save achievements
        outFile << "Achievements:" << std::endl;
        for (const auto& achievement : user.getAchievements()) {
            outFile << achievement.getName() << ";" << achievement.getDescription() << std::endl;
        }
        outFile << "EndAchievements" << std::endl;

        // Save skill proficiency
        outFile << "SkillProficiency:" << std::endl;
        for (const auto& entry : user.getSkillProficiency()) {
            outFile << entry.first << ";" << entry.second << std::endl;
        }
        outFile << "EndSkillProficiency" << std::endl;

        // Save skill time spent
        outFile << "SkillTimeSpent:" << std::endl;
        for (const auto& entry : user.getSkillTimeSpent()) {
            outFile << entry.first << ";" << entry.second << std::endl;
        }
        outFile << "EndSkillTimeSpent" << std::endl;

        // Save custom exercises
        outFile << "CustomExercises:" << std::endl;
        for (const auto& exercise : customLesson.getExercises()) {
            // Serialize each exercise
            // Format: Type;Question;Skills;[SpecificFields]
            if (auto mcq = dynamic_cast<MultipleChoiceExercise*>(exercise)) {
                outFile << "MultipleChoice;";
                outFile << mcq->questionText << ";";
                // Skills
                for (const auto& skill : mcq->skillsAddressed) {
                    outFile << skill << ",";
                }
                outFile << ";";
                // Options
                for (const auto& option : mcq->options) {
                    outFile << option << ",";
                }
                outFile << ";";
                outFile << mcq->correctAnswer << std::endl;
            } else if (auto tf = dynamic_cast<TrueFalseExercise*>(exercise)) {
                outFile << "TrueFalse;";
                outFile << tf->questionText << ";";
                // Skills
                for (const auto& skill : tf->skillsAddressed) {
                    outFile << skill << ",";
                }
                outFile << ";";
                outFile << (tf->correctAnswer ? "True" : "False") << std::endl;
            } else if (auto fib = dynamic_cast<FillInTheBlankExercise*>(exercise)) {
                outFile << "FillInTheBlank;";
                outFile << fib->questionText << ";";
                // Skills
                for (const auto& skill : fib->skillsAddressed) {
                    outFile << skill << ",";
                }
                outFile << ";";
                outFile << fib->correctAnswer << std::endl;
            }
            // Add more exercise types if needed
        }
        outFile << "EndCustomExercises" << std::endl;

        outFile.close();
        std::cout << "Progress saved successfully." << std::endl;
    } else {
        std::cerr << "Error saving progress." << std::endl;
    }
}

void DataManager::loadProgress(User& user, Lesson& customLesson) const {
    std::ifstream inFile("userdata.txt");
    if (inFile.is_open()) {
        std::string line;
        while (std::getline(inFile, line)) {
            if (line.find("Username:") == 0) {
                user = User(line.substr(9));
            } else if (line == "Achievements:") {
                while (std::getline(inFile, line) && line != "EndAchievements") {
                    size_t pos = line.find(';');
                    if (pos != std::string::npos) {
                        std::string name = line.substr(0, pos);
                        std::string desc = line.substr(pos + 1);
                        user.earnAchievement(Achievement(name, desc));
                    }
                }
            } else if (line == "SkillProficiency:") {
                while (std::getline(inFile, line) && line != "EndSkillProficiency") {
                    size_t pos = line.find(';');
                    if (pos != std::string::npos) {
                        std::string skill = line.substr(0, pos);
                        int points = std::stoi(line.substr(pos + 1));
                        user.updateSkillProficiency(skill, points);
                    }
                }
            } else if (line == "SkillTimeSpent:") {
                while (std::getline(inFile, line) && line != "EndSkillTimeSpent") {
                    size_t pos = line.find(';');
                    if (pos != std::string::npos) {
                        std::string skill = line.substr(0, pos);
                        double time = std::stod(line.substr(pos + 1));
                        user.updateSkillTime(skill, time);
                    }
                }
            } else if (line == "CustomExercises:") {
                customLesson.clearExercises();
                while (std::getline(inFile, line) && line != "EndCustomExercises") {
                    std::istringstream iss(line);
                    std::string type;
                    std::getline(iss, type, ';');

                    std::string question;
                    std::getline(iss, question, ';');

                    std::string skillsStr;
                    std::getline(iss, skillsStr, ';');
                    std::vector<std::string> skills;
                    std::istringstream skillsStream(skillsStr);
                    std::string skill;
                    while (std::getline(skillsStream, skill, ',')) {
                        if (!skill.empty()) {
                            skills.push_back(skill);
                        }
                    }

                    if (type == "MultipleChoice") {
                        std::string optionsStr;
                        std::getline(iss, optionsStr, ';');
                        std::vector<std::string> options;
                        std::istringstream optionsStream(optionsStr);
                        std::string option;
                        while (std::getline(optionsStream, option, ',')) {
                            if (!option.empty()) {
                                options.push_back(option);
                            }
                        }
                        char correctOption;
                        iss >> correctOption;
                        customLesson.addExercise(new MultipleChoiceExercise(question, options, correctOption, skills));
                    } else if (type == "TrueFalse") {
                        std::string answer;
                        std::getline(iss, answer, ';');
                        bool isTrue = (answer == "True");
                        customLesson.addExercise(new TrueFalseExercise(question, isTrue, skills));
                    } else if (type == "FillInTheBlank") {
                        std::string correctAnswer;
                        std::getline(iss, correctAnswer, ';');
                        customLesson.addExercise(new FillInTheBlankExercise(question, correctAnswer, skills));
                    }
                    // Add more exercise types if needed
                }
            }
        }
        inFile.close();
        std::cout << "Progress loaded successfully." << std::endl;
    } else {
        std::cerr << "Error loading progress." << std::endl;
    }
}
