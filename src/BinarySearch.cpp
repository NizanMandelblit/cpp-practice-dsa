#include "BinarySearch.h"

// Constructor to initialize the search object with a sorted array
BinarySearch::BinarySearch(const std::vector<int> &input): nums(input) {
    // or nums.assign(input.begin(), input.end());
}

// Destructor
BinarySearch::~BinarySearch() {}

// Sets or updates the array to search in
void
BinarySearch::setArray(const std::vector<int> &input) {
    nums.assign(input.begin(), input.end());
}

int
BinarySearch::binary_search(int target, int left, int right) const {
    if (left > right)
        return -1;

    int middle = left + (right - left) / 2;
    if (nums[middle] == target)
        return middle;

    if (nums[middle] > target)
        return binary_search(target, left, middle - 1);
    else
        return binary_search(target, middle + 1, right);
}

// Performs binary search on the array for the given target
// Returns the index of the target if found, or -1 if not found
// O(log n)
int
BinarySearch::search(int target) const {
    return binary_search(target, 0, nums.size() - 1);
}

// Checks if a target exists in the array (returns true if found, false otherwise)
// in O(n) linear search
bool
BinarySearch::contains(int target) const {
    for (auto &&num : nums)
        if (num == target)
            return true;
    return false;
}

// Returns the current array
std::vector<int>
BinarySearch::getArray() const {
    return nums;
}
