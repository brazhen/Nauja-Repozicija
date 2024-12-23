cmake_minimum_required(VERSION 3.14)
project(v2.0)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(${CMAKE_SOURCE_DIR})

# Add Google Test as a subdirectory
add_subdirectory(googletest)

# Add your main application executable
add_executable(main_app main.cpp Stud.cpp)

# Add your test executable
add_executable(unit_tests test_main.cpp Stud.cpp)

# Link Google Test libraries to the test executable
target_link_libraries(unit_tests gtest gtest_main)





