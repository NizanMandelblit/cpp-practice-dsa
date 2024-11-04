#ifndef BINARYSEARCH_H
#define BINARYSEARCH_H

#include <vector>

class BinarySearch {
  private:
    std::vector<int> nums;

  public:
    // Constructor to initialize the search object with a sorted array
    BinarySearch(const std::vector<int> &input);

    // Destructor
    ~BinarySearch();

    // Sets or updates the array to search in
    void setArray(const std::vector<int> &input);
    int binary_search(int target, int left, int right) const;
    // Performs binary search on the array for the given target
    // Returns the index of the target if found, or -1 if not found
    int search(int target) const;

    // Checks if a target exists in the array (returns true if found, false otherwise)
    bool contains(int target) const;

    // Returns the current array
    std::vector<int> getArray() const;
};

#endif
