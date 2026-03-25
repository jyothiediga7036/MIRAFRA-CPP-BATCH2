# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Target executable
TARGET = network

# Source files
SRC = main.cpp Network.cpp Router.cpp RouterFactory.cpp

# Object files
OBJ = $(SRC:.cpp=.o)

# Default rule
all: $(TARGET)

# Linking
$(TARGET): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)

# Compilation rule
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Run program
run: $(TARGET)
	./$(TARGET)

# Clean build files
clean:
	rm -f $(OBJ) $(TARGET)

.PHONY: all clean run
