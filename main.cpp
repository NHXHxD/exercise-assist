#include "Menu.h"
#include <iostream>
using namespace std;

int main() {
    cout << "Welcome to your Educational Assistant!" << endl;
    cout << "Enter your username: ";
    string username;
    getline(cin, username);

    while (username.empty()) {
        cout << "Username cannot be empty. Please enter a valid username: ";
        getline(cin, username);
    }

    User user(username);
    Menu menu;
    menu.displayMainMenu(user);

    return 0;
}
