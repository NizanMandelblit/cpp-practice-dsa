#include "Heap.h"
Heap::Heap() {}

Heap::~Heap() {}

void
Heap::heapifyUp(int index) {
    while (index) {
        // Parent: At index (i−1)/2
        int parent_value = data[(index - 1) / 2];
        // if child is less then it's parent heapify up
        if (data[index] < parent_value) {
            std::swap(data[index], data[(index - 1) / 2]);
            index = (index - 1) / 2;
        } else {
            break;
        }
    }
}

void
Heap::heapifyDown(int index) {
    int size = data.size();
    while (index < size) {
        // Child left :  2i+1, Child right: 2i+2
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int smallestIndex = index;

        // Check if the left child exists and is smaller than the current node
        if (leftChildIndex < size && data[leftChildIndex] < data[smallestIndex])
            smallestIndex = leftChildIndex;

        // Check if the right child exists and is smaller than the current smallest
        if (rightChildIndex < size && data[rightChildIndex] < data[smallestIndex])
            smallestIndex = rightChildIndex;

        // If the smallest element is still the current node, we're done
        if (smallestIndex == index)
            break;

        // Swap with the smaller child and move down
        std::swap(data[index], data[smallestIndex]);
        index = smallestIndex;
    }
}

// Adds an element to the heap
void
Heap::insert(int value) {
    // insert into the last node
    data.push_back(value);
    // then heapify up
    heapifyUp(data.size() - 1);
}

// Returns the minimum element in a min-heap or maximum in a max-heap
int
Heap::peek() const {
    if (isEmpty())
        throw std::out_of_range("Heap is empty");
    return data[0];
}

// Removes and returns the minimum element in a min-heap or maximum in a max-heap
int
Heap::extract() {
    if (isEmpty())
        throw std::out_of_range("Heap is empty");

    int min = data.at(0);
    std::swap(data.front(), data.back());
    data.pop_back();
    // heapify down
    heapifyDown(0);
    return min;
}

// Returns true if the heap is empty
bool
Heap::isEmpty() const {
    return data.empty();
}

// Returns the size of the heap
int
Heap::size() const {
    return data.size();
}
