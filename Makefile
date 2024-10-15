# Makefile for SkillMaster Project

# Compiler
CXX = g++
CXXFLAGS = -std=c++11 

# Source Files
SRCS = main.cpp User.cpp Achievement.cpp Exercise.cpp MCExercise.cpp TMCExercise.cpp TFExercise.cpp FBExercise.cpp 

# GCH Files
GCHS = User.h.gch Achievement.h.gch Exercise.h.gch MCExercise.h.gch TMCExercise.h.gch TFExercise.h.gch FBExercise.h.gch 


# Header Files
HEADERS = User.h Achievement.h Exercise.h MCExercise.h TMCExercise.h TFExercise.h FBExercise.h 

# Object Files
OBJS = $(SRCS:.cpp=.o)

# Executable Name
EXEC = ExerciseAsisst

# Default Target
all: $(EXEC)

# Build the main executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Build object files
%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up object files and executables
clean:
	rm -f $(OBJS) $(EXEC) $(TEST_OBJS) $(TEST_EXEC) $(GCHS)

# Phony targets
.PHONY: all clean
