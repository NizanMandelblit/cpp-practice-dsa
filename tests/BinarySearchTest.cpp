#include "../src/BinarySearch.h"
#include "gtest/gtest.h"
#include <chrono>

// Test initializing BinarySearch with a sorted array and searching for an existing element
TEST(BinarySearchTest, SearchExistingElement) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    BinarySearch search(arr);
    EXPECT_EQ(search.search(3), 2); // 3 is at index 2
}

// Test searching for a non-existing element
TEST(BinarySearchTest, SearchNonExistingElement) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    BinarySearch search(arr);
    EXPECT_EQ(search.search(6), -1); // 6 is not in the array
}

// Test updating the array with setArray and searching again
TEST(BinarySearchTest, SetArrayAndSearch) {
    BinarySearch search({ 1, 2, 3 });
    search.setArray({ 10, 20, 30, 40 });
    EXPECT_EQ(search.search(30), 2); // 30 is at index 2
}

// Test contains for an existing element
TEST(BinarySearchTest, ContainsExistingElement) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    BinarySearch search(arr);
    EXPECT_TRUE(search.contains(4)); // 4 exists in the array
}

// Test contains for a non-existing element
TEST(BinarySearchTest, ContainsNonExistingElement) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    BinarySearch search(arr);
    EXPECT_FALSE(search.contains(6)); // 6 does not exist in the array
}

// Test getArray to retrieve the stored array
TEST(BinarySearchTest, GetArray) {
    std::vector<int> arr = { 1, 2, 3, 4, 5 };
    BinarySearch search(arr);
    EXPECT_EQ(search.getArray(), arr); // Check if getArray returns the correct vector
}

// Test searching in an empty array
TEST(BinarySearchTest, SearchInEmptyArray) {
    BinarySearch search({});
    EXPECT_EQ(search.search(1), -1); // Searching in an empty array should return -1
}

// Test contains on an empty array
TEST(BinarySearchTest, ContainsInEmptyArray) {
    BinarySearch search({});
    EXPECT_FALSE(search.contains(1)); // Empty array should not contain any element
}

// Test searching in a large array
TEST(BinarySearchTest, SearchInLargeArray) {
    std::vector<int> largeArray;
    for (int i = 1; i <= 1000; ++i)
        largeArray.push_back(i); // Sorted array from 1 to 1000
    BinarySearch search(largeArray);
    EXPECT_EQ(search.search(500), 499); // 500 should be at index 499
    EXPECT_EQ(search.search(1001), -1); // 1001 does not exist in the array
}

TEST(BinarySearchTest, SearchPerformance) {
    // Create a large sorted array
    std::vector<int> largeArray;
    int size = 1000000; // 1 million elements
    for (int i = 1; i <= size; ++i)
        largeArray.push_back(i);
    BinarySearch search(largeArray);

    // Measure the time for searching an element in the middle
    auto start = std::chrono::high_resolution_clock::now();
    search.search(size / 2);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // Double the size and repeat
    size *= 2;
    largeArray.clear();
    for (int i = 1; i <= size; ++i)
        largeArray.push_back(i);
    search.setArray(largeArray);

    start = std::chrono::high_resolution_clock::now();
    search.search(size / 2);
    end = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start).count();

    // We expect the second duration to be close to the first because log(n) grows slowly
    EXPECT_NEAR(duration2, duration1, duration1 * 1.5);
}
