# ExerciseAssist

ExerciseAssist is a program to gamify learning exercises. ExerciseAssist helps to create exercises, with multiple options to choose from: Multiple choice, timed multiple choice, True False, Fill in the Blank exercise.
## Installation
### Prerequisites

- **C++ Compiler:** Ensure you have a C++11 compatible compiler installed (e.g., `g++`).
- **Make:** You should have `make` installed to use the provided Makefile.

Type "make" into the command panel to compile the program

```bash
make
```

## Architecture Overview

The application follows an object-oriented design with the following key classes:

- **`Exercise` (Abstract Base Class):**
  - Defines the common interface for all exercise types.
  - Contains pure virtual methods for creating exercises, checking answers, and serialization (`save` and `load` methods).

- **Derived Classes:**
  - **`MCExercise`:** Implements multiple-choice exercises.
  - **`TMCExercise`:** Extends `MCExercise` by adding a time limit feature.
  - **`TFExercise`:** Implements true/false exercises.
  - **`FBExercise`:** Implements fill-in-the-blank exercises.

- **`User` Class:**
  - Stores user information, progress, and achievements.

- **`Achievement` Class:**
  - Represents individual achievements that can be unlocked.

- **`DataManager` Class:** (Coming soon!)
  - Handles saving and loading of application data to and from a file.
  
- **`main.cpp`:**
  - Contains the main loop and user interface logic.
  - Interacts with the user and coordinates the application flow.



