#include "HashTable.h"

// Constructor to initialize the hash table with a specified capacity
HashTable::HashTable(int capacity) {
    this->capacity = capacity;
    table = std::vector<HashTable::HashNode *>{ static_cast<size_t>(capacity) };
}

// Destructor to clean up memory
HashTable::~HashTable() {
    for (size_t i = 0; i < capacity; i++) {
        HashNode *ptr = table[i];
        HashNode *ptrNext = nullptr;
        while (ptr) {
            ptrNext = ptr->next;
            delete ptr;
            ptr = ptrNext;
        }
    }
}

// Insert a key-value pair into the hash table
// Update value if key exists
void
HashTable::insert(int key, int value) {
    HashNode *hash_node = (contains(key) ? nullptr : new HashNode(key, value));
    HashNode *ptr = table[hash(key)];
    if (!ptr)
        table[hash(key)] = hash_node;
    else if (contains(key)) {
        while (ptr->key != key)
            ptr = ptr->next;
        ptr->value = value;
    } else {
        HashNode *prev = nullptr;
        while (ptr) {
            prev = ptr;
            ptr = ptr->next;
        }
        ptr = hash_node;
        prev->next = ptr;
    }
}

// Remove a key-value pair from the hash table
// Returns true if the key was found and removed, false otherwise
bool
HashTable::remove(int key) {
    if (!contains(key))
        return false;

    HashNode *ptr = table[hash(key)];
    HashNode *prev = nullptr;
    while (ptr && ptr->key != key) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (prev)
        prev->next = ptr->next;

    delete ptr;
    table[hash(key)] = nullptr;
    return true;
}

// Retrieve the value associated with a key
// Throws an exception if the key is not found
int
HashTable::get(int key) const {
    HashNode *ptr = table[hash(key)];
    while (ptr && ptr->key != key)
        ptr = ptr->next;

    if (!ptr)
        throw std::runtime_error("key doesn't exist");

    return (ptr->value);
}

// Check if a key exists in the hash table
bool
HashTable::contains(int key) const {
    HashNode *ptr = table[hash(key)];
    while (ptr && ptr->key != key)
        ptr = ptr->next;

    return !(ptr == nullptr);
}

// Get the current capacity of the hash table
int
HashTable::getCapacity() const {
    return this->capacity;
}

// Hash function to map keys to indices
int
HashTable::hash(int key) const {
    return (key % capacity);
}
