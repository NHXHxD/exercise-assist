#ifndef LESSON_H
#define LESSON_H

#include <string>
#include <vector>
#include "Exercise.h"

class User; // Forward declaration

/**
 * @brief Class representing a lesson containing exercises.
 */
class Lesson {
public:
    /**
     * @brief Constructs a Lesson with the given title and description.
     * @param title The title of the lesson.
     * @param description The description of the lesson.
     * @param skills The skills covered in the lesson.
     */
    Lesson(const std::string& title, const std::string& description, const std::vector<std::string>& skills);

    /**
     * @brief Starts the lesson for the given user.
     * @param user The user taking the lesson.
     */
    void startLesson(User& user);

    /**
     * @brief Adds an exercise to the lesson.
     * @param exercise A pointer to the exercise to add.
     */
    void addExercise(Exercise* exercise);

    /**
     * @brief Displays information about the lesson.
     */
    void displayLessonInfo() const;

    /**
     * @brief Gets the title of the lesson.
     * @return The lesson title.
     */
    std::string getTitle() const;

    /**
     * @brief Gets the skills covered by the lesson.
     * @return A vector of skill names.
     */
    const std::vector<std::string>& getSkills() const;

    /**
     * @brief Gets the exercises in the lesson.
     * @return A vector of pointers to exercises.
     */
    const std::vector<Exercise*>& getExercises() const;

    /**
     * @brief Clears the exercises in the lesson.
     */
    void clearExercises();

    /**
     * @brief Adds skills to the lesson's skillsCovered.
     * @param skills The skills to add.
     */
    void addSkills(const std::vector<std::string>& skills);

private:
    std::string title;
    std::string description;
    std::vector<Exercise*> exercises;
    std::vector<std::string> skillsCovered;
};

#endif // LESSON_H
