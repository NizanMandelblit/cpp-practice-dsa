#ifndef HEAP_H
#define HEAP_H

#include <stdexcept>
#include <vector>

class Heap {
  private:
    /*
     *Heaps are commonly represented using a vector (or array) rather than a binary tree. This is
     *because:
     *
     * 1. Index-Based Relationships: In a complete binary tree (which a heap always is), each node's
     *position can be easily determined and accessed using indices in a vector.
     *
     *    For a node at index i:
     *    Left Child: At index 2i+1
     *    Right Child: At index  2i+2
     *    Parent: At index (i−1)/2 (for i>0)
     *
     *2. Space Efficiency: A vector (or array) is more memory-efficient for a complete binary tree
     *because it avoids storing explicit pointers for each node, as would be needed in a tree
     *structure.
     *
     *3.Efficient Access and Manipulation: Using a vector allows for efficient access, insertion,
     *and deletion operations, which are required to maintain the heap properties through operations
     *like heapify, insert, and extract.
     *
     *  Index:   0  1  2  3  4  5
     *  Array:  [1, 3, 6, 5, 9, 8]
     * 
     *    */
    std::vector<int> data;

    void heapifyUp(int index);
    void heapifyDown(int index);

  public:
    Heap();
    ~Heap();

    // Adds an element to the heap
    void insert(int value);

    // Returns the minimum element in a min-heap or maximum in a max-heap
    int peek() const;

    // Removes and returns the minimum element in a min-heap or maximum in a max-heap
    int extract();

    // Returns true if the heap is empty
    bool isEmpty() const;

    // Returns the size of the heap
    int size() const;
};

#endif // HEAP_H
