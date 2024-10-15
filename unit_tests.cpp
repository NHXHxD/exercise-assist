// tests.cpp

#include <iostream>
#include "MCExercise.h"
#include "TMCExercise.h"
#include "TFExercise.h"
#include "FBExercise.h"

// Testing the MCExercise class
void testMCExercise() {
    std::cout << "\n=== Testing MCExercise ===\n";

        std::cout << "\n--- Test Case "  << " ---\n";

        std::string title;
        std::cout << "Enter title for MCExercise: ";
        std::getline(std::cin, title);
        MCExercise exercise(title);

        std::cout << "Creating exercise with 1 question.\n";
        exercise.createExercise(1); // Manually enter 1 question

        std::cout << "Now, take the exercise.\n";
        exercise.checkAnswer();

        std::cout << "Test Case " << " completed.\n";
    

    std::cout << "MCExercise tests completed.\n";
}

// Testing the TMCExercise class
void testTMCExercise() {
    std::cout << "\n=== Testing TMCExercise ===\n";


        std::cout << "\n--- Test Case " << " ---\n";

        std::string title;
        std::cout << "Enter title for TMCExercise: ";
        std::getline(std::cin, title);
        TMCExercise exercise(title);

        std::cout << "Creating exercise with 1 question.\n";
        exercise.createExercise(1); // Manually enter 1 question

        std::cout << "Now, take the exercise.\n";
        exercise.checkAnswer();

        std::cout << "Test Case "  << " completed.\n";

    std::cout << "TMCExercise tests completed.\n";
}

// Testing the TFExercise class
void testTFExercise() {
    std::cout << "\n=== Testing TFExercise ===\n";

        std::cout << "\n--- Test Case "  << " ---\n";

        std::string title;
        std::cout << "Enter title for TFExercise: ";
        std::getline(std::cin, title);
        TFExercise exercise(title);

        std::cout << "Creating exercise with 1 question.\n";
        exercise.createExercise(1); // Manually enter 1 question

        std::cout << "Now, take the exercise.\n";
        exercise.checkAnswer();

        std::cout << "Test Case "  << " completed.\n";
    

    std::cout << "TFExercise tests completed.\n";
}

// Testing the FBExercise class
void testFBExercise() {
    std::cout << "\n=== Testing FBExercise ===\n";
    std::cout << "\n--- Test Case "  << " ---\n";

    std::string title;
    std::cout << "Enter title for FBExercise: ";
    std::getline(std::cin, title);
    FBExercise exercise(title);

    std::cout << "Creating exercise with 1 question.\n";
    exercise.createExercise(1); // Manually enter 1 question

    std::cout << "Now, take the exercise.\n";
    exercise.checkAnswer();

    std::cout << "Test Case "  << " completed.\n";


    std::cout << "FBExercise tests completed.\n";
}

int main() {
    testMCExercise();
    testTMCExercise();
    testTFExercise();
    testFBExercise();

    std::cout << "\nAll tests completed.\n";
    return 0;
}
