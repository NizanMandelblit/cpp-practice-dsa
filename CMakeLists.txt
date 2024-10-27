cmake_minimum_required(VERSION 3.10)
project(DSA_Practice)

# Enable C++11 standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_BUILD_TYPE Debug)

# Add Google Test
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.11.0.zip
)
FetchContent_MakeAvailable(googletest)

enable_testing()

# Add main DSA file and test files
add_executable(DSA_Tests tests/test_dsa.cpp src/LinkedList.cpp src/Stack.cpp)

# Link Google Test with DSA_Tests
target_link_libraries(DSA_Tests gtest_main)
add_test(NAME DSA_Tests COMMAND DSA_Tests)

