#include "Menu.h"
#include <iostream>

int main() {
    std::cout << "Welcome to SkillMaster!" << std::endl;
    std::cout << "Enter your username: ";
    std::string username;
    std::getline(std::cin, username);

    while (username.empty()) {
        std::cout << "Username cannot be empty. Please enter a valid username: ";
        std::getline(std::cin, username);
    }

    User user(username);
    Menu menu;
    menu.displayMainMenu(user);

    return 0;
}
