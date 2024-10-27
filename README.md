### Create a build directory
```
mkdir -p build
cd build
```

### Run CMake from the build directory, specifying the parent directory as the source
```
cmake ..
```

### Build the project
```
cmake --build .
```

### Run all tests
```
ctest --output-on-failure --verbose
```
with valgrind check 
```
ctest -T memcheck --output-on-failure --overwrite MemoryCheckCommandOptions="--leak-check=full --error-exitcode=1" --verbose
```

Plan is to implement and test the following : 

Data structers :
1. Linked List
2. Stack
3. Queue
4. HashTable
5. Binary Search Tree
6. Heap
7. Graphs

Algorithms :
1. Breadth-First Search (Graphs)
2. Depth-First Search (Graphs)
3. Binary Search
4. Merge Sort
5. Quick Sort

