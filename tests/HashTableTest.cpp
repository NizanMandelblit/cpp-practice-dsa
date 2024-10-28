#include <gtest/gtest.h>
#include "../src/HashTable.h"

// Test inserting and retrieving elements
TEST(HashTableTest, InsertAndGet) {
    HashTable hashTable(10);

    // Insert a few key-value pairs
    hashTable.insert(1, 100);
    hashTable.insert(2, 200);
    hashTable.insert(3, 300);

    // Retrieve and check values
    EXPECT_EQ(hashTable.get(1), 100);
    EXPECT_EQ(hashTable.get(2), 200);
    EXPECT_EQ(hashTable.get(3), 300);
}

// Test updating value if the key exists
TEST(HashTableTest, UpdateExistingKey) {
    HashTable hashTable(10);

    // Insert and then update the value of an existing key
    hashTable.insert(1, 100);
    hashTable.insert(1, 500);  // Update value for key 1

    // Check if value has been updated
    EXPECT_EQ(hashTable.get(1), 500);
}

// Test removing a key
TEST(HashTableTest, RemoveKey) {
    HashTable hashTable(10);

    // Insert and remove a key
    hashTable.insert(1, 100);
    EXPECT_TRUE(hashTable.remove(1));
    EXPECT_FALSE(hashTable.contains(1));  // Confirm removal

    // Attempt to remove a non-existing key
    EXPECT_FALSE(hashTable.remove(2));
}

// Test contains method
TEST(HashTableTest, ContainsKey) {
    HashTable hashTable(10);

    // Insert key-value pairs
    hashTable.insert(1, 100);
    hashTable.insert(2, 200);

    // Check if keys exist
    EXPECT_TRUE(hashTable.contains(1));
    EXPECT_TRUE(hashTable.contains(2));
    EXPECT_FALSE(hashTable.contains(3));  // Key that doesn't exist
}

// Test throwing an exception when retrieving a non-existing key
TEST(HashTableTest, GetNonExistentKeyThrowsException) {
    HashTable hashTable(10);

    // Attempt to retrieve a key that wasn't inserted
    EXPECT_THROW(hashTable.get(5), std::runtime_error);
}

// Test handling collisions
TEST(HashTableTest, HandleCollisions) {
    HashTable hashTable(5);  // Small capacity to force collisions

    // Insert multiple keys that will collide
    hashTable.insert(1, 100);
    hashTable.insert(6, 200);  // 6 % 5 == 1 % 5, so it should collide with key 1

    // Both values should be retrievable despite the collision
    EXPECT_EQ(hashTable.get(1), 100);
    EXPECT_EQ(hashTable.get(6), 200);
}

// Test resizing hash table
TEST(HashTableTest, ResizeTable) {
    HashTable hashTable(2);  // Start with a small capacity

    // Insert multiple elements to trigger resizing
    hashTable.insert(1, 100);
    hashTable.insert(2, 200);
    hashTable.insert(3, 300);  // Should resize at this point

    // Check that elements are still accessible after resizing
    EXPECT_EQ(hashTable.get(1), 100);
    EXPECT_EQ(hashTable.get(2), 200);
    EXPECT_EQ(hashTable.get(3), 300);
}

// Test inserting a large sequence of elements
TEST(HashTableTest, InsertManyElements) {
    HashTable hashTable(100);

    // Insert a large number of elements
    for (int i = 0; i < 1000; ++i) {
        hashTable.insert(i, i * 10);
    }

    // Verify that each element is retrievable
    for (int i = 0; i < 1000; ++i) {
        EXPECT_EQ(hashTable.get(i), i * 10);
    }
}

// Test current capacity
TEST(HashTableTest, CapacityCheck) {
    HashTable hashTable(50);  // Initialize with capacity of 50
    EXPECT_EQ(hashTable.getCapacity(), 50);

    // Insert elements and resize if necessary
    for (int i = 0; i < 100; ++i) {
        hashTable.insert(i, i * 10);
    }
    EXPECT_GE(hashTable.getCapacity(), 50);  // Capacity should be >= initial capacity
}
