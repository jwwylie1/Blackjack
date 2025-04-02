# Detect OS
ifeq ($(OS),Windows_NT)
    TARGET = blackjack-trainer.exe
    SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
    CLEAN_CMD = del /f $(TARGET)
else
    TARGET = blackjack-trainer
    SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
    CLEAN_CMD = rm -f $(TARGET)
endif

# Compiler settings
CXX = g++
CXXFLAGS = -std=c++17 -w
LDFLAGS = $(SFML_LIBS)

# Build rules
all: $(TARGET)

$(TARGET): main.cpp
	$(CXX) $(CXXFLAGS) main.cpp -o $(TARGET) $(LDFLAGS)

run: $(TARGET)
	./$(TARGET)

clean:
	$(CLEAN_CMD)

.PHONY: all clean run