# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -w
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Target executable
TARGET = blackjack-trainer

# Source files
SRCS = main.cpp

# Default build rule
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) $(SRCS) -o $(TARGET) $(LDFLAGS)

# Clean compiled files
clean:
	rm -f $(TARGET)

# Run the program
run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run