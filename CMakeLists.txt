cmake_minimum_required(VERSION 3.12)  # Compatible with most systems
project(BlackjackTrainer)             # Project name

# Set C++ standard (SFML needs at least C++11)
set(CMAKE_CXX_STANDARD 17)

# Find SFML (must be installed on the system)
find_package(SFML REQUIRED COMPONENTS graphics window system)

# Add executable (main.cpp -> blackjack-trainer)
add_executable(blackjack-trainer main.cpp)

# Link SFML libraries
target_link_libraries(blackjack-trainer PRIVATE 
    sfml-graphics 
    sfml-window 
    sfml-system
)