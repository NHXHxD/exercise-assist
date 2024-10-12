#include "DataManager.h"
#include <fstream>
#include <iostream>
#include <sstream>

void DataManager::saveData(const User& user, const std::vector<Skill>& skills) const {
    std::ofstream outFile("userdata.txt");
    if (outFile.is_open()) {
        // Save user data
        outFile << "Username:" << user.getUsername() << std::endl;

        // Save skill time spent
        outFile << "SkillTimeSpent:" << std::endl;
        for (const auto& entry : user.getSkillTimeSpent()) {
            outFile << entry.first << ";" << entry.second << std::endl;
        }
        outFile << "EndSkillTimeSpent" << std::endl;

        // Save achievements
        outFile << "Achievements:" << std::endl;
        for (const auto& achievement : user.getAchievements()) {
            outFile << achievement.getName() << ";" << achievement.getDescription() << std::endl;
        }
        outFile << "EndAchievements" << std::endl;

        // Save skills and their exercises
        outFile << "Skills:" << std::endl;
        for (const auto& skill : skills) {
            outFile << "SkillName:" << skill.getName() << std::endl;
            outFile << "Exercises:" << std::endl;
            for (const auto& exercise : skill.getExercises()) {
                // Serialize each exercise
                // Format: Type;Question;Skills;[SpecificFields]
                if (auto mcq = dynamic_cast<MultipleChoiceExercise*>(exercise)) {
                    outFile << "MultipleChoice;";
                    outFile << mcq->questionText << ";";
                    // Options
                    for (const auto& option : mcq->options) {
                        outFile << option << ",";
                    }
                    outFile << ";";
                    outFile << mcq->correctAnswer << std::endl;
                } else if (auto tf = dynamic_cast<TrueFalseExercise*>(exercise)) {
                    outFile << "TrueFalse;";
                    outFile << tf->questionText << ";";
                    outFile << (tf->correctAnswer ? "True" : "False") << std::endl;
                } else if (auto fib = dynamic_cast<FillInTheBlankExercise*>(exercise)) {
                    outFile << "FillInTheBlank;";
                    outFile << fib->questionText << ";";
                    outFile << fib->correctAnswer << std::endl;
                }
                // Add more exercise types if needed
            }
            outFile << "EndExercises" << std::endl;
        }
        outFile << "EndSkills" << std::endl;

        outFile.close();
        std::cout << "Data saved successfully." << std::endl;
    } else {
        std::cerr << "Error saving data." << std::endl;
    }
}

void DataManager::loadData(User& user, std::vector<Skill>& skills) const {
    std::ifstream inFile("userdata.txt");
    if (inFile.is_open()) {
        std::string line;
        Skill* currentSkill = nullptr;
        while (std::getline(inFile, line)) {
            if (line.find("Username:") == 0) {
                user = User(line.substr(9));
            } else if (line == "SkillTimeSpent:") {
                while (std::getline(inFile, line) && line != "EndSkillTimeSpent") {
                    size_t pos = line.find(';');
                    if (pos != std::string::npos) {
                        std::string skill = line.substr(0, pos);
                        double time = std::stod(line.substr(pos + 1));
                        user.updateSkillTime(skill, time);
                    }
                }
            } else if (line == "SkillExercisesCompleted:") {
                while (std::getline(inFile, line) && line != "EndSkillExercisesCompleted") {
                    size_t pos = line.find(';');
                    if (pos != std::string::npos) {
                        std::string skill = line.substr(0, pos);
                        int count = std::stoi(line.substr(pos + 1));
                        user.updateSkillExercises(skill, count);
                    }
                }
            } else if (line == "Achievements:") {
                while (std::getline(inFile, line) && line != "EndAchievements") {
                    size_t pos = line.find(';');
                    if (pos != std::string::npos) {
                        std::string name = line.substr(0, pos);
                        std::string desc = line.substr(pos + 1);
                        user.earnAchievement(Achievement(name, desc));
                    }
                }
            } else if (line == "Skills:") {
                while (std::getline(inFile, line) && line != "EndSkills") {
                    if (line.find("SkillName:") == 0) {
                        std::string skillName = line.substr(10);
                        skills.emplace_back(skillName);
                        currentSkill = &skills.back();
                    } else if (line == "Exercises:") {
                        while (std::getline(inFile, line) && line != "EndExercises") {
                            std::istringstream iss(line);
                            std::string type;
                            std::getline(iss, type, ';');

                            std::string question;
                            std::getline(iss, question, ';');

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
                                currentSkill->addExercise(new MultipleChoiceExercise(question, options, correctOption, {currentSkill->getName()}));
                            } else if (type == "TrueFalse") {
                                std::string answer;
                                std::getline(iss, answer, ';');
                                bool isTrue = (answer == "True");
                                currentSkill->addExercise(new TrueFalseExercise(question, isTrue, {currentSkill->getName()}));
                            } else if (type == "FillInTheBlank") {
                                std::string correctAnswer;
                                std::getline(iss, correctAnswer, ';');
                                currentSkill->addExercise(new FillInTheBlankExercise(question, correctAnswer, {currentSkill->getName()}));
                            }
                            // Add more exercise types if needed
                        }
                    }
                }
            }
        }
        inFile.close();
        std::cout << "Data loaded successfully." << std::endl;
    } else {
        std::cerr << "Error loading data." << std::endl;
    }
}
