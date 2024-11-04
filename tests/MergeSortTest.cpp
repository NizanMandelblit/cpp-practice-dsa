#include "gtest/gtest.h"
#include "../src/MergeSort.h"

// Test sorting an already sorted array
TEST(MergeSortTest, SortedArray) {
    vector<int> arr = {1, 2, 3, 4, 5};
    mergeSort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, (vector<int>{1, 2, 3, 4, 5}));
}

// Test sorting a reverse-sorted array
TEST(MergeSortTest, ReverseSortedArray) {
    vector<int> arr = {5, 4, 3, 2, 1};
    mergeSort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, (vector<int>{1, 2, 3, 4, 5}));
}

// Test sorting an array with random elements
TEST(MergeSortTest, UnsortedArray) {
    vector<int> arr = {3, 5, 1, 4, 2};
    mergeSort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, (vector<int>{1, 2, 3, 4, 5}));
}

// Test sorting an array with duplicate elements
TEST(MergeSortTest, ArrayWithDuplicates) {
    vector<int> arr = {4, 1, 3, 2, 2, 1};
    mergeSort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, (vector<int>{1, 1, 2, 2, 3, 4}));
}

// Test sorting an array with a single element
TEST(MergeSortTest, SingleElementArray) {
    vector<int> arr = {1};
    mergeSort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, (vector<int>{1}));
}

// Test sorting an empty array
TEST(MergeSortTest, EmptyArray) {
    vector<int> arr = {};
    mergeSort(arr, 0, arr.size() - 1);
    EXPECT_EQ(arr, (vector<int>{}));
}

// Test sorting a large array
TEST(MergeSortTest, LargeArray) {
    vector<int> arr;
    for (int i = 10000; i > 0; --i) {
        arr.push_back(i);
    }
    mergeSort(arr, 0, arr.size() - 1);
    for (int i = 0; i < 10000; ++i) {
        EXPECT_EQ(arr[i], i + 1);
    }
}
