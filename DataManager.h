#ifndef DATAMANAGER_H
#define DATAMANAGER_H

#include "User.h"
#include <vector>

/**
 * @brief Class responsible for saving and loading user data.
 */
class DataManager {
public:
    /**
     * @brief Saves the user's progress and skills to a file.
     * @param user The user whose progress is to be saved.
     * @param skills The skills to save.
     */
    void saveData(const User& user) const;

    /**
     * @brief Loads the user's progress and skills from a file.
     * @param user The user whose progress is to be loaded.
     * @param skills The skills to load.
     */
    void loadData(User& user) const;
};

#endif // DATAMANAGER_H
