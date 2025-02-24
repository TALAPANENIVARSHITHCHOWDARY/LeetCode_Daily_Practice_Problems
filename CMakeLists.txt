cmake_minimum_required(VERSION 3.12)
project(LeetCode_Solutions)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing
enable_testing()

# Add all subdirectories that contain solutions
add_subdirectory(2467_Most_Profitable_Path_in_a_Tree)
# Add other problem directories as needed 