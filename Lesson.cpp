#include "Lesson.h"
#include "User.h"
#include <iostream>
#include <algorithm>

Lesson::Lesson(const std::string& lessonTitle, const std::string& lessonDescription, const std::vector<std::string>& skills)
    : title(lessonTitle), description(lessonDescription), skillsCovered(skills) {
    // Constructor implementation
}

void Lesson::startLesson(User& user) {
    std::cout << "Starting lesson: " << title << std::endl;
    std::cout << description << std::endl;

    int correctAnswers = 0;
    for (auto exercise : exercises) {
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

        // Update user's skill proficiency and time
        for (const auto& skill : exercise->getSkills()) {
            user.updateSkillProficiency(skill, isCorrect ? 10 : 0); // Arbitrary points
            user.updateSkillTime(skill, 5); // Arbitrary time in seconds
        }
    }

    std::cout << "Lesson completed. Your score: " << correctAnswers << "/" << exercises.size() << std::endl;

    // Check for achievements
    if (correctAnswers == static_cast<int>(exercises.size())) {
        user.earnAchievement(Achievement("Perfect Score", "You answered all questions correctly in a lesson!"));
    }

    // Clean up exercises
    for (auto exercise : exercises) {
        delete exercise;
    }
    exercises.clear();
}

void Lesson::addExercise(Exercise* exercise) {
    exercises.push_back(exercise);
}

void Lesson::displayLessonInfo() const {
    std::cout << "Lesson: " << title << std::endl;
    std::cout << description << std::endl;
    std::cout << "Number of exercises: " << exercises.size() << std::endl;
}

std::string Lesson::getTitle() const {
    return title;
}

const std::vector<std::string>& Lesson::getSkills() const {
    return skillsCovered;
}

const std::vector<Exercise*>& Lesson::getExercises() const {
    return exercises;
}

void Lesson::clearExercises() {
    for (auto exercise : exercises) {
        delete exercise;
    }
    exercises.clear();
}

void Lesson::addSkills(const std::vector<std::string>& skills) {
    skillsCovered.insert(skillsCovered.end(), skills.begin(), skills.end());
    // Remove duplicates
    std::sort(skillsCovered.begin(), skillsCovered.end());
    skillsCovered.erase(std::unique(skillsCovered.begin(), skillsCovered.end()), skillsCovered.end());
}
