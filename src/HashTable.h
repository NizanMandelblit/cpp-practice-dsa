#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <vector>
#include <stdexcept>

class HashTable {
public:
    // Constructor to initialize the hash table with a specified capacity
    HashTable(int capacity = 100);

    // Destructor to clean up memory
    ~HashTable();

    // Insert a key-value pair into the hash table
    // Update value if key exists
    void insert(int key, int value);

    // Remove a key-value pair from the hash table
    // Returns true if the key was found and removed, false otherwise
    bool remove(int key);

    // Retrieve the value associated with a key
    // Throws an exception if the key is not found
    int get(int key) const;

    // Check if a key exists in the hash table
    bool contains(int key) const;

    // Get the current capacity of the hash table
    int getCapacity() const;

private:
    // Node structure for linked list chaining
    struct HashNode {
        int key;
        int value;
        HashNode* next;  // Pointer to the next node in the chain

        HashNode(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    // Hash function to map keys to indices
    int hash(int key) const;

    // Array of pointers to HashNode (each entry in the array is a bucket)
    std::vector<HashNode*> table;

    // Current capacity of the hash table
    int capacity;

};

#endif // HASHTABLE_H
