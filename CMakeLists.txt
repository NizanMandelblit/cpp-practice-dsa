cmake_minimum_required(VERSION 3.10)
project(DSA_Practice)

# Enable C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

#include the CTest CMake module
include (CTest)


# Add Google Test using FetchContent
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add LinkedListTest executable and link GoogleTest libraries
add_executable(LinkedListTest tests/LinkedListTest.cpp src/LinkedList.cpp)
target_link_libraries(LinkedListTest gtest gtest_main)

# Add StackTest executable and link GoogleTest libraries
add_executable(StackTest tests/StackTest.cpp src/Stack.cpp)
target_link_libraries(StackTest gtest gtest_main)

# Register the tests with CTest
add_test(NAME LinkedListTest COMMAND LinkedListTest)
add_test(NAME StackTest COMMAND StackTest)
