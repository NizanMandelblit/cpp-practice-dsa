#include <iostream>
#include <vector>


#include "MergeSort.h"

/**
 * @brief Merges two sorted subarrays of `arr` into a single sorted subarray.
 * 
 * This function takes two adjacent sorted subarrays within the main array `arr`
 * and merges them into a single sorted subarray, which is placed back into `arr`.
 * The two subarrays are:
 *   - The first subarray: `arr[l]` to `arr[middle]`
 *   - The second subarray: `arr[middle + 1]` to `arr[right]`
 *
 * @param arr Reference to the vector of integers to be sorted.
 * @param l Left index of the first subarray.
 * @param middle Middle index that separates the two subarrays.
 * @param right Right index of the second subarray.
 */
static void merge(vector<int> &arr, int l, int middle, int right) {
    // Calculate the sizes of the two subarrays
    int array1_size = middle - l + 1;
    int array2_size = right - middle;

    // Create temporary vectors to hold the elements of each subarray
    vector<int> array1(array1_size);
    vector<int> array2(array2_size);

    // Copy data into temporary arrays `array1` and `array2`
    for (int i = 0; i < array1_size; i++)
        array1[i] = arr[l + i];
    for (int i = 0; i < array2_size; i++)
        array2[i] = arr[middle + i + 1];

    // Merge the two temporary arrays back into `arr`
    int i = 0, j = 0, k = l; // `i`, `j`, and `k` are indexes for `array1`, `array2`, and `arr`, respectively

    // Compare elements from `array1` and `array2` and place the smaller one into `arr`
    while (i < array1_size && j < array2_size) {
        if (array1[i] <= array2[j]) {
            arr[k] = array1[i];
            i++;
        } else {
            arr[k] = array2[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements from `array1`, if any
    while (i < array1_size) {
        arr[k] = array1[i];
        i++;
        k++;
    }

    // Copy any remaining elements from `array2`, if any
    while (j < array2_size) {
        arr[k] = array2[j];
        j++;
        k++;
    }
}

/**
 * @brief Recursively sorts the array `arr` using the Merge Sort algorithm.
 * 
 * This function sorts the array by recursively dividing it into smaller subarrays
 * and then merging those sorted subarrays back together. The `mergeSort` function
 * splits the array in half, recursively sorts each half, and then merges the two sorted halves.
 *
 * @param arr Reference to the vector of integers to be sorted.
 * @param l Left index of the subarray to be sorted.
 * @param r Right index of the subarray to be sorted.
 */
void mergeSort(vector<int> &arr, int l, int r) {
    // Base case: if the array has one or zero elements, it is already sorted
    if (l >= r)
        return;

    // Calculate the middle point to split the array
    int middle = l + (r - l) / 2;

    // Recursively sort the left half of the array
    mergeSort(arr, l, middle);

    // Recursively sort the right half of the array
    mergeSort(arr, middle + 1, r);

    // Merge the two sorted halves
    merge(arr, l, middle, r);
}


// Helper function to print the array
void
printArray(const vector<int> &arr) {
    for (int i : arr)
        cout << i << " ";
    cout << endl;
}
