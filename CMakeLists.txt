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

# Add BinarySearchTreeTest executable and link GoogleTest libraries
add_executable(BinarySearchTreeTest tests/BinarySearchTreeTest.cpp src/BinarySearchTree.cpp)
target_link_libraries(BinarySearchTreeTest gtest gtest_main)

# Add HashTableTest executable and link GoogleTest libraries
add_executable(HashTableTest tests/HashTableTest.cpp src/HashTable.cpp)
target_link_libraries(HashTableTest gtest gtest_main)

# Add HeapTest executable and link GoogleTest libraries
add_executable(HeapTest tests/HeapTest.cpp src/Heap.cpp)
target_link_libraries(HeapTest gtest gtest_main)

# Add GraphTest executable and link GoogleTest libraries
add_executable(GraphTest tests/GraphTest.cpp src/Graph.cpp)
target_link_libraries(GraphTest gtest gtest_main)

# MergeSortTest
add_executable(MergeSortTest tests/MergeSortTest.cpp src/MergeSort.cpp)
target_link_libraries(MergeSortTest gtest gtest_main)

# BinarySearchTest
add_executable(BinarySearchTest tests/BinarySearchTest.cpp src/BinarySearch.cpp)
target_link_libraries(BinarySearchTest gtest gtest_main)


# Register the tests with CTest
add_test(NAME LinkedListTest COMMAND LinkedListTest)
add_test(NAME StackTest COMMAND StackTest)
add_test(NAME BinarySearchTreeTest COMMAND BinarySearchTreeTest)
add_test(NAME HashTableTest COMMAND HashTableTest)
add_test(NAME HeapTest COMMAND HeapTest)
add_test(NAME GraphTest COMMAND GraphTest)
add_test(NAME MergeSortTest COMMAND MergeSortTest)
add_test(NAME BinarySearchTest COMMAND BinarySearchTest)

