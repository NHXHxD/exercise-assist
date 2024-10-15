// tests.cpp

#include <iostream>
#include "MCExercise.h"
#include "TMCExercise.h"
#include "TFExercise.h"
#include "FBExercise.h"

void testMCExercise() {
    std::cout << "Testing MCExercise...\n";
    std::string title;
    std::cout << "Enter title for MCExercise: ";
    std::getline(std::cin, title);
    MCExercise exercise(title);
    exercise.createExercise(1); // Manually enter 1 question
    exercise.checkAnswer();
    std::cout << "MCExercise test completed.\n";
}

void testTMCExercise() {
    std::cout << "Testing TMCExercise...\n";
    std::string title;
    std::cout << "Enter title for TMCExercise: ";
    std::getline(std::cin, title);
    TMCExercise exercise(title);
    exercise.createExercise(1); // Manually enter 1 question
    exercise.checkAnswer();
    std::cout << "TMCExercise test completed.\n";
}

void testTFExercise() {
    std::cout << "Testing TFExercise...\n";
    std::string title;
    std::cout << "Enter title for TFExercise: ";
    std::getline(std::cin, title);
    TFExercise exercise(title);
    exercise.createExercise(1); // Manually enter 1 question
    exercise.checkAnswer();
    std::cout << "TFExercise test completed.\n";
}

void testFBExercise() {
    std::cout << "Testing FBExercise...\n";
    std::string title;
    std::cout << "Enter title for FBExercise: ";
    std::getline(std::cin, title);
    FBExercise exercise(title);
    exercise.createExercise(1); // Manually enter 1 question
    exercise.checkAnswer();
    std::cout << "FBExercise test completed.\n";
}

int main() {
    testMCExercise();
    testTMCExercise();
    testTFExercise();
    testFBExercise();
    std::cout << "All tests completed.\n";
    return 0;
}
