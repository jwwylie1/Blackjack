cmake_minimum_required(VERSION 3.15)  
project(Blackjack)  

# 1. Set C++ standard (SFML requires C++11 or later)  
set(CMAKE_CXX_STANDARD 17)  

# 2. Include SFML from the 'extern' folder  
add_subdirectory(extern/SFML)  

# 3. Add your executable  
add_executable(Blackjack src/main.cpp)  # Adjust if you have multiple .cpp files  

# 4. Link SFML libraries  
target_link_libraries(Blackjack PRIVATE 
    sfml-graphics 
    sfml-window 
    sfml-system 
    sfml-audio       # Only if you use audio
)  

# (Optional) Copy SFML DLLs to build folder (Windows only)  
if(WIN32)
    file(COPY ${CMAKE_SOURCE_DIR}/extern/SFML/bin/ 
         DESTINATION ${CMAKE_BINARY_DIR}/Debug/)
endif()