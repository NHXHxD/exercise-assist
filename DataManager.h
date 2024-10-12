#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "User.h"
#include "Lesson.h"
#include <vector>

/**
 * @brief Class responsible for saving and loading user data.
 */
class DataManager {
public:
    /**
     * @brief Saves the user's progress and custom lessons to a file.
     * @param user The user whose progress is to be saved.
     * @param customLesson The custom lesson to save.
     */
    void saveProgress(const User& user, const Lesson& customLesson) const;

    /**
     * @brief Loads the user's progress and custom lessons from a file.
     * @param user The user whose progress is to be loaded.
     * @param customLesson The custom lesson to load.
     */
    void loadProgress(User& user, Lesson& customLesson) const;
};

#endif // DATAMANAGER_H
