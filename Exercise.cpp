#include "Exercise.h"

Exercise::Exercise(const std::string& question, const std::vector<std::string>& skills)
    : questionText(question), skillsAddressed(skills) {
    // Constructor implementation
}

const std::vector<std::string>& Exercise::getSkills() const {
    return skillsAddressed;
}

Exercise::~Exercise() {
    // Virtual destructor implementation
}
